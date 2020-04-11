#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

namespace exercise {

struct Connection {
  uint32_t to;
  double distance;
};

struct Node {
  uint32_t x, y;
  std::vector<Connection> connections;
};

using Graph = std::unordered_map<uint32_t, Node>;

double dijkstra(const Graph& graph, uint32_t from, uint32_t to);

double manhatten(const Node&, const Node&);

double aStar(const Graph& graph, uint32_t from, uint32_t to,
             std::function<double(const Node&, const Node&)>);

}  // namespace exercise
