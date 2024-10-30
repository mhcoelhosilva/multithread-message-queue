#include <vector>
#include <thread>
#include <memory>

#include "message.hpp"
#include "basemmq.hpp"

using namespace std;

class NaiveMultithreadMessageQueue : public BaseMultithreadMessageQueue {

    vector<thread> m_threads;

public:

    virtual void Start(int numThreads = 8) override {}
    virtual void AddMessage(shared_ptr<Message> message) override;
    virtual bool IsDoneProcessing() override { return true; }
    virtual void Shutdown() override;

    static void WorkerFunction(shared_ptr<Message> message);

};