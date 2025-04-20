#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <vector>
#include <string>

class GraphBase {
public:
    virtual ~GraphBase() = default;
    virtual void addVertex(const std::string &label) = 0;
    virtual void removeVertex(const std::string &label) = 0;
    virtual void addEdge(const std::string &label1,
                         const std::string &label2,
                         unsigned long weight) = 0;
    virtual void removeEdge(const std::string &label1,
                            const std::string &label2) = 0;
    virtual unsigned long shortestPath(const std::string &startLabel,
                                       const std::string &endLabel,
                                       std::vector<std::string> &path) = 0;
};

#endif // GRAPHBASE_H
