/*
Program Name: Book Keeping
Purpose: Record and Display book information
Programmer Name: Delbert Defoe
Date Created: 03/04/2020
*/

#include <iostream>
#include <windows.h>


using namespace std;

//These two variables are global, in order to make their usage simpler
const int ArraySize= 100;

//This struct is book data. It contains all the data needed to store the books
struct Book_Data{

     string Title;
     string Author;
     string Date_Published;
     string ISBN;
   };


//class definition
class Books{

private:
//the places where the books are being saved and printed are not to be accessed by the user of from main
//neither is the storage location...
//for this reason they are private
   int index;
   Book_Data AllBooks[ArraySize];

public:

//the constructor and various functions are to be called directly from main
   Books();
   void setBookData(string, string, string, string);
   void printBookDetails();




};

int main(){

//main will act as a main menu which will either allow a user to add a book, display all books,
char option=' ';
//these strings will store the needed data to pass into the function
string Title,Author,Date_Published,ISBN;

//creating an object of the class
Books NewBook;

//Do loop - actual menu
do{
cout<<"-----------------"<<endl;
cout<<"Choose Option 1-3"<<endl;
cout<<"-----------------"<<endl;
cout<<"1. Add Book \n"
    <<"2. Display Books\n"
    <<"3. Exit"          <<endl;
cout<<"-----------------"<<endl;
cin>>option;

switch(option){

//this case allows the using to enter information, then passes the information  into the setBookData function
case '1':
    system("cls");
    cin.get();
    cout<<"Title of the book: ";
    getline(cin, Title);

    cout<<"\nName of the author: ";
    getline(cin, Author);

    cout<<"\nDate Published (DD/MM/YYYY): ";
    getline(cin, Date_Published);

    cout<<"\nISBN#: ";
    getline(cin, ISBN);

    NewBook.setBookData(Title, Author, Date_Published, ISBN);

    break;

//This case prints the saved books
case '2':
    NewBook.printBookDetails();
    break;

//This case closes the program
case '3':
    cout<<"GOODBYE!"<<endl;
    break;

default:
    cout<<"Invalid Input!"<<endl;
    Sleep(2000);
    system("cls");
    break;
}
}while(option!='3');

return 0;
}

//Constructor
Books::Books(){
  index =0;

}

//this function take the given data and saves it to a Book_Data Array
void Books::setBookData(string Title, string Author, string Date_Published, string ISBN){
system("cls");


   AllBooks[index].Title = Title;
   AllBooks[index].Author = Author;
   AllBooks[index].Date_Published = Date_Published;
   AllBooks[index].ISBN = ISBN;

//this line increments the index so that the data will always save in the next index
   index++;

}

//This function displays the data by using a for loop, and will stop once the index matches the last index saved from setBookData
void Books::printBookDetails(){

system("cls");
int LastEntry= index;

for(int index=0; index<ArraySize; index++){

if (index==LastEntry)
    break;

  cout<<"Title: "<<AllBooks[index].Title;
  cout<<"\nAuthor: "<<AllBooks[index].Author;
  cout<<"\nDate Published: "<<AllBooks[index].Date_Published;
  cout<<"\nISBN#: "<<AllBooks[index].ISBN<<"\n\n";

}
if(LastEntry==0)
    cout<<"No Books Found...."<<endl;
system("pause");
system("cls");
}
