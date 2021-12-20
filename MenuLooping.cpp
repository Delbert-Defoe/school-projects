#include <iostream>
#include <windows.h>

using namespace std;

int main() {

  //title
  system("title Menu");
 //variables
 char option=' ';
 string name= "";

 do {
    cout << "\n-----------------"
         << "\n  Simple Menu    "
         << "\n-----------------"
         <<"\n 1.Say Hello"
         <<"\n 2.Exit"
         << "\n------------------"
         <<"\n select an option: ";

         cin>>option;

         //evaluate user input
    system("cls");
     switch(option)
     {

    case '1':

        cout << "\n please enter your first name: ";
        cin>>name;

        cout <<" \n hello "<<name <<endl;
        break;

    case '2':

        cout << "\n Goodbye........";
        break;

    default:
        cout<< "\a\n Invalid option!!!!!"<<endl;
        system("pause"); //pauses run time
     }


 } while(option !='2'); //loop until 2 is selected

 return 0;

}
//end main
