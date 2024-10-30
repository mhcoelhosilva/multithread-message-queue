#include "naive.hpp"

#include <iostream>
#include <fstream>

void NaiveMultithreadMessageQueue::AddMessage(shared_ptr<Message> message) {
    if (!message) {
        cerr << "Invalid message" << endl;
        return;
    }

    m_threads.push_back(thread(&NaiveMultithreadMessageQueue::WorkerFunction, message));
}

void NaiveMultithreadMessageQueue::Shutdown() {
    for (int i = 0; i < m_threads.size(); ++i) {
        m_threads[i].join();
    }
    m_threads.clear();
}

void NaiveMultithreadMessageQueue::WorkerFunction(shared_ptr<Message> message) {
    if (!message) {
        return;
    }

    ofstream file(message->m_targetFile, ios::app);
    for (int i = 0; i < PAYLOAD_SIZE; ++i) {
        file << to_string(message->m_payload[i]) << ", ";
    }
    file << endl;
    file.close();
}