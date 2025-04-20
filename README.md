# Dijkstra's Algorithm Implementation

This project implements Dijkstra's algorithm for finding the shortest path between vertices in a graph. The implementation is in C++ and uses CMake as the build system.

## Project Structure

- `main.cpp` - Contains the main program with example graphs and shortest path calculations
- `Graph.cpp`/`Graph.hpp` - Implementation of the Graph class with Dijkstra's algorithm
- `GraphBase.hpp` - Base interface for the Graph implementation
- `CMakeLists.txt` - CMake configuration file

## Requirements

- C++ compiler (e.g., GCC, Clang, or MSVC)
- CMake (version 3.0 or higher)

## Building and Running the Project

### Using CMake (Recommended)

1. Open a terminal and navigate to the project directory:

   ```
   cd /path/to/Dijkstras
   ```

2. Create a build directory and build the project:

   ```
   cmake -B build
   cmake --build build
   ```

3. Run the executable:

   ```
   # On macOS/Linux:
   ./build/Djikstra_s

   # On Windows:
   build\Djikstra_s.exe
   ```

### Using Clang/GCC Directly

If you prefer not to use CMake, you can compile the project directly:

```
# Using g++:
g++ -std=c++17 main.cpp Graph.cpp -o dijkstra
./dijkstra

# Or using clang++:
clang++ -std=c++17 main.cpp Graph.cpp -o dijkstra
./dijkstra
```

## Example Output

The program contains two example graphs:

1. A simple numbered graph (1-6) demonstrating the basic algorithm
2. A campus map with building locations (BSN, LIB, ENB, MSC, CAS, SUB, SUN)

When you run the program, it will output the shortest paths and distances for predefined vertex pairs.

## Modifying the Code

To use your own graphs:

1. Create a Graph object
2. Add vertices using `addVertex()`
3. Add edges using `addEdge()`
4. Calculate the shortest path using `shortestPath()`
