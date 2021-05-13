#include <iostream>
#include "words.hpp"

int main() {
  int wordsCount = 0;
  ii::IndexedWord *words = 
    ii::loadFrom("assets/inverted", wordsCount);
  
  ii::print(words, 3, std::cout) << std::endl;

  ii::updateFrom(words, "assets/doc", wordsCount);
}