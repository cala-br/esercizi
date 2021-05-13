#ifndef INVERTED_INDEX_WORD_HPP_
#define INVERTED_INDEX_WORD_HPP_

#include <linked_list.hpp>
#include <ostream>
#include <istream>

namespace ii {
  typedef char Word[80];

  struct IndexedWord {
    Word word;
    int documentsCount;
    ll::Node* documents;
  };

  IndexedWord* loadFrom(const char *path, int& count);
  std::istream& loadOne(IndexedWord& word, std::istream& stream);
  std::ostream& print(IndexedWord *words, int count, std::ostream& stream);

  void updateFrom(IndexedWord*& words, const char *path, int& count);
}

#endif // !INVERTED_INDEX_WORD_HPP_