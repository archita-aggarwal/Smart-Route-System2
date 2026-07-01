# 🚗 GraphRoute++ : Graph Algorithms Toolkit

*A graph-based route optimization system built in Modern C++ that finds the shortest path between locations using Dijkstra's Algorithm.*

---

## 📌 Overview

Smart Route Planner is a C++ application that models cities and roads as a weighted graph to compute the shortest route between any two locations. The project follows a modular architecture with separate components for graph management, shortest path computation, and user interaction, making it scalable and easy to maintain.

---

## ✨ Features

- 📍 Create and manage a weighted road network
- ➕ Add roads dynamically
- 🗺️ Display the complete graph
- 🚀 Find the shortest route between two locations
- 📏 Calculate total travel distance
- ⚡ Efficient implementation using Min Heap (`priority_queue`)
- 🧩 Modular OOP-based design

---

## 🏗️ Project Structure

```text
Smart-Route-Planner/
│
├── src/
│   ├── main.cpp
│   ├── Graph.cpp
│   └── Graph.h
│
├── README.md
└── LICENSE
```

---

## 🧠 Algorithm

The project uses **Dijkstra's Algorithm** to compute the minimum distance between two locations.

**Data Structures Used**
- Weighted Graph
- Adjacency List
- Priority Queue (Min Heap)
- `unordered_map`
- `vector`

---

## ⚙️ Time Complexity

| Operation | Complexity |
|----------|------------|
| Add Road | O(1) |
| Display Graph | O(V + E) |
| Shortest Path (Dijkstra) | O((V + E) log V) |

> **V** = Number of Locations  
> **E** = Number of Roads

---

## 🛠️ Tech Stack

- C++17
- STL
- Graph Algorithms
- Object-Oriented Programming

---

## 🚀 Getting Started

### Compile

```bash
g++ src/main.cpp src/Graph.cpp -o SmartRoutePlanner
```

### Run

**Linux/macOS**
```bash
./SmartRoutePlanner
```

**Windows**
```bash
SmartRoutePlanner.exe
```

---

## 📈 Future Enhancements

- A* Search Algorithm
- Traffic-aware routing
- Road closure support
- File-based graph loading
- GUI using Qt
- Map visualization

---

## 📚 Concepts Demonstrated

- Graphs
- Dijkstra's Algorithm
- Greedy Algorithms
- Priority Queue
- Hashing
- OOP
- STL
- Time Complexity Analysis

---

## 📄 License

This project is licensed under the MIT License.

---

## ⭐ Why this Project?

Smart Route Planner demonstrates how graph algorithms can solve real-world navigation problems while emphasizing clean architecture, modular C++ design, and efficient algorithm implementation.