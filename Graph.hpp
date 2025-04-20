#ifndef GRAPH_H
#define GRAPH_H


// Includes
#include "GraphBase.hpp"
#include <string>
#include <vector>
#include <limits>

class Graph : public GraphBase {
public:

    // Constructor
    Graph();

    // Destructor
    ~Graph() override;

    // Vertex Operations
    void addVertex(const std::string &label) override;
    void removeVertex(const std::string &label) override;

    // Edge Operations
    void addEdge(const std::string &label1,
                 const std::string &label2,
                 unsigned long weight) override;
    void removeEdge(const std::string &label1,
                    const std::string &label2) override;

    // Dijkstra shortest path
    unsigned long shortestPath(const std::string &startLabel,
                               const std::string &endLabel,
                               std::vector<std::string> &path) override;

private:
    // Storage
    std::vector<std::string> labels;
    std::vector<std::vector<std::pair<int, unsigned long>>> adj;

    // Helpers
    [[nodiscard]] int findIndex(const std::string &label) const;
    void removeVertexAt(int idx);
    static constexpr unsigned long INF =
        std::numeric_limits<unsigned long>::max();

};

#endif // GRAPH_H
