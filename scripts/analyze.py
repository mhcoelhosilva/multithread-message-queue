import matplotlib.pyplot as plt
import json
from pathlib import Path

with open("../data/results.json", 'r') as file:
    j = json.load(file)
    x = []
    y = []
    x2 = []
    y2 = []
    x3 = []
    y3 = []
    x4 = []
    y4 = []
    for obj in j["mmq_results"]:
        x.append(obj["num_threads"])
        y.append(obj["duration_ms"])
    for obj in j["mmq_2_results"]:
        x2.append(obj["num_threads"])
        y2.append(obj["duration_ms"])
    for obj in j["single_thread_results"]:
        x3.append(obj["num_threads"])
        y3.append(obj["duration_ms"])
    for obj in j["naive_results"]:
        x4.append(obj["num_threads"])
        y4.append(obj["duration_ms"])
    

    plt.plot(x, y, color='r', label='MMQ 1')
    plt.plot(x2, y2, color='g', label='MMQ 2')
    plt.plot(x3, y3, color='b', label='Single thread')
    plt.plot(x4, y4, color='c', label='Naive')
    plt.title("Multi-thread Message Queue Performance (8 core CPU)")
    plt.xlabel("Number of threads")
    plt.ylabel("Program duration in milliseconds")
    plt.legend(loc='best')
    plt.show()