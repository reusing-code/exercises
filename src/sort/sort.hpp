#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

namespace exercise {

template <class RandomIt, class Compare>
constexpr void sort(RandomIt first, RandomIt last, Compare comp) {
  if (last - first <= 3) {
    // selection sort
    for (auto it = first; it != last; ++it) {
      std::iter_swap(it, std::min_element(it, last, comp));
    }
    return;
  }
  RandomIt pivot = first;
  auto end = last;
  for (auto it = first + 1; it != end;) {
    if (comp(*it, *pivot)) {
      std::iter_swap(pivot, it);
      pivot = it;
      ++it;
    } else {
      std::iter_swap(it, end - 1);
      --end;
    }
  }
  sort(first, pivot);
  sort(pivot + 1, last);
}

template <class RandomIt, class Compare>
constexpr void sortMerge(RandomIt first, RandomIt last, Compare comp) {
  auto length = last - first;
  if (length <= 1) {
    return;
  }

  RandomIt middle = first + std::ceil(length / 2.0);
  sortMerge(first, middle, comp);
  sortMerge(middle, last, comp);

  RandomIt mergeL = first;
  RandomIt mergeR = middle;
  std::vector<typename std::iterator_traits<RandomIt>::value_type> temp;
  temp.reserve(length);
  while (mergeL != middle && mergeR != last) {
    if (comp(*mergeL, *mergeR)) {
      temp.push_back(*mergeL);
      ++mergeL;
    } else {
      temp.push_back(*mergeR);
      ++mergeR;
    }
  }
  temp.insert(temp.end(), mergeL, middle);
  temp.insert(temp.end(), mergeR, last);

  std::copy(temp.begin(), temp.end(), first);
}

}  // namespace exercise