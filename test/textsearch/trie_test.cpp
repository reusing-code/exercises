#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <set>
#include <string>
#include <textsearch/textsearch.hpp>
#include <textsearch/trie.hpp>
#include <vector>

/**
 * The English test data originates from the Wikipedia article
 * 'Trie' ( https://en.wikipedia.org/wiki/Trie ),
 * which is released under the Creative Commons Attribution-Share-Alike
 * License 3.0 ( https://creativecommons.org/licenses/by-sa/3.0/ ).
 *
 * The German test data originates from the Wikipedia article
 * 'Trie' ( https://de.wikipedia.org/wiki/Trie ),
 * which is released under the Creative Commons Attribution-Share-Alike
 * License 3.0 ( https://creativecommons.org/licenses/by-sa/3.0/ ).
 *
 **/

static const std::vector<std::string> testDataEN{
    "In computer science, a trie, also called digital tree or prefix tree, is "
    "a kind of search tree—an ordered tree data structure used to store a "
    "dynamic set or associative array where the keys are usually strings.",
    "Keys tend to be associated with leaves, though some inner nodes may "
    "correspond to keys of interest.",
    "Tries were first described by René de la Briandais in 1959.[1][2]:336 The "
    "term trie was coined two years later by Edward Fredkin, who pronounces it "
    "/ˈtriː/ (as \" tree \"), after the middle syllable of retrieval."};

static const std::vector<std::string> testDataDE{
    "Ein Trie oder Präfixbaum ist eine Datenstruktur, die in der Informatik "
    "zum Suchen nach Zeichenketten verwendet wird.",
    "Der Ausdruck Trie wurde von Edward Fredkin in Anlehnung an den Begriff "
    "Information Retrieval vorgeschlagen.",
    "Tries finden ihre Anwendung im Bereich des Information Retrieval. Dort "
    "werden sie zur Indexierung von Texten verwendet, um effizient bestimmte "
    "Anfragen an den Text zu beantworten."};

struct TestCase {
  std::string keyword;
  std::set<std::string> result;
};

static const std::vector<TestCase> testCases{
    {"Trie", {"en", "de"}},     //
    {"trie", {"en", "de"}},     //
    {"TRIE", {"en", "de"}},     //
    {"notaword", {}},           //
    {"correspond", {"en"}},     //
    {"vorgeschlagen", {"de"}},  //
    {"vorgeschlage", {"de"}},  //
    {"vorgeschla", {"de"}},  //
    {"vorg", {"de"}},  //
    {"vor", {"de"}},  //

};

class TrieTest : public ::testing::Test {
 protected:
  void SetUp() override {
    for (const auto& str : testDataDE) {
      trie_.addString(str, "de");
    }
    for (const auto& str : testDataEN) {
      trie_.addString(str, "en");
    }
  }

  exercise::Trie<std::string> trie_;
};

TEST_F(TrieTest, Basic) {
  for (const auto& tc : testCases) {
    auto result = trie_.search(tc.keyword);
    EXPECT_EQ(tc.result, result);
  }
}