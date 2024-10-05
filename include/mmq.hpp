#include <vector>
#include <thread>
#include <atomic>
#include <memory>
#include <queue>
#include <mutex>
#include <chrono>

#define PAYLOAD_SIZE 20000

using namespace std;

struct Message {
    int m_payload[PAYLOAD_SIZE];
    string m_targetFile;
};

// Similar to log_queue and requests but now we wanna use multiple threads simultaneously
// to process longer messages
class MultithreadMessageQueue {

    vector<thread> m_threads;
    atomic<uint64_t> m_threadBusy = 0;
    vector<shared_ptr<Message>> m_messages;
    atomic<bool> m_stop = true;

public:

    void Start(int numThreads = 64);
    void AddMessage(shared_ptr<Message> message);
    bool IsDoneProcessing();
    void Shutdown();

    static void WorkerFunction(uint64_t index, MultithreadMessageQueue* p);

};