#include "linked_list.hpp"
#include <iostream>


using List = ll::Node*;
using Node = ll::Node*;

struct MenuChoice {
  enum _MenuChoice {
    INSERT_URL = 'i',
    DELETE_URL = 'd',
    PRINT_URLS = 'p',
    FIND_URL = 'f',
    EXIT = 'e',
  };
};

struct SearchSubmenuChoice {
  enum _SearchSubmenuChoice {
    FORWARD = 'f',
    BACKWARD = 'b',
    STOP = 's',
  };
};

std::ostream& operator<<(std::ostream& out, List node) {
  out << node->value;
  return out;
}


void addTo(List &list);
void deleteFrom(List &list);
void print(List list);
void findUrlIn(List list);
void startSearchSubmenu(Node res);
void maybeAssignAndPrint(Node &node, Node other);
char *input();



int main() {
  List list = nullptr;

  const char *menu =
    "i. Insert url\n"
    "d. Delete url\n"
    "p. Print urls\n"
    "f. Find url\n"
    "e. Exit\n"
    " >> ";

  while (true) {
    char choice;
    std::cout << menu;
    std::cin >> choice;

    switch (choice) {
      case MenuChoice::INSERT_URL: addTo(list);       break;
      case MenuChoice::DELETE_URL: deleteFrom(list);  break;
      case MenuChoice::PRINT_URLS: print(list);       break;
      case MenuChoice::FIND_URL:   findUrlIn(list);   break;
      case MenuChoice::EXIT:
        return 0;
    }

    std::cout << std::endl;
  }
}



void addTo(List &list) {
  ll::addFront(list, input());
}


void deleteFrom(List &list) {
  ll::deleteWhenValueEquals(list, input());
}


void print(List list) {
  while (list) {
    std::cout << list << '\n';
    list = ll::next(list);
  }
}


void findUrlIn(List list) {
  Node res = ll::find(list, input());
  if (res == nullptr) {
    std::cout << "Nothing found\n";
    return;
  }

  std::cout << res << '\n';
  startSearchSubmenu(res);
}

void startSearchSubmenu(Node res) {
  const char *submenu =
    "f. Forward\n" 
    "b. Backward\n" 
    "s. Stop\n" 
    " >> "; 

  while (true) {
    char choice;
    std::cout << submenu;
    std::cin >> choice;

    switch (choice) {
      case SearchSubmenuChoice::FORWARD:
        maybeAssignAndPrint(res, ll::prev(res));
        break;

      case SearchSubmenuChoice::BACKWARD:
        maybeAssignAndPrint(res, ll::next(res));
        break;

      case SearchSubmenuChoice::STOP:
        return;
    }

    std::cout << std::endl;
  }
}

void maybeAssignAndPrint(Node &node, Node other) {
  if (other != nullptr)
    node = other;

  std::cout << node << '\n';
}


char *input() {
  char *value = new char[50];
  std::cin >> value;

  return value;
}