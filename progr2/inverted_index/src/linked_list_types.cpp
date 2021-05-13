#include <cstring>
#include <istream>
#include <ostream>
#include "linked_list_types.hpp"

namespace ll {
  int compare(const int& a, const int& b) {
    return a - b;
  }

  int compare(char* const& a, char* const& b) {
    return strcmp(a, b);
  }


  void copy(int& destination, const int source) {
    destination = source;
  }

  void copy(char*& destination, char *source) {
    destination = new char[strlen(source) + 1];
    strcpy(destination, source);
  }


  void dispose(int& elem) {
    elem = 0;
  }

  void dispose(char*& elem) {
    delete[] elem;
  }
  

  std::istream& load(int& elem, std::istream& stream) {
    return (stream >> elem);
  }

  std::ostream& print(const int& elem, std::ostream& stream) {
    return (stream << elem);
  }
}