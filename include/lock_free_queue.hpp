#include <memory>

template <class T>
struct AtomicNode {
    std::atomic<AtomicNode*> next = nullptr;
    [[no_unique_address]] std::shared_ptr<T> payload;
};

/**
 * Queue allowing atomic pushing and popping of atomic nodes
 *
 * @tparam T
 */
template <class T>
class LockFreeQueue {
    std::atomic<AtomicNode<T>*> head = nullptr;
    std::atomic<std::atomic<AtomicNode<T>*>*> tail = &head;
    using HeadType = AtomicNode<T>*;
    using TailType = std::atomic<HeadType>*;

   public:
    using Node = AtomicNode<T>;

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
    void push(std::shared_ptr<T> data) {
        Node* n = new Node();
        n->payload = data;
        std::atomic<Node*>* current = tail.exchange(&n->next);
        current->store(n);
    }

    bool empty() {
        return head.load() == nullptr;
    }

    // Atomically pop a node from the queue. Returns nullptr if the queue is
    // empty
    std::shared_ptr<T> pop() {
        // No point in trying to pop from an empty queue, fail fast
        Node* currentHead = head.load();
        if (currentHead == nullptr) {
            return nullptr;
        }

        std::atomic<Node*>* nextHeadPtr = nullptr;

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

        std::shared_ptr<T> payload = currentHead->payload;
        delete currentHead;
        return payload;
    }
};