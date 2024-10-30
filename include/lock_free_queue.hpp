#include <memory>

using namespace std;

template <class T>
struct AtomicNode {
    atomic<AtomicNode*> next = nullptr;
    [[no_unique_address]] shared_ptr<T> payload;
};

/**
 * Queue allowing atomic pushing and popping of atomic nodes
 *
 * @tparam T
 */
template <class T>
class LockFreeQueue {
    using Node = AtomicNode<T>;

    atomic<Node*> head = nullptr;
    atomic<atomic<Node*>*> tail = &head;
    using HeadType = Node*;
    using TailType = atomic<HeadType>*;

public:

    LockFreeQueue() = default;
    LockFreeQueue(LockFreeQueue const&) = delete;
    constexpr LockFreeQueue(LockFreeQueue&& other) noexcept
      : head(HeadType(other.head))
      , tail(TailType(other.tail)) {
        if (tail == &other.head) {
            tail = &head;
        }
        other.head = nullptr;
        other.tail = &other.head;
    }

    // Atomically push a node into the queue
    void push(shared_ptr<T> data) {
        Node* n = new Node();
        n->payload = data;
        if (head.load() == nullptr) {
            head.store(n);
        }
        atomic<Node*>* current = tail.exchange(&n->next); // new tail is new node's next
        current->store(n); // previous tail is new node. i.e., head->...->new_node(old tail, was empty)->new_node_next(empty, new tail)
    }

    bool empty() {
        return head.load() == nullptr;
    }

    // Atomically pop a node from the queue. Returns nullptr if the queue is
    // empty
    shared_ptr<T> pop() {
        // No point in trying to pop from an empty queue, fail fast
        Node* currentHead = head.load();
        if (currentHead == nullptr) {
            return nullptr;
        }

        atomic<Node*>* nextHeadPtr = nullptr;

        do {
             // Another thread might have just popped something off the queue
            currentHead = head.load();
            if (currentHead == nullptr) {
                return nullptr;
            }
            nextHeadPtr = &currentHead->next;
        } while (!head.compare_exchange_weak(currentHead, *nextHeadPtr));

        // If the tail is currently pointing to nextHeadPtr, reset the
        // tail to point to &head
        tail.compare_exchange_strong(nextHeadPtr, &head);

        shared_ptr<T> payload = currentHead->payload;
        delete currentHead;
        return payload;
    }
};