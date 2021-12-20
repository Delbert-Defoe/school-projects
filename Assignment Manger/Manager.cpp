#include "Manager.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {

//Creating an object of class Manager
Manager UserEvent;

//int exit will be used to call the menu function and saves what ever it returns
int ex_it=0;

//the menu will be called until it returns the number 6
do{
ex_it=UserEvent.menu();
}while(ex_it!='6');

return 0;
}

