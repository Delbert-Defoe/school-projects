//void functions
#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

//prototyping functions
void GetNumber(int &);
void DisplayTimeTable(int number);

//main function
int main() {

system("Title Time Table Generator");

//choice will capture the action to be taken from the menu
char choice=' ';
//num will allocate a memory location to be passed to GetNumber function
int num=0;

//this will run until user chooses to exit
do{

system("cls");

cout<<"==================================================================================="<<endl;
cout<<">Welcome! This program will display the time table of any positive number you input "<<endl;
cout<<"        (********************Only positive************************)                "<<endl;
cout<<"                                                                                   "<<endl;
cout<<"==================================================================================="<<endl;
cout<<"             >Type '1' to display the time table of your choice                    "<<endl;
cout<<"             >Type '0' to exit if desired                                          "<<endl;
cout<<"==================================================================================="<<endl;

cin>>choice;

switch(choice){

 case '1':

   //this case calls GetNumber
   GetNumber(num);

   /* if the number inputted is a negative number the program will inform the user and redirect them to the main menu. if not the function
   DisplayTimeTable */

   if(num== abs(num)){
    DisplayTimeTable(num);
}
else {

    system("cls");
    cout<<"The number you inputed is a negative number!!! \n"<<endl;
    system("pause");
}


     break;
 case '0':
    system("cls");
    cout<<"Goodbye ! \n\n";
    break;

 default:
    cout<<"Invalid option \n";
    system("pause");
}

}while(choice!='0');

return 0;
}

//this functions prompts the user to type in a number and assigns that number to the memory location of num
void GetNumber(int &num){

system("cls");
cout<<"Please type in the number you would like to know the time table of"<<endl;
cin>>num;


}


// this function displays the time table
void DisplayTimeTable(int number){


system("cls");
cout<<" You chose "<<number<<endl;
cout<<"==================="<<endl;

for(int x=1; x<13; x++){

    cout<<number<<" x "<<x<<" = "<<(number*x)<<endl;
}
cout<<"==================="<<endl;

system("pause");

}

