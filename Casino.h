#include <fstream>
#include <iostream>

using namespace std;

#ifndef CASINO_H
#define CASINO_H

struct People {
  string name;
  int age;
  int deposit;
  int chips;
  People *next;
};

class Casino {
private:
  People *head;

public:
  Casino() { head = nullptr; }
  // Check empty
  bool isEmpty() {
    if (head == nullptr) {
      return true;
    } else
      return false;
  }
  // Check duplicate
  bool isDuplicate(string name, int age) {
    People *cur = head;
    while (cur != nullptr) {
      if (cur->name == name && cur->age == age) {
        return true;
      }
      cur = cur->next;
    }
    return false;
  }
  // Get head
  People *getHead() { return head; }
  // Insert at beginning of the linked list
  void insertAtHead(string name, int age, int deposit, int chips) {
    People *temp = new People{name, age, deposit, chips, nullptr};
    if (isEmpty()) {
      head = temp;
    }
  }
  // Insert at end of the linked list
  void insertAtTail(string name, int age, int deposit, int chips) {
    People *temp = new People{name, age, deposit, chips, nullptr};
    if (isEmpty()) {
      head = temp;
    } else {
      People *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = temp;
    }
  }
  // Insert in the specific position of the linked list
  void insertAtPosition(string name, int age, int deposit, int chips, int pos,
                        int size) {
    if (pos == 0) {
      // Check duplicate to update instead of adding new
      if (isDuplicate(name, age)) {
        People *cur = head;
        while (cur != nullptr) {
          if (cur->name == name && cur->age == age) {
            cur->deposit += deposit;
            cur->chips += chips;
            return;
          }
        }
      } else {
        insertAtHead(name, age, deposit, chips);
      }
    } else if (pos >= size) {
      if (isDuplicate(name, age)) {
        People *cur = head;
        while (cur != nullptr) {
          if (cur->name == name && cur->age == age) {
            cur->deposit += deposit;
            cur->chips += chips;
            return;
          }
        }
      } else {
        insertAtTail(name, age, deposit, chips);
      }
    } else {
      if (isDuplicate(name, age)) {
        People *cur = head;
        while (cur != nullptr) {
          if (cur->name == name && cur->age == age) {
            cur->deposit += deposit;
            cur->chips += chips;
            return;
          }
        }
      } else {
        People *temp = new People{name, age, deposit, chips, nullptr};
        People *current = head;
        for (int i = 0; i < pos - 1; i++) {
          current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
      }
    }
  }
  // Print casino
  void printCasino() {
    People *current = head;
    while (current != nullptr) {
      cout << "[name: " << current->name << "; age: " << current->age
           << "; deposit: " << current->deposit
           << "; number of drinks: " << current->chips << "]" << endl;
      current = current->next;
    }
  }
};

#endif