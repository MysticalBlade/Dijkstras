#include "Graph.hpp"
#include <algorithm>


// Constructor
Graph::Graph() = default;

// Destructor
Graph::~Graph() = default;

// Return index of label or ‑1 if absent
int Graph::findIndex(const std::string &label) const {
  for (int i = 0; i < (int) labels.size(); ++i)
    if (labels[i] == label) return i;
  return -1;
}

// Add unique vertex
void Graph::addVertex(const std::string &label) {
  if (findIndex(label) != -1) return;
  labels.push_back(label);
  adj.emplace_back();             // new empty list
}

// Remove vertex and all incident edges
void Graph::removeVertex(const std::string &label) {
  int idx = findIndex(label);
  if (idx != -1) removeVertexAt(idx);
}

// Internal: erase vertex @idx and re‑index neighbors */
void Graph::removeVertexAt(int idx) {
  for (auto &nbrs : adj)            // Drop edges TO idx
    nbrs.erase(std::remove_if(nbrs.begin(), nbrs.end(),
                [&](auto &p){ return p.first == idx; }), nbrs.end());

  adj.erase(adj.begin() + idx);     // Erase list
  labels.erase(labels.begin() + idx);

  for (auto &nbrs : adj)            // Shift indices > idx
    for (auto &p : nbrs) if (p.first > idx) --p.first;
}

// Add undirected edge if valid & absent
void Graph::addEdge(const std::string &l1,
                    const std::string &l2,
                    unsigned long w) {
  int i = findIndex(l1), j = findIndex(l2);
  if (i < 0 || j < 0 || i == j) return;
  for (auto &p : adj[i]) if (p.first == j) return; // exists

  adj[i].emplace_back(j, w);
  adj[j].emplace_back(i, w);
}

// Remove undirected edge
void Graph::removeEdge(const std::string &l1,
                       const std::string &l2) {
  int i = findIndex(l1), j = findIndex(l2);
  if (i < 0 || j < 0) return;

  auto strip = [&](int a, int b){
    auto &nbrs = adj[a];
    nbrs.erase(std::remove_if(nbrs.begin(), nbrs.end(),
              [&](auto &p){ return p.first == b; }), nbrs.end());
  };
  strip(i,j); strip(j,i);
}

// O(V^2) Dijkstras
unsigned long Graph::shortestPath(const std::string &startLabel,
                                  const std::string &endLabel,
                                  std::vector<std::string> &path) {
  path.clear();
  int s = findIndex(startLabel), t = findIndex(endLabel);
  if (s < 0 || t < 0) return INF;

  int n = labels.size();
  std::vector<unsigned long> dist(n, INF);
  std::vector<int> prev(n, -1);
  std::vector<bool> used(n, false);

  dist[s] = 0;

  for (int k = 0; k < n; ++k) {
    // Pick the closest unused vertex
    int u = -1; unsigned long best = INF;
    for (int i = 0; i < n; ++i)
      if (!used[i] && dist[i] < best) { best = dist[i]; u = i; }
    if (u == -1) break;
    used[u] = true;

    // Relax its neighbors
    for (auto &[v, w] : adj[u])
      if (!used[v] && dist[u] + w < dist[v]) {
        dist[v]  = dist[u] + w;
        prev[v]  = u;
      }
  }

  if (dist[t] == INF) return INF;   // no path

  // Rebuild path
  for (int cur = t; cur != -1; cur = prev[cur])
    path.push_back(labels[cur]);
  std::reverse(path.begin(), path.end());
  return dist[t];
}
