// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    prepareDataDirs();
    j["mmq_results"] = json::array();
    for (int numThreads = 1; numThreads <= 16; ++numThreads) {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        MultithreadMessageQueue mmq;
        mmq.Start(numThreads);
        for (int i = 0; i < messages.size(); ++i) {
            mmq.AddMessage(messages[i]);
        }
        while (!mmq.IsDoneProcessing()) {}
        mmq.Shutdown();

        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::duration<float> duration = end - begin;

        json jj;
        jj["num_threads"] = numThreads;
        jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();

        j["mmq_results"].push_back(jj);
    }

    // Testing MMQ 2 with lockless queue
    prepareDataDirs();
    j["mmq_2_results"] = json::array();
    for (int numThreads = 1; numThreads <= 16; ++numThreads) {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        MultithreadMessageQueue2 mmq;
        mmq.Start(numThreads);
        for (int i = 0; i < messages.size(); ++i) {
            mmq.AddMessageAsync(messages[i]);
        }
        while (!mmq.IsDoneProcessing()) {}
        mmq.Shutdown();

        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::duration<float> duration = end - begin;

        json jj;
        jj["num_threads"] = numThreads;
        jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();

        j["mmq_2_results"].push_back(jj);
    }

    // Testing Naive multi-threaded approach
    prepareDataDirs();
    j["naive_results"] = json::array();
    {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();

        NaiveMultithreadMessageQueue mmq;
        for (int i = 0; i < messages.size(); ++i) {
            mmq.AddMessageAsync(messages[i]);
        }
        mmq.Shutdown();

        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        chrono::duration<float> duration = end - begin;

        for (int numThreads = 1; numThreads <= 16; ++numThreads) {
            json jj;
            jj["num_threads"] = numThreads;
            jj["duration_ms"] = chrono::duration_cast<chrono::milliseconds>(duration).count();
            j["naive_results"].push_back(jj);
        }
    }

    ofstream o("../../data/results.json", ios::trunc);
    o << j.dump(4) << endl;
    o.close();

    system("cd ../../scripts && python3 ./analyze.py");
}
