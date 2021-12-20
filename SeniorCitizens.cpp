//value returning function
#include <iostream>
#include <windows.h>

using namespace std;


//proto-typing the value-returning function
int SeniorAge(int, int);

//main function
int main() {
system("Title Age Calculator");

string Name=" ";
char choice=' ';
int YearOfBirth=0, CurrentYear=0;

//Welcome Screen will accept the user's name

cout<<" ============================================================================= "<<endl;
cout<<" Hello And Welcome to the age Calculator :) Please Enter your name to continue "<<endl;
cout<<" ============================================================================= "<<endl;
cin>>Name;

system("cls");



do {
//this part of the menu is now personalized making it easier to understand. It will allow the user a chance to exit
    cout<<"Hi "<<Name<<" !! Type '1' to calculate your age or '2' to exit!"<<endl;
    cin>>choice;
    system("cls");

//this switch structure will repeat the calculations until 2 is selected
    switch(choice){

case '1':
//in the case that the user chooses 1, the program will ask them for their year of birth, and the function "SeniorAge" Will be called
    cout<<" Please Type in the year you were born below "<<endl;
    cin>>YearOfBirth;
    cout<<" Please input the current year below "<<endl;
    cin>>CurrentYear;
    system("cls");

    SeniorAge(YearOfBirth, CurrentYear);

//the function will calculate the age of the person and display it with a friendly message. After this the program will return to the menu
    cout<<" Yeepee "<<Name<<" You are "<<SeniorAge(YearOfBirth,CurrentYear)<<" Years old !!! ;) "<<"You look 30 years younger!!"<<endl;
    cout<<"\n"<<endl;
    system("pause");
    system("cls");

    break;


case '2':
//the second case will show a farewell message and exit the program
    cout<<" Ok!! bye "<<Name<<" Do try again next Time!!"<<endl;
    break;

default:
    cout<<" The program is not able to understand what you typed in :("<<endl;
    system("pause");
    system("cls");
    }


}while(choice!='2');




//return value
return 0;
}

//Function responsible for calculating age of the user
 int SeniorAge(int YearOfBirth, int CurrentYear){

//declaration of current year as a constant

 int age= CurrentYear-YearOfBirth;

//return value
 return age;
 }
