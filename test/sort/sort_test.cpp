#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <sort/sort.hpp>
#include <vector>

TEST(Sort, basic1) {
  std::vector<int> values{};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_EQ(values.size(), 0);
}

TEST(Sort, basic2) {
  std::vector<int> values{10, 2, 1, 3, 7};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 7, 10}));
}

TEST(Sort, basic3) {
  std::vector<int> values{1, 2, 3, 4, 5};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 4, 5}));
}

TEST(Sort, basic4) {
  std::vector<int> values{5, 4, 3, 2, 1};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 4, 5}));
}

TEST(Sort, basic5) {
  std::vector<int> values{5, 5, 5, 5, 5};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({5, 5, 5, 5, 5}));
}

TEST(Sort, basic6) {
  std::vector<int> values{10, 2, 1, 3, 7, 9};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 7, 9, 10}));
}

TEST(Sort, basic7) {
  std::vector<int> values{10, 2, 1, 3};

  exercise::sort(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 10}));
}

TEST(Sort, merge1) {
  std::vector<int> values{};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_EQ(values.size(), 0);
}

TEST(Sort, merge2) {
  std::vector<int> values{10, 2, 1, 3, 7};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());
  EXPECT_EQ(values.size(), 5);

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 7, 10}));
}

TEST(Sort, merge3) {
  std::vector<int> values{1, 2, 3, 4, 5};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 4, 5}));
}

TEST(Sort, merge4) {
  std::vector<int> values{5, 4, 3, 2, 1};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 4, 5}));
}

TEST(Sort, merge5) {
  std::vector<int> values{5, 5, 5, 5, 5};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({5, 5, 5, 5, 5}));
}

TEST(Sort, merge6) {
  std::vector<int> values{10, 2, 1, 3, 7, 9};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 7, 9, 10}));
}

TEST(Sort, merge7) {
  std::vector<int> values{10, 2, 1, 3};

  exercise::sortMerge(values.begin(), values.end(), std::less<int>());

  ASSERT_THAT(values, ::testing::ElementsAreArray({1, 2, 3, 10}));
}