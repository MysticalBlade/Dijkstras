#include "Graph.hpp"
#include <iostream>

static void show(const std::vector<std::string>& p) {
    for (size_t i = 0; i < p.size(); ++i)
        std::cout << p[i] << (i + 1 < p.size() ? " -> " : "\n");
}

int main() {
    /* ----- Graph 1 ----- */
    Graph g1;
    for (auto s : {"1","2","3","4","5","6"}) g1.addVertex(s);

    using Edge = std::tuple<std::string,std::string,unsigned long>;
    std::vector<Edge> e1 {
        {"1","2",7},{"1","3",9},{"1","6",14},{"2","3",10},
        {"2","4",15},{"3","4",11},{"3","6",2},{"4","5",6},{"5","6",9}
    };
    for (auto &e : e1) g1.addEdge(std::get<0>(e), std::get<1>(e), std::get<2>(e));

    std::vector<std::string> path;
    std::cout << "Dist 1->5 = " << g1.shortestPath("1","5",path) << '\n';
    show(path);

    /* ----- Graph 2 ----- */
    Graph g2;
    for (auto s : {"BSN","LIB","ENB","MSC","CAS","SUB","SUN"}) g2.addVertex(s);

    struct E{std::string a,b; unsigned long w;};
    std::vector<E> e2 {
        {"BSN","LIB",871},{"BSN","CAS",1672},{"BSN","MSC",2355},
        {"SUN","SUB",1265},{"LIB","MSC",1615},{"LIB","SUN",1847},
        {"ENB","SUN",2885},{"ENB","CAS",454},{"ENB","LIB",1078}
    };
    for (auto &e : e2) g2.addEdge(e.a,e.b,e.w);

    std::cout << "\nDist ENB->SUN = " << g2.shortestPath("ENB","SUN",path) << '\n';
    show(path);

    std::cout << "Dist LIB->CAS = " << g2.shortestPath("LIB","CAS",path) << '\n';
    show(path);
}
