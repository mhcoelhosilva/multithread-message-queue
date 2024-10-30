#pragma once

#include <memory>

#include "message.hpp"

using namespace std;

class BaseMultithreadMessageQueue {
public:

    virtual void Start(int numThreads = 8) = 0;
    virtual void AddMessage(shared_ptr<Message> message) = 0;
    virtual bool IsDoneProcessing() = 0;
    virtual void Shutdown() = 0;
};