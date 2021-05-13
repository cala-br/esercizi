#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <istream>
#include <ostream>
#include "linked_list_types.hpp"

namespace ll {
  struct Node {
    ElemT value;
    Node *_next;
    Node *_prev;
  };


  Node *&next(Node *current);
  Node *&prev(Node *current);
  Node *last(Node *current);

  void deleteNode(Node *&list, Node *node);
  void clear(Node *&list);
  
  Node *addFront(Node *&list, ElemT value);
  Node *addBack(Node *&list, ElemT value);
  
  int count(Node *list, char *value);
  void deleteWhenValueEquals(Node *&list, ElemT value);
  Node *find(Node *list, ElemT value);
  
  std::istream& loadMany(Node *&list, int count, std::istream& stream);
  std::istream& loadOne(Node *&list, std::istream& stream);
  std::ostream& print(Node *list, std::ostream& stream);
}


#endif // !LINKED_LIST_HPP_