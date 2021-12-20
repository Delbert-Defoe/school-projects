//including directories
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

char filename[]="C:\\Users\\CheeZee\\Documents\\AsgmntMangr";

//This function when called will prompt the user to enter the required data then write the data to the file in a specific format
void AddAssignment(){

//Variables will store user input
string Code=" ", AsgnmtName= " ", DueDate=" ";

system("Title Add Assignment");

cout<<"Course Code:"<<endl;
cin>>Code;

cin.ignore();

cout<<"\nAssignment Name:"<<endl;
getline(cin, AsgnmtName);

cout<<"\nDate Due:"<<endl;
getline(cin, DueDate);

//creating an object of ofstream
ofstream WriteFile;

//the file is opened in append mode so that data will be added and not overwritten
WriteFile.open(filename, ios::app);

//this block of code tests to see if the file was opened. If the file is not opened, the user is notified and the program terminates.
if(!WriteFile){
    system("cls");
    cout<<"ERROR: There Was A Problem With Opening The File... Exiting Program"<<endl;
    exit(3);
}

//if the file is opened, the else statement writes the data into the file in the following format
else{

 WriteFile<<Code<<"#"<<AsgnmtName<<"#"<<DueDate<<"\n";

}
//the file is closed
WriteFile.close();
}


//this function displays the data inputed into the file
void DisplayAssignment(){

system("Title Display Assignment");
//these variables capture data from the file in order to display them in an orderly fashion
    string code=" ", Assignment=" ", date=" ";

//creating an object of ifstream
ifstream readFile;

//opening the file in input mode, so that data can be read throughout the entire file
readFile.open(filename,ios::in);

//if the file is not opened, the user is notified and the program terminates
if(!readFile){

    cout<<"ERROR: There Was A Problem With Opening The File... Exiting Program"<<endl;
    exit(3);

}

//if the file is opened, the else statement displays the data
else{

//this output is outside the while statement because it only needs to display once
cout<<"---------------------------------------------------------------------------------"<<endl;
std::cout<<std::setw(10)<<"Course"<<std::setw(10)<<"|"<<std::setw(25)<<"Assignment"<<std::setw(14)<<"|"<<std::setw(15)<<"Due Date"<<std::setw(7)<<"|"<<endl;
cout<<"---------------------------------------------------------------------------------"<<endl;

//this while statement is tasked with reading the file until the end
while(!readFile.eof()){

//these few lines of code reads the file in the specified format and assigns data accordingly
    getline(readFile, code, '#');
    getline(readFile, Assignment, '#');
    getline(readFile, date);

//these lines of code checks one more time for the end of the file, so that the last line of data is not doubled
    if(readFile.eof())
        break;

//this line of code displays the data in a formatted manner
std::cout<<std::setw(19)<<code<<"|"<<std::setw(38)<<Assignment<<"|"<<std::setw(21)<<date<<"|"<<endl;


}
//this text only needs to be outputted ones
cout<<"---------------------------------------------------------------------------------"<<endl;

system("Pause");
}
//the file is closed
readFile.close();
}




int main(){

char option=' ';

system("Title Assignment Manager");

do{
system("cls");

//this block of code displays the menu
cout<<"----------------------"<<endl;
cout<<"Choose a number 1-3"<<endl;
cout<<"----------------------"<<endl;
cout<<"1. Add New Assignments"<<endl;
cout<<"2. Display Assignments"<<endl;
cout<<"3. Exit"<<endl;
cout<<"----------------------"<<endl;
cin>>option;

//this switch takes the number inputted and calls the relevant function
switch(option){

 case '1':
     system("cls");
     AddAssignment();
     break;

 case '2':
     system("cls");
     DisplayAssignment();
    break;

 case '3':
     system("cls");
    cout<<"**GOODBYE!**"<<endl;
    Sleep(1000);
    break;

 default :
    cout<<"Invalid input"<<endl;
    system("pause");
    break;


}
}while(option!='3');

}
