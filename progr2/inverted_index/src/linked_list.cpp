#include <cstring>
#include <ostream>
#include "linked_list.hpp"


namespace ll {
  Node *addFront(Node *&list, ElemT value) {
    Node *result = new Node {};
    copy(result->value, value);
    result->_next = list;

    if (list != nullptr)
      prev(list) = result;

    return list = result;
  }


  Node *addBack(Node *&list, ElemT value) {
    if (list == nullptr) {
      list = new Node {};
      copy(list->value, value);
      return list;
    }

    Node *last = ll::last(list);
    Node *&next = ll::next(last);
    next = new Node {
      .value = {},
      ._next = nullptr,
      ._prev = last,
    };

    copy(next->value, value);
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
      dispose(node->value);
    
    delete node;
  }

  
  int count(Node *list, ElemT value) {
    int count = 0;
    while ((list = find(list, value))) {
      list = next(list);
      count++;
    }

    return count;
  }

  void deleteWhenValueEquals(Node *&list, ElemT value) {
    Node *curr = list;
    Node *next = nullptr;

    while ((curr = find(curr, value))) {
      next = ll::next(curr);
      deleteNode(list, curr);

      curr = next;
    }
  }
  

  Node *find(Node *list, ElemT value) {
    while (list) {
      if (compare(list->value, value) == 0)
        return list;

      list = next(list);
    }

    return nullptr;
  }


  std::istream& loadMany(Node *&list, int count, std::istream& stream) {
    while (count-- > 0) {
      loadOne(list, stream);
    }
    return stream;
  }

  std::istream& loadOne(Node *&list, std::istream& stream) {
    ElemT elem;
    ll::load(elem, stream);
    ll::addFront(list, elem);
    
    return stream;
  }


  std::ostream& print(Node *list, std::ostream& stream) {
    stream << "[ ";
    while (list) {
      print(list->value, stream);
      
      list = next(list);
      if (list)
        stream << ", ";
    }
    return (stream << " ]");
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