import matplotlib.pyplot as plt
import json
from pathlib import Path

with open("../data/results.json", 'r') as file:
    j = json.load(file)
    x = []
    y = []
    for obj in j["results"]:
        x.append(obj["num_threads"])
        y.append(obj["duration_ms"])

    plt.plot(x, y)
    plt.title("Multi-thread Message Queue Performance (8 core CPU)")
    plt.xlabel("Number of threads")
    plt.ylabel("Program duration in milliseconds")
    plt.show()