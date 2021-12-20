#include <iostream>
#include <windows.h>

using namespace std;

int main() {

system("Title USC Cafe");

//price will store a new value every time the user inputs a value for add item. total will add all together.
  int  no_of_items=0;
  float total=0.0, price=0.0;
//option will store the value inputted to choose the correct case to carry out based on that input
  char option =' ';

   cout<<" Welcome To USC Cafe ";
   system("pause");
 do {


//the page will be cleared then the menu will be shown where the user is prompted to seek help first, but does not have to
    system("cls");

    cout<<" ================== "<<endl;
    cout<<"    1. Add Item     "<<endl;
    cout<<"    2. Help (Please Read first)"<<endl;
    cout<<"    3. Exit Program "<<endl;
    cout<<" ================== "<<endl;
//the program will accept input and store it in option to know which action to take
    cin>>option;

    switch(option) {
//the First option "Add Item" Will allow the user to input an infinite amount of items, and when 0 is inputted it will total the items and decide whether a discount is appropriate or not

      case '1':
//this do statement will accept data until the user inputs 0
        do {
         system("cls");
         cout<<"Please input the price of an item, *Typing 0 will exit the option, and/or display your total*."<<endl;
         cin>> price;
//this if statement adds the inputs to the total and adds a count to the number of items inputted as long as the number is greater than 0
           if(price>0){
              total+=price;
              no_of_items++;

           }

        } while(price!=0);

/*these series of if else statements checks the to see if the total is greater than o then checks the number of items to see whether a discount is applicable or not
  if it is applicable, 10% of the total is removed from the total and the total is displayed. If not, the total is displayed */

          if (total!=0){
            if(no_of_items>=10){
                total-= 0.1*total;

                cout<<"You bought 10 or more items which qualified you for a 10% discount. Your total is: $"<<total<<endl;
                system("pause");
                total=0;
            }
            else{
            cout<<"The total of all your items is : $"<<total<<endl;
            system("pause");
            total=0;
            }
           break;

         }
         else
         break;


//this option gives information about the program.
      case '2' :

         system("cls");
         cout<< "\n Please type 1 to start inputting the price of an item.";
         cout<< "\n When you are done adding items, or if you do not wish to input items anymore, type 0.";
         cout<< "\n If you have not inputed any price it will lead you back to the home screen. If you have inputed items, the program";
         cout<<"\n will display your total."<<endl;
         cout<<"\n   "<<endl;
         system("pause");
         break;

//the third option is the exit from the entire program

      case '3':

         break;

//if the desired or required data is inputed this message will display
      default:
        cout<<"you have not chosen a valid option. Please choose option 2 if you need any help"<<endl;
        Sleep(5000);

    }


 }while(option!='3');

//this is the farewell message.
 system("cls");
 cout<< " Do shop again!!!"<<endl;
 system("pause");
 return 0;
}
/*
This Program was made by Delbert Defoe
Id : 2019081103
*/
