#include "linked_list.hpp"
#include <cstring>


namespace ll {
  Node *addFront(Node *&list, ElemT value) {
    Node *result = new Node {};
    ll::copy(result->value, value);
    result->_next = list;

    if (list != nullptr)
      prev(list) = result;

    return list = result;
  }


  Node *addBack(Node *&list, ElemT value) {
    if (list == nullptr) {
      list = new Node {};
      ll::copy(list->value, value);
      return list;
    }

    Node *last = ll::last(list);
    Node *&next = ll::next(last);
    next = new Node {
      .value = {},
      ._next = nullptr,
      ._prev = last,
    };

    ll::copy(next->value, value);
    return next;
  }


  void clear(Node *&list) {
    while (list)
      deleteNode(list, list);
  }


  void deleteNode(Node *&list, Node *node) {
    if (list == nullptr || node == nullptr)
      return;

    Node *prev = ll::prev(node);
    Node *next = ll::next(node);
    
    if (next) ll::prev(next) = prev;
    if (prev) ll::next(prev) = next;
    
    if (list == node)
      list = next;

    if (node->value)
      ll::dispose(node->value);
    
    delete node;
  }

  
  int count(Node *list, ElemT value) {
    int count = 0;
    while (list = find(list, value)) {
      list = next(list);
      count++;
    }

    return count;
  }

  void deleteWhenValueEquals(Node *&list, ElemT value) {
    Node *curr = list;
    Node *next = nullptr;

    while (curr = find(curr, value)) {
      next = ll::next(curr);
      deleteNode(list, curr);

      curr = next;
    }
  }
  

  Node *find(Node *list, ElemT value) {
    while (list) {
      if (ll::compare(list->value, value) == 0)
        return list;

      list = next(list);
    }

    return nullptr;
  }


  Node *&next(Node *current) {
    return current->_next;
  }

  Node *&prev(Node *current) {
    return current->_prev;
  }

  Node *last(Node *current) {
    while (current && next(current)) {
      current = next(current);
    }

    return current;
  }
}