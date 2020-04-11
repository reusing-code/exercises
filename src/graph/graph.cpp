#include "graph.hpp"

#include <cmath>
#include <map>
#include <queue>

namespace exercise {

struct QueueElement {
  double distance;
  uint32_t nodeId;

  QueueElement(double distance_, uint32_t nodeId_)
      : distance(distance_), nodeId(nodeId_) {}
};

double dijkstra(const Graph& graph, uint32_t from, uint32_t to) {
  std::unordered_map<uint32_t, double> distances;
  auto cmp = [](const auto& l, const auto& r) {
    return l.distance > r.distance;
  };
  std::priority_queue<QueueElement, std::vector<QueueElement>, decltype(cmp)>
      queue(cmp);

  auto addNextNodes = [&graph, &queue, &distances](uint32_t nodeId) {
    for (const auto& next : graph.at(nodeId).connections) {
      if (distances.find(next.to) == distances.end()) {
        queue.emplace(distances.at(nodeId) + next.distance, next.to);
      }
    }
  };

  distances[from] = 0;
  addNextNodes(from);

  while (!queue.empty()) {
    QueueElement elem = queue.top();
    queue.pop();
    if (distances.find(elem.nodeId) != distances.end()) {
      continue;
    }
    distances[elem.nodeId] = elem.distance;
    addNextNodes(elem.nodeId);
    if (elem.nodeId == to) {
      return elem.distance;
    }
  }
  return -1.;
}

struct AStarQueueElement {
  double estimatedPathLength;
  double currentDistance;
  uint32_t nodeId;

  AStarQueueElement(double estimatedPathLength_, double currentDistance_,
                    uint32_t nodeId_)
      : estimatedPathLength(estimatedPathLength_),
        currentDistance(currentDistance_),
        nodeId(nodeId_) {}
};

double manhatten(const Node& l, const Node& r) {
  return std::abs(static_cast<int64_t>(l.x) - r.x) +
         std::abs(static_cast<int64_t>(l.y) - r.y);
}

double aStar(const Graph& graph, uint32_t from, uint32_t to,
             std::function<double(const Node&, const Node&)> heuristic) {
  std::unordered_map<uint32_t, double> distances;
  auto cmp = [](const auto& l, const auto& r) {
    return l.estimatedPathLength > r.estimatedPathLength;
  };
  std::priority_queue<AStarQueueElement, std::vector<AStarQueueElement>,
                      decltype(cmp)>
      queue(cmp);

  auto addNextNodes = [&graph, &queue, &distances, &heuristic,
                       &to](uint32_t nodeId) {
    for (const auto& next : graph.at(nodeId).connections) {
      if (distances.find(next.to) == distances.end()) {
        double distance = distances.at(nodeId) + next.distance;
        queue.emplace(distance + heuristic(graph.at(next.to), graph.at(to)),
                      distance, next.to);
      }
    }
  };

  distances[from] = 0;
  addNextNodes(from);

  while (!queue.empty()) {
    AStarQueueElement elem = queue.top();
    queue.pop();
    if (distances.find(elem.nodeId) != distances.end()) {
      continue;
    }
    distances[elem.nodeId] = elem.currentDistance;
    addNextNodes(elem.nodeId);
    if (elem.nodeId == to) {
      return elem.currentDistance;
    }
  }
  return -1.;
}

}  // namespace exercise