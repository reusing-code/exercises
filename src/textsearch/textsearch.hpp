#pragma once

#include <set>
#include <string>

namespace exercise {

template <typename T>
class TextSearch {
 public:
  virtual void addString(std::string str, const T& result) = 0;
  virtual std::set<T> search(std::string keyword) = 0;
};

}  // namespace exercise