#include "node.h"
#include <iostream>

using namespace std;

class LL {
  NodePtr head; // head of circular linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  void printListR();
  ~LL();
};

LL::LL() {
  this->head = nullptr;
  size = 0;
}

LL::~LL() {
  cout << "Deleting all nodes" << endl;
  NodePtr currentPtr = head;
  NodePtr nextPtr;

  if (currentPtr != nullptr) {
    do {
      nextPtr = currentPtr->get_next();
      delete currentPtr;
      currentPtr = nextPtr;
    } while (currentPtr != head);
  }
}

void LL::insert(int value) {
  NodePtr newPtr = new Node(value);

  if (newPtr != nullptr) {
    if (head == nullptr) {
      head = newPtr;
      newPtr->set_next(newPtr);
      newPtr->set_prev(newPtr);
    } else {
      NodePtr last = head->get_prev();

      newPtr->set_next(head);
      newPtr->set_prev(last);
      head->set_prev(newPtr);
      last->set_next(newPtr);
    }

    ++size;
  } else {
    cout << value << " not inserted. No memory available." << endl;
  }
}

int LL::deletes(int value) {
  if (isEmpty()) {
    return '\0';
  }

  NodePtr currentPtr = head;

  do {
    if (currentPtr->get_data() == value) {
      NodePtr prevPtr = currentPtr->get_prev();
      NodePtr nextPtr = currentPtr->get_next();

      prevPtr->set_next(nextPtr);
      nextPtr->set_prev(prevPtr);

      if (currentPtr == head) {
        head = nextPtr;
      }

      int deletedValue = currentPtr->get_data();
      delete currentPtr;
      size--;

      return deletedValue;
    }

    currentPtr = currentPtr->get_next();
  } while (currentPtr != head);

  cout << value << " not found." << endl;
  return '\0';
}

int LL::isEmpty() {
  return head == nullptr;
}

void LL::printListR() {
  if (isEmpty()) {
    cout << "List is empty." << endl;
    return;
  }

  NodePtr currentPtr = head->get_prev();
  
  cout << "The reversed list is:" << endl;
  do {
    currentPtr->print();
    cout << " -> ";
    currentPtr = currentPtr->get_prev();
  } while (currentPtr != head->get_prev());

  cout << endl;
}

void LL::printList() {
  if (isEmpty()) {
    cout << "List is empty." << endl;
    return;
  }

  NodePtr currentPtr = head;

  cout << "The list is:" << endl;
  do {
    currentPtr->print();
    cout << " -> ";
    currentPtr = currentPtr->get_next();
  } while (currentPtr != head);

  cout << endl;
}