#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

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
}


#endif // !LINKED_LIST_HPP_