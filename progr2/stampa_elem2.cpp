#include <iostream>

struct Node {
  int value;
  Node *_next;
};


Node *&llNext(Node *current) {
  return current->_next;
}

Node *llLast(Node *current) {
  while (current && llNext(current)) {
    current = llNext(current);
  }

  return current;
}


Node *llGetNodeThatHasNext(Node *list, Node *node) {
  while (list && node && llNext(list) != node)
    list = llNext(list);

  return list;
}

bool _llTryDeleteIfHead(Node *&list, Node *node) {
  if (list != node)
    return false;

  list = llNext(list);
  delete node;
  return true;
}

void llDelete(Node *&list, Node *node) {
  if (list == NULL || node == NULL)
    return;

  if (_llTryDeleteIfHead(list, node))
    return;

  Node *prev = llGetNodeThatHasNext(list, node);
  llNext(prev) = llNext(node);
  delete node;
}

void llClear(Node *&list) {
  while (list)
    llDelete(list, list);
}


Node *llAddFront(Node *&list, int value) {
  return list = new Node {
    .value = value,
    ._next = list,
  };
}


Node *llAddBack(Node *&list, int value) {
  if (list == NULL) {
    return list = new Node {value};
  }

  Node *last = llLast(list);
  Node *&next = llNext(last);
  return next = new Node {value};
}


Node *llFind(Node *list, int value) {
  while (list) {
    if (list->value == value)
      return list;

    list = llNext(list);
  }

  return NULL;
}


void llPrint(Node *list) {
  while (list) {
    std::cout << list->value << '\n';
    list = llNext(list);
  }
}

Node *llCreate(int n) {
  Node *result = NULL;
  while (n-- > 0) {
    int val;
    std::cin >> val;

    llAddFront(result, val);
  }

  return result;
}


int main() {
  Node *l = NULL;

  int n;
  std::cout << "n: ";
  std::cin >> n;
  l = llCreate(n);

  Node *e = llFind(l, 10);
  llPrint(e);
}