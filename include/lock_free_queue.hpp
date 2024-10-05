#include <atomic>
#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class LockFreeQueue
{
private:

    struct Node
    {
        std::shared_ptr<T> m_data;
        std::atomic<Node*> m_next;

        Node(const T& data_) :
            m_data(std::make_shared<T>(data_))
        {};

        Node(std::shared_ptr<T> data_) :
            m_data(data_)
        {};
    };

    std::atomic<Node*> m_head;
    std::atomic<Node*> m_tail;

public:
    void push(std::shared_ptr<T> data) {
        std::atomic<Node*> const newNode = new Node(data);
        Node* oldHead = m_head.load();
        Node* oldTail = m_tail.load();
        if (!oldTail || !oldHead) {
            Node* tmp = nullptr;
            while(!m_tail.compare_exchange_weak(tmp, newNode)){
                oldTail = m_tail.load();
            }
            while(!m_head.compare_exchange_weak(tmp, newNode)){
                oldHead = m_head.load();
            }
        } else {
            Node* tmp = nullptr;
            while(!oldTail->m_next.compare_exchange_weak(tmp, newNode)){
                oldTail = m_tail.load();
            }
            m_tail.compare_exchange_weak(oldTail, newNode);
        }
    }

    std::shared_ptr<T> pop() {
        Node* oldHead = m_head.load();
        while(oldHead && !m_head.compare_exchange_weak(oldHead, oldHead->m_next)){
            oldHead = m_head.load();
        }
        return oldHead ? oldHead->m_data : std::shared_ptr<T>();
    }

    bool empty() {
        Node* oldHead = m_head.load();
        return oldHead == nullptr;
    }
};