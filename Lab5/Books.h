#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>

using namespace std;



struct Book_Data{

     string Title;
     string Author;
     string Date_Published;
     string ISBN;
   };

const int ArraySize= 100;

//This struct is book data. It contains all the data needed to store the books

class Books{

private:
//the places where the books are being saved and printed are not to be accessed by the user of from main
//neither is the storage location...
//for this reason they are private
   int index;
   Book_Data AllBooks[ArraySize];

public:


   Books();
    //Default constructor

   void setBookData(string, string, string, string);
    //This functions gets all the details needed from main passed in as parameters
    //These parameters are saved into the "AllBooks" Struct Array


   void printBookDetails();
   //This function prints all the books that are saved


};
#endif // BOOKS_H
