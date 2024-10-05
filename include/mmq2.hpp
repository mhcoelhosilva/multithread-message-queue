#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <chrono>

#include "message.hpp"
#include "lock_free_queue.hpp"

using namespace std;

class MultithreadMessageQueue2 {

    vector<thread> m_threads;
    LockFreeQueue<Message> m_queue;
    atomic<bool> m_stop = true;

public:

    void Start(int numThreads = 8);
    void AddMessageAsync(shared_ptr<Message> message);
    bool IsDoneProcessing();
    void Shutdown();

    static void WorkerFunction(uint64_t index, MultithreadMessageQueue2* p);

};