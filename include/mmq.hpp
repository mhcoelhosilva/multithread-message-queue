#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <queue>
#include <chrono>

#include "message.hpp"

using namespace std;

class MultithreadMessageQueue {

    vector<thread> m_threads;
    atomic<uint64_t> m_threadBusy = 0;
    vector<shared_ptr<Message>> m_messages;
    atomic<bool> m_stop = true;

public:

    void Start(int numThreads = 8);
    void AddMessage(shared_ptr<Message> message);
    bool IsDoneProcessing();
    void Shutdown();

    static void WorkerFunction(uint64_t index, MultithreadMessageQueue* p);

};