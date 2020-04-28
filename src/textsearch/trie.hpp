#pragma once

#include <array>
#include <cctype>
#include <functional>
#include <memory>

#include "textsearch.hpp"

namespace exercise {

template <typename T>
class Trie : public TextSearch<T> {
 public:
  void addString(std::string str, const T& result) override {
    tokenize(str, [this, &result](std::string::iterator first, std::string::iterator last) {
      addToken(first, last, result);
    });
  };
  std::set<T> search(std::string keyword) override {
        Node* currentNode = &root_;
    for (auto it = keyword.begin(); it != keyword.end(); ++it) {
      auto idx = calcIdx(*it);
      if (idx == kNumChars + 1) {
        continue;
      }
      std::unique_ptr<Node>& uq = currentNode->children[idx];
      if (!uq) {
        return {};
      }
      currentNode = uq.get();

    }
    std::set<T> result;
    collect(currentNode, result);
    return result;
  };

 private:
  static constexpr size_t kNumChars{26};
  struct Node {
    std::array<std::unique_ptr<Node>, kNumChars> children;
    std::set<T> result;
  };

  size_t calcIdx(char c) {
    c |= 0x20;
    if (c < 97 || c > 122) {
      return kNumChars;
    }
    return c - 97;
  }

  void tokenize(std::string input,
                std::function<void(std::string::iterator first, std::string::iterator last)> cb) {
    auto current = input.begin();
    for (auto it = input.begin(); it != input.end(); ++it) {
      if (std::isspace(static_cast<unsigned char>(*it))) {
        if (it - current > 0) {
          cb(current, it);
        }
        current = it + 1;
      }
    }
    if (input.end() - current > 0) {
      cb(current, input.end());
    }
  }

template <class InputIt>
  void addToken(InputIt first, InputIt last, const T& result) {
    Node* currentNode = &root_;
    for (InputIt it = first; it != last; ++it) {
      auto idx = calcIdx(*it);
      if (idx >= kNumChars) {
        continue;
      }
      std::unique_ptr<Node>& uq = currentNode->children[idx];
      if (!uq) {
        uq = std::make_unique<Node>();
      }
      currentNode = uq.get();
    }
    if (currentNode != &root_) {
      currentNode->result.insert(result);
    }
  }

  void collect(Node* node, std::set<T>& result) {
    if (!node) {
      return;
    }
    result.insert(node->result.begin(), node->result.end());
    for (size_t i = 0; i < kNumChars; ++i) {
      collect(node->children[i].get(), result);
    }
  }

  Node root_;
};
}  // namespace exercise