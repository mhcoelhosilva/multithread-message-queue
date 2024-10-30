#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <queue>
#include <chrono>

#include "message.hpp"
#include "basemmq.hpp"

using namespace std;

class MultithreadMessageQueue : public BaseMultithreadMessageQueue {

    vector<thread> m_threads;
    atomic<uint64_t> m_threadBusy = 0;
    vector<shared_ptr<Message>> m_messages;
    atomic<bool> m_stop = true;

public:

    virtual void Start(int numThreads = 8) override;
    virtual void AddMessage(shared_ptr<Message> message) override;
    virtual bool IsDoneProcessing() override;
    virtual void Shutdown() override;

    static void WorkerFunction(uint64_t index, MultithreadMessageQueue* p);

};