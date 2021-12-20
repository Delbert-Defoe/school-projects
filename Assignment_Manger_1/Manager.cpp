#include "Manager.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {

//Creating an object of class Manager
Manager UserEvent;

//int ex_it will be used to call the menu function and saves what ever it returns
int ex_it=0;

//the menu will be called until it returns the number 7
do{
ex_it=UserEvent.menu();
}while(ex_it!='7');

return 0;
}


