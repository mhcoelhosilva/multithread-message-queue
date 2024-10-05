import matplotlib.pyplot as plt
import json
from pathlib import Path

with open("../data/results.json", 'r') as file:
    j = json.load(file)
    x = []
    y = []
    x2 = []
    y2 = []
    for obj in j["mmq_results"]:
        x.append(obj["num_threads"])
        y.append(obj["duration_ms"])
    for obj in j["mmq_2_results"]:
        x2.append(obj["num_threads"])
        y2.append(obj["duration_ms"])
    

    plt.plot(x, y, color='r', label='MMQ 1')
    plt.plot(x2, y2, color='g', label='MMQ 2')
    plt.title("Multi-thread Message Queue Performance (8 core CPU)")
    plt.xlabel("Number of threads")
    plt.ylabel("Program duration in milliseconds")
    plt.legend(loc='best')
    plt.show()