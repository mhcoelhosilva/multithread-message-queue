#include "mmq.hpp"

#include <iostream>
#include <fstream>

void MultithreadMessageQueue::Start(int numThreads) {
    if (numThreads > 64) {
        cerr << "Num Threads must be a maximum of 64" << endl;
        return;
    }
    m_stop = false;
    for (int i = 0; i < numThreads; ++i) {
        m_threads.push_back(thread(&MultithreadMessageQueue::WorkerFunction, i, this));
        m_messages.push_back(nullptr);
    }
}

void MultithreadMessageQueue::AddMessage(shared_ptr<Message> message) {
    if (!message) {
        cerr << "Invalid message" << endl;
        return;
    }

    bool threadAvailable = false;
    while (!threadAvailable) {
        for (uint64_t i = 0; i < this->m_threads.size(); ++i) {
            uint64_t comp = 1ULL << i;
            if (!(this->m_threadBusy & comp)) {
                this->m_messages[i] = message;
                this->m_threadBusy |= comp;
                threadAvailable = true;
                break;
            }
        }
    };
}

bool MultithreadMessageQueue::IsDoneProcessing() {
    for (uint64_t i = 0; i < this->m_threads.size(); ++i) {
        if (this->m_threadBusy & (1ULL << i)) {
            return false;
        }
    }
    return true;
}

void MultithreadMessageQueue::Shutdown() {
    m_stop = true;
    for (int i = 0; i < m_threads.size(); ++i) {
        m_threads[i].join();
    }
    m_threads.clear();
    m_messages.clear();
}

void MultithreadMessageQueue::WorkerFunction(uint64_t index, MultithreadMessageQueue* p) {
    uint64_t comp = 1ULL << index;
    while (true) {
        if (!p) {
            cerr << "MMQ Unavailable!" << endl;
            return;
        }
        if (p->m_threadBusy & comp) {
            if (!p->m_messages[index]) {
                cerr << "Messages[" << to_string(index) << "] unavailable!" << endl;
                return;
            }

            ofstream file(p->m_messages[index]->m_targetFile, ios::app);
            for (int i = 0; i < PAYLOAD_SIZE; ++i) {
                file << to_string(p->m_messages[index]->m_payload[i]) << ", ";
            }
            file << endl;
            file.close();
            
            p->m_messages[index] = nullptr;
            p->m_threadBusy &= ~comp;
        }
        if (p->m_stop) {
            return;
        }
    }
}