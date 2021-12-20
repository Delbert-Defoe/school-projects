#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int ArraySize=50;

static char filename[] = "AllAssignments.txt";

 struct Assignment{

  string Course_code;
  string Name;
  string Description;
  string Due_Date;
  string Assignment_Number;
  };

class Manager{

public:

    Manager();
    int menu();
    void readEntireFile(int &);
    void addAssignment(int &);
    void updateAssignment();
    void removeAssignment(int &);
    void displayALl(int &);
    void displaySpecific();



private:
  Assignment newAssignment[ArraySize];
  char option;
  int index;
  int lastIndex;
  string coursecode;
  string name;
  string description;
  string duedate;
  int assignmentNumber;

  ifstream readFile;
  ofstream writeFile;
};


#endif // MANAGER_H
