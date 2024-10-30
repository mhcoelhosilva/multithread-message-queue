#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <chrono>

#include "message.hpp"
#include "lock_free_queue.hpp"
#include "basemmq.hpp"

using namespace std;

class MultithreadMessageQueue2 : public BaseMultithreadMessageQueue {

    vector<thread> m_threads;
    LockFreeQueue<Message> m_queue;
    atomic<bool> m_stop = true;

public:

    virtual void Start(int numThreads = 8) override;
    virtual void AddMessage(shared_ptr<Message> message) override;
    virtual bool IsDoneProcessing() override;
    virtual void Shutdown() override;

    static void WorkerFunction(uint64_t index, MultithreadMessageQueue2* p);

};