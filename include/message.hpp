#pragma once

#include <string>

#define PAYLOAD_SIZE 20000

struct Message {
    int m_payload[PAYLOAD_SIZE];
    std::string m_targetFile;
};
