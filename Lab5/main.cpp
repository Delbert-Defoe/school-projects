#include "Books.h"
#include <iostream>
#include <windows.h>

using namespace std;


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
    cout<<"GOODBYyE!"<<endl;
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
