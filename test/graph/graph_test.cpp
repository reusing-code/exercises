#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <graph/graph.hpp>

exercise::Graph simpleGraph{
    {1, {1, 1, {{2, 2}, {3, 2}}}},
    {2, {3, 1, {{1, 2}, {3, 5}}}},
    {3, {1, 3, {{1, 2}, {2, 5}}}},
};

exercise::Graph testGrap{
    {1, {1, 1, {{2, 5}, {3, 2}, {8, 4}, {9, 7}}}},                    // A
    {2, {3, 3, {{1, 5}, {3, 2}, {4, 3}, {12, 5}, {11, 2}, {8, 3}}}},  // B
    {3, {3, 1, {{1, 2}, {2, 2}, {5, 12}, {9, 5}}}},                   // C
    {4, {6, 3, {{2, 3}, {9, 2}, {6, 5}, {12, 2}}}},                   // D
    {5, {10, 1, {{3, 12}, {6, 6}}}},                                  // E
    {6, {8, 6, {{4, 5}, {5, 6}, {7, 5}, {11, 9}, {12, 4}}}},          // F
    {7, {4, 6, {{6, 5}, {8, 8}, {11, 3}}}},                           // G
    {8, {1, 5, {{1, 4}, {2, 3}, {7, 8}}}},                            // H
    {9, {6, 2, {{1, 7}, {3, 5}, {4, 2}}}},                            // I
    {11, {3, 4, {{2, 2}, {6, 9}, {7, 3}}}},                           // K
    {12, {5, 4, {{2, 5}, {4, 2}, {6, 4}}}},                           // L
};

struct testCase {
  const exercise::Graph& graph;
  int start, end;
  double expectedDistance;
};

std::vector<testCase> testCases{
    {simpleGraph, 1, 2, 2},  //
    {simpleGraph, 2, 1, 2},  //
    {simpleGraph, 1, 3, 2},  //
    {simpleGraph, 3, 1, 2},  //
    {simpleGraph, 2, 3, 4},  //
    {simpleGraph, 3, 2, 4},  //
    {testGrap, 1, 2, 4},     //
    {testGrap, 2, 1, 4},     //
    {testGrap, 1, 6, 12},    //
    {testGrap, 6, 1, 12},    //
    {testGrap, 5, 8, 17},    //
    {testGrap, 8, 5, 17},    //
};

TEST(Graph, dijkstra) {
  for (const auto& tc : testCases) {
    auto result = exercise::dijkstra(tc.graph, tc.start, tc.end);
    EXPECT_DOUBLE_EQ(result, tc.expectedDistance);
  }
}
