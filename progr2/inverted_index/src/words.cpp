#include <fstream>
#include <ostream>
#include <iostream>
#include <cstring>
#include "words.hpp"
#include "linked_list_types.hpp"

using namespace std;


namespace ii {
  IndexedWord* loadFrom(const char *path, int& count) {
    ifstream file(path);
    file >> count;

    IndexedWord *words = new IndexedWord[count]{};
    for (int i = 0; i < count; i++) {
      loadOne(words[i], file);
    }

    return words;
  }

  istream& loadOne(IndexedWord& word, istream& stream) {
    stream >> word.word;
    stream >> word.documentsCount;
    return ll::loadMany(word.documents, word.documentsCount, stream);
  }


  ostream& print(IndexedWord *words, int count, ostream& stream) {
    for (int i = 0; i < count; i++) {
      IndexedWord& word = words[i];

      stream << word.word << '\n';
      stream << "docs: ";

      ll::print(word.documents, stream) << endl;
    }

    return stream;
  }


  static int countLines(istream& stream) {
    int lines = 1;
    while (stream) {
      if (stream.get() == '\n')
        lines++;
    }

    stream.clear();
    stream.seekg(0);
    return lines;
  }

  void updateFrom(IndexedWord*& words, const char *path, int& count) {
    ifstream file(path);
    int documentId;
    file >> documentId;

    int lines = countLines(file);
    Word *tmp = new Word[lines];
    
    const int wordLen = sizeof(Word);
    int newWords = 0;

    for (int i = 0; file.getline(tmp[i], wordLen); i++) {
      for (int j = 0; j < count; j++) {
        if (!strncmp(words[j].word, tmp[i], wordLen)) {
          if (!ll::find(words[i].documents, documentId)) {
            words[i].documentsCount++;
            ll::addFront(words[i].documents, documentId);
          }

          *tmp[i] = '\0';
        }
        else {
          newWords++;
        }
      }
    }

    
  }
}