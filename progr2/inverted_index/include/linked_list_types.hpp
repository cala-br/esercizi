#ifndef LINKED_LIST_TYPES_H_
#define LINKED_LIST_TYPES_H_

#include <istream>
#include <ostream>

namespace ll {
  using ElemT = int;

  int compare(const ElemT& a, const ElemT& b);
  void copy(ElemT& destination, const ElemT source);
  void dispose(ElemT& elem);

  std::istream& load(ElemT& elem, std::istream& stream);
  std::ostream& print(const ElemT& elem, std::ostream& stream);
}

#endif // !LINKED_LIST_TYPES_H_