#include "Casino.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Convert from input
void convertFromInput(string &line) {
  line.erase(remove(line.begin(), line.end(), '\n'), line.end());
  line.erase(remove(line.begin(), line.end(), '\r'), line.end());
  line.erase(remove(line.begin(), line.end(), '['), line.end());
  line.erase(remove(line.begin(), line.end(), ']'), line.end());
  line.erase(remove(line.begin(), line.end(), ':'), line.end());
  line.erase(remove(line.begin(), line.end(), ';'), line.end());
  size_t pos = line.find("name");
  if (pos != string::npos) {
    line.erase(pos, string("name").length());
  }
  pos = line.find("age");
  if (pos != string::npos) {
    line.erase(pos, string("age").length());
  }
  pos = line.find("deposit");
  if (pos != string::npos) {
    line.erase(pos, string("deposit").length());
  }
  pos = line.find("number of drinks");
  if (pos != string::npos) {
    line.erase(pos, string("number of drinks").length());
  }
}

// Convert from command
void convertFromCommand(string &line) {
  line.erase(remove(line.begin(), line.end(), '\n'), line.end());
  line.erase(remove(line.begin(), line.end(), '\r'), line.end());
  line.erase(remove(line.begin(), line.end(), '['), line.end());
  line.erase(remove(line.begin(), line.end(), ']'), line.end());
  line.erase(remove(line.begin(), line.end(), ':'), line.end());
  line.erase(remove(line.begin(), line.end(), ';'), line.end());
  line.erase(remove(line.begin(), line.end(), '('), line.end());
  line.erase(remove(line.begin(), line.end(), ')'), line.end());
  size_t pos = line.find("name");
  if (pos != string::npos) {
    line.erase(pos, string("name").length());
  }
  pos = line.find("age");
  if (pos != string::npos) {
    line.erase(pos, string("age").length());
  }
  pos = line.find("deposit");
  if (pos != string::npos) {
    line.erase(pos, string("deposit").length());
  }
  pos = line.find("number of drinks");
  if (pos != string::npos) {
    line.erase(pos, string("number of drinks").length());
  }
}

int main() {
  Casino *casino = new Casino();
  string line;
  string name, command;
  int age, deposit, chips, index;
  int size = 0;
  fstream input("input1.txt");
  fstream inputCommand("command2.txt");

  if (!input.is_open()) {
    cout << "Error opening file" << endl;
  } else {
    while (getline(input, line)) {
      convertFromInput(line);
      istringstream ss(line);
      ss >> name >> age >> deposit >> chips;

      if (casino->isEmpty()) {
        size++;
        casino->insertAtHead(name, age, deposit, chips);
      } else {
        size++;
        casino->insertAtTail(name, age, deposit, chips);
      }
    }
    casino->printCasino();
    cout << endl;
    cout << size;
    cout << endl;
    while (getline(inputCommand, line)) {
      convertFromCommand(line);
      //cout << line << endl;
      istringstream ss(line);
      ss >> command >> index >> name >> age >> deposit >> chips;
      if (command == "Add") {
        casino->insertAtPosition(name, age, deposit, chips, index, size);
      }
      /* cout << "Command: " << command << " Index: " << index << " Name: " << name
           << " Age: " << age << " Deposit: " << deposit
           << " NumDrinks: " << chips << endl; */
    }
    casino->printCasino();
  }

  delete casino;

  return 0;
}