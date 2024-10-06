#include <vector>
#include <thread>
#include <memory>

#include "message.hpp"

using namespace std;

class NaiveMultithreadMessageQueue {

    vector<thread> m_threads;

public:

    void AddMessageAsync(shared_ptr<Message> message);
    void Shutdown();

    static void WorkerFunction(shared_ptr<Message> message);

};