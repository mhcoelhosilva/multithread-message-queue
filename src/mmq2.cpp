#include "mmq2.hpp"

#include <iostream>
#include <fstream>

void MultithreadMessageQueue2::Start(int numThreads) {
    m_stop = false;
    for (int i = 0; i < numThreads; ++i) {
        m_threads.push_back(thread(&MultithreadMessageQueue2::WorkerFunction, i, this));
    }
}

void MultithreadMessageQueue2::AddMessageAsync(shared_ptr<Message> message) {
    if (!message) {
        cerr << "Invalid message" << endl;
        return;
    }

    m_queue.push(message);
}

bool MultithreadMessageQueue2::IsDoneProcessing() {
    return m_queue.empty();
}

void MultithreadMessageQueue2::Shutdown() {
    m_stop = true;
    for (int i = 0; i < m_threads.size(); ++i) {
        m_threads[i].join();
    }
}

void MultithreadMessageQueue2::WorkerFunction(uint64_t index, MultithreadMessageQueue2* p) {
    while (true) {
        if (!p->m_queue.empty()) {
            shared_ptr<Message> message = p->m_queue.pop();
            if (!message) {
                continue;
            }

            ofstream file(message->m_targetFile, ios::app);
            for (int i = 0; i < PAYLOAD_SIZE; ++i) {
                file << to_string(message->m_payload[i]) << ", ";
            }
            file << endl;
            file.close();
        }
        if (p->m_stop) {
            return;
        }
    }
}