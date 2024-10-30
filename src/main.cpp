// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "basemmq.hpp"
#include "mmq.hpp"
#include "mmq2.hpp"
#include "naive.hpp"

#include <iostream>
#include <chrono>
#include <memory>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

void prepareDataDirs() {
    try{
        string dir_path = "../../data/dumps";
        fs::create_directory(dir_path);
        for (auto& path: fs::directory_iterator(dir_path)) {
            fs::remove_all(path);
        }
    } catch(const std::exception& e) {
        cerr << e.what() << '\n';
    }
}

void runExperiment(BaseMultithreadMessageQueue* mmq, json& j, const char* resultsString, const vector<shared_ptr<Message>>& messages, int maxThreads) {
    prepareDataDirs();
    j[resultsString] = json::array();

    if (maxThreads > 1) {
        for (int numThreads = 1; numThreads <= maxThreads; ++numThreads) {
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();

            mmq->Start(numThreads);
            for (int i = 0; i < messages.size(); ++i) {
                mmq->AddMessage(messages[i]);
            }
            while (!mmq->IsDoneProcessing()) {
                this_thread::yield();
            }
            mmq->Shutdown();

            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            chrono::duration<float> duration = end - begin;

            json jj;
            jj["num_threads"] = numThreads;
            jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();

            j[resultsString].push_back(jj);
        }
    } else {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        mmq->Start(1);
        for (int i = 0; i < messages.size(); ++i) {
            mmq->AddMessage(messages[i]);
        }
        mmq->Shutdown();

        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::duration<float> duration = end - begin;

        for (int numThreads = 1; numThreads <= 16; ++numThreads) {
            json jj;
            jj["num_threads"] = numThreads;
            jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();
            
            j[resultsString].push_back(jj);
        }
    }
}

int main()
{
    vector<shared_ptr<Message>> messages;
    for (int i = 0; i < 500; ++i) {
        messages.push_back(make_shared<Message>());
        messages.back()->m_targetFile = "../../data/dumps/test_" + to_string(i) + ".txt";
        for (int j = 0; j < PAYLOAD_SIZE; ++j) {
            messages.back()->m_payload[j] = j;
        }
    }

    json j;

    // Benchmark case (single thread!)
    prepareDataDirs();
    j["single_thread_results"] = json::array();
    {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        
        for (int i = 0; i < messages.size(); ++i) {
            ofstream file(messages[i]->m_targetFile, ios::app);
            for (int j = 0; j < PAYLOAD_SIZE; ++j) {
                file << to_string(messages[i]->m_payload[j]) << ", ";
            }
            file << endl;
            file.close();
        }

        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::duration<float> duration = end - begin;

        for (int numThreads = 1; numThreads <= 16; ++numThreads) {
            json jj;
            jj["num_threads"] = numThreads;
            jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();
            j["single_thread_results"].push_back(jj);
        }
    }

    // Testing MMQ
    MultithreadMessageQueue mmq;
    runExperiment(&mmq, j, "mmq_results", messages, 16);

    // Testing MMQ 2 with lockless queue
    MultithreadMessageQueue2 mmq2;
    runExperiment(&mmq2, j, "mmq_2_results", messages, 16);

    // Testing Naive multi-threaded approach
    NaiveMultithreadMessageQueue naiveMmq;
    runExperiment(&naiveMmq, j, "naive_results", messages, 1);

    ofstream o("../../data/results.json", ios::trunc);
    o << j.dump(4) << endl;
    o.close();

    system("cd ../../scripts && python3 ./analyze.py");
}
