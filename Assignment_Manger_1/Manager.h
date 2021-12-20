#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

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
    //constructor

    int menu();
    /*
    This is the main menu which keeps on looping until told to exit.
    It is responsible for calling all functions.
    */

    void help();
    /*
    This function gives a concise overview as to how to use the program.
    */

    void readEntireFile(int &);
    /*
    This function is called before almost every function
    It simply reads the data from the assignment manager file into a struct array
    */

    void addAssignment(int &);
    /*
    This Function adds new data to the file
    */

    void updateAssignment();
    /*
    This functions allows data from a specific course to be re-written
    */

    void removeAssignment(int &);
    /*
    This Function allows for an assignment to be deleted from a file
    */

    void displayALl(int &);
    /*
    This function displays all functions in a tabulated form
    */

    void displaySpecific();
    /*
    This function displays all courses with the given code
    */



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
  //ifstream object
  ofstream writeFile;
  //ofstream object
};


#endif // MANAGER_H
