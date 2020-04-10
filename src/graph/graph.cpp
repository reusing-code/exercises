#include "graph.hpp"

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
    distances[elem.nodeId] = elem.distance;
    addNextNodes(elem.nodeId);
    if (elem.nodeId == to) {
      return elem.distance;
    }
  }
  return -1.;
}

}  // namespace exercise