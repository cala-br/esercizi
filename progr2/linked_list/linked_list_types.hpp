#ifndef LINKED_LIST_TYPES_H_
#define LINKED_LIST_TYPES_H_

namespace ll {
  using ElemT = char*;

  int compare(const ElemT& a, const ElemT& b);
  void copy(ElemT& destination, const ElemT source);
  void print(const ElemT& elem);
  void dispose(ElemT& elem);
}

#endif // !LINKED_LIST_TYPES_H_