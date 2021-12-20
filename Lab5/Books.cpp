#include "Books.h"
#include <iostream>
#include <windows.h>

using namespace std;


Books::Books(){

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
