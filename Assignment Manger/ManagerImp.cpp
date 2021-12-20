#include "Manager.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

/*
Through out the program, variables like 'x' and 'y'
will be used in multiple areas but will only have local scopes
they are used as working variables, and will only be used for local
logical operations, and record saving.
*/
using namespace std;

//default constructor
Manager::Manager(){
 lastIndex=0;
}

//This is the looping menu called from main, which calls the other functions in the class
int Manager::menu(){
system("Title Main Menu");
system("cls");

std::cout<<"=============================="<<endl;
std::cout<<std::setw(13)<<"Menu"<<endl;
std::cout<<"=============================="<<endl;
     cout<<"1. Add Assignment"<<endl;
     cout<<"2. Update Assignment"<<endl;
     cout<<"3. Delete Assignment"<<endl;
     cout<<"4. Display All Assignments"<<endl;
     cout<<"5. Display Specific Assignment"<<endl;
     cout<<"6. Exit"<<endl;
     cout<<"=============================="<<endl;
     cin>>option;

//This switch case chooses the corresponding function to the number chosen
switch (option){

case '1':
    addAssignment(lastIndex);
    break;

case '2':
    readEntireFile(lastIndex);
    updateAssignment();
    break;

case '3':
    readEntireFile(lastIndex);
    removeAssignment(lastIndex);
    break;

case '4':
    readEntireFile(lastIndex);
    displayALl(lastIndex);
    break;

case '5':
    readEntireFile(lastIndex);
    displaySpecific();
    break;

//Case 6 is the exit message, as when the function returns 6 the program will end
case '6':
    cout<<"Closing Program Goodbye....."<<endl;
    break;

default :
    cout<<"invalid input"<<endl;
    break;
}

return option;
}

//This function reads the entire file before any other function is called, in order for the logic to work correctly, and in sync
void Manager::readEntireFile(int &lastIndex){

//readFile in this case opens the file
readFile.open(filename);

//This if else statements checks for a file error
if(!readFile){
    cout<<"oops....Error opening file!....Returning to main menu"<<endl;
    Sleep(5000);
    return;
}
//if the file is opened, It is read through a special format, and the data is saved into the respective locations
else{

int x=0;
while(!readFile.eof()){


    readFile.get();
    getline(readFile, newAssignment[x].Assignment_Number, '$');
    getline(readFile, newAssignment[x].Course_code, '#');
    getline(readFile, newAssignment[x].Name, '#');
    getline(readFile, newAssignment[x].Description, '#');
    getline(readFile, newAssignment[x].Due_Date);

    stringstream(newAssignment[x].Assignment_Number)>>lastIndex;

    //this if statement prevents the last bit of data from repeating
    if(readFile.eof()){

        break;
    }
//x is incremented so that the next array is populated
 x++;
}
}

//closing the file to prevent any errors in the other functions
readFile.close();
}

//This function allows the user to add an assignment
void Manager::addAssignment(int &lastIndex){

system("Title Add New Assignment");
system("cls");
cout<<"Please provide the following details: \n\n";

cout<<"Course Code (All CAPS): ";
cin>> coursecode;

cin.ignore();

cout<<"\nName of Assignment: ";
getline(cin, name);

cout<<"\nDescription: ";
getline(cin, description);

cout<<"\nDue Date (dd/mm/yyyy): ";
cin>> duedate;

/*
These few lines of code are a fail-safe. The function which reads the entire file will not be able to create the file
these few lines create the file if it does not exists, then calls the readEntireFile() function to retrieve much needed information, before
writing
*/
writeFile.open(filename, ios::app);
writeFile.close();

readEntireFile(lastIndex);

//seeing that readEntireFile() closes the file, it must be reopened for writing.
writeFile.open(filename, ios::app);

if(!writeFile){
    cout<<"oops....Error opening file!....Returning to main menu"<<endl;
    Sleep(5000);
    return;
}

//if there is no file error, the assignment information is printed in a specific format
else{
    assignmentNumber=lastIndex+1;

    writeFile<<"%"<<assignmentNumber<<"$"<<coursecode<<"#"<<name<<"#"<<description<<"#"<<duedate<<"\n";
    }
//file is again closed to prevent any corruption or file errors
writeFile.close();

}

//This function allows you to remove an existing assignment
void Manager::removeAssignment(int &lastIndex) {

system("Title Remove An Assignment");

//All assignments are printed to provide clear options to the user
for (int x=0; x<ArraySize; x++){

 if(lastIndex==x)
    break;

    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[x].Assignment_Number<<":"<<" "<<newAssignment[x].Name;
    cout<<"\nCourse Code: "<<newAssignment[x].Course_code;
    cout<<"\nDescription: "<<newAssignment[x].Description;
    cout<<"\nDue Date: "<<newAssignment[x].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;


}
//the user is able to choose the assignment he wants by choosing the assignment number.
cout<<"Which Assignment would you like to delete? (Use #)"<<endl;
cin>>assignmentNumber;

system("cls");

int Asgnmt_Index= assignmentNumber-1;
char decision=' ';

//the assignment chosen is displayed, as the user is asked for confirmation
    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[Asgnmt_Index].Assignment_Number<<":"<<" "<<newAssignment[Asgnmt_Index].Name;
    cout<<"\nCourse Code: "<<newAssignment[Asgnmt_Index].Course_code;
    cout<<"\nDescription: "<<newAssignment[Asgnmt_Index].Description;
    cout<<"\nDue Date: "<<newAssignment[Asgnmt_Index].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;

cout<<"Are you sure you want to delete this assignment? (1=Yes/2=No)"<<endl;
cin>>decision;

//This switch case decides whether to continue with the function or return to the menu
switch(decision){

case '1':

//The is opened in output mode, so data already saved will be overwritten
writeFile.open(filename);


//If the assignment chosen is the first assignment the program will skip it and continue writing as normal
if(Asgnmt_Index==0){
    for(int x=1; x<lastIndex; x++){
    if(x==lastIndex-1)
      break;

    writeFile<<"%"<<x<<"$"<<newAssignment[x].Course_code<<"#"<<newAssignment[x].Name<<"#"<<newAssignment[x].Description<<"#"<<newAssignment[x].Due_Date<<"\n";
    }
}

//If the assignment chosen is the last assignment the program will reprint the information as normal but not the last one
else if(Asgnmt_Index==lastIndex-1){

  for(int x=1; x<lastIndex-1; x++){
    if(x==lastIndex-1)
    break;

    writeFile<<"%"<<x<<"$"<<newAssignment[x].Course_code<<"#"<<newAssignment[x].Name<<"#"<<newAssignment[x].Description<<"#"<<newAssignment[x].Due_Date<<"\n";
    }

}
//If this is not true, the program will continue until is reaches the given assignment
else{

//When the program arrives to the given assignment number, the next assignment will need that number, Y will store it to write later on
int y=0;

//This do-loop will print the information back into the file until the assignment is encountered
do{
    writeFile<<"%"<<y+1<<"$"<<newAssignment[y].Course_code<<"#"<<newAssignment[y].Name<<"#"<<newAssignment[y].Description<<"#"<<newAssignment[y].Due_Date<<"\n";
y++;

}while(y!=Asgnmt_Index);

//when the assignment is encountered, the next assignment is given its number using int Y, however the index of the next assignment will remain unchanged
 for(int z=y+1; y<lastIndex; z++){
    writeFile<<"%"<<y+1<<"$"<<newAssignment[z].Course_code<<"#"<<newAssignment[z].Name<<"#"<<newAssignment[z].Description<<"#"<<newAssignment[z].Due_Date<<"\n";
 y++;
 if(y==lastIndex-1)
    break;
 }
}
//user is notified that the assignment was deleted
cout<<"Assignment deleted.... Updated Assignments will show on restart..."<<endl;
Sleep(3000);
writeFile.close();
    break;

//this case returns to the menu
case '2':
    break;

default:
    cout<<"Invalid Option"<<endl;
    break;

}

}


//This function allows the user to make changes to an already saved assignment
void Manager::updateAssignment() {

system("Title Update An Assignment");

//Displays all assignments
for (int x=0; x<ArraySize; x++){

 if(lastIndex==x)
    break;

    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[x].Assignment_Number<<":"<<" "<<newAssignment[x].Name;
    cout<<"\nCourse Code: "<<newAssignment[x].Course_code;
    cout<<"\nDescription: "<<newAssignment[x].Description;
    cout<<"\nDue Date: "<<newAssignment[x].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;


}

cout<<"Which Assignment would you like to Update? (Use #)"<<endl;
cin>>assignmentNumber;

system("cls");

int Asgnmt_Index= assignmentNumber-1;
char decision=' ';

    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[Asgnmt_Index].Assignment_Number<<":"<<" "<<newAssignment[Asgnmt_Index].Name;
    cout<<"\nCourse Code: "<<newAssignment[Asgnmt_Index].Course_code;
    cout<<"\nDescription: "<<newAssignment[Asgnmt_Index].Description;
    cout<<"\nDue Date: "<<newAssignment[Asgnmt_Index].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;

cout<<"Are you sure you want to update this assignment? (1=Yes/2=No)"<<endl;
cin>>decision;

switch(decision){

case '1':
system("cls");
cout<<"Please provide the following details: \n\n\n";

cout<<"Course Code (All CAPS): ";
cin>> newAssignment[Asgnmt_Index].Course_code;

cin.ignore();

cout<<"\nName of Assignment: ";
getline(cin, newAssignment[Asgnmt_Index].Name);

cout<<"\nDescription: ";
getline(cin, newAssignment[Asgnmt_Index].Description);

cout<<"\nDue Date (dd/mm/yyyy): ";
cin>> newAssignment[Asgnmt_Index].Due_Date;

writeFile.open(filename);

//If the assignment chosen is the first assignment, it will be written first, then a for loop will write the data that follows it
if(Asgnmt_Index==0){

    writeFile<<"%"<<newAssignment[Asgnmt_Index].Assignment_Number<<"$"<<newAssignment[Asgnmt_Index].Course_code<<"#"<<newAssignment[Asgnmt_Index].Name<<"#"<<newAssignment[Asgnmt_Index].Description<<"#"<<newAssignment[Asgnmt_Index].Due_Date<<"\n";

    for(int x=1; x<lastIndex-1; x++){

        writeFile<<"%"<<x+1<<"$"<<newAssignment[x].Course_code<<"#"<<newAssignment[x].Name<<"#"<<newAssignment[x].Description<<"#"<<newAssignment[x].Due_Date<<"\n";

    }
}

//If the assignment chosen is the last assignment, the data before it will be written and then the last assignment will be updated
else if(Asgnmt_Index==lastIndex-1){
    int x=0;
do{
        writeFile<<"%"<<x+1<<"$"<<newAssignment[x].Course_code<<"#"<<newAssignment[x].Name<<"#"<<newAssignment[x].Description<<"#"<<newAssignment[x].Due_Date<<"\n";
        x++;
}while(x!=Asgnmt_Index);

        writeFile<<"%"<<newAssignment[Asgnmt_Index].Assignment_Number<<"$"<<newAssignment[Asgnmt_Index].Course_code<<"#"<<newAssignment[Asgnmt_Index].Name<<"#"<<newAssignment[Asgnmt_Index].Description<<"#"<<newAssignment[Asgnmt_Index].Due_Date<<"\n";

}

//if the assignment chosen is a random assignment between the first and last, the program will keep checking for the assignment.
//If it is not the assignment, it will continue writing as normal, and if it is, it will update that assignment.
//When the assignment is updated, it will continue writing the data after it
else{
for(int x=0; x<lastIndex; x++){

    if(x==Asgnmt_Index){
            writeFile<<"%"<<newAssignment[Asgnmt_Index].Assignment_Number<<"$"<<newAssignment[Asgnmt_Index].Course_code<<"#"<<newAssignment[Asgnmt_Index].Name<<"#"<<newAssignment[Asgnmt_Index].Description<<"#"<<newAssignment[Asgnmt_Index].Due_Date<<"\n";
    x++;
    }
        writeFile<<"%"<<x+1<<"$"<<newAssignment[x].Course_code<<"#"<<newAssignment[x].Name<<"#"<<newAssignment[x].Description<<"#"<<newAssignment[x].Due_Date<<"\n";

}
}

case '2':
    break;

default:
    cout<<"invalid input"<<endl;
    break;
}
writeFile.close();
}

//this function displays all saved assignments
void Manager::displayALl(int &lastIndex) {

system("Title All Assignments");

system("cls");

//if there are no assignments, the program will notify the user, and return to the menu
if(lastIndex==0){
    cout<<"No Assignments saved"<<endl;
    system("pause");
    return;
    }

cout<<"Displaying All Assignments....."<<endl;
Sleep(1000);

system("cls");

for (int x=0; x<ArraySize; x++){

 if(lastIndex==x)
    break;

    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[x].Assignment_Number<<":"<<" "<<newAssignment[x].Name;
    cout<<"\nCourse Code: "<<newAssignment[x].Course_code;
    cout<<"\nDescription: "<<newAssignment[x].Description;
    cout<<"\nDue Date: "<<newAssignment[x].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;


}
system("pause");

readFile.close();
}
//This function displays all assignments from the same course
void Manager::displaySpecific() {

system("Title Course Assignments");

cout<<"Which course would you like to view courses for?"<<endl;
cin>>coursecode;

system("cls");
//this for loop goes through all the saved assignments and prints those with 'coursecode' as their Course code
for(int x=0; x<lastIndex; x++){
    if(newAssignment[x].Course_code==coursecode){

    cout<<"-----------------------------------------"<<endl;
    cout<<"Assignment "<<newAssignment[x].Assignment_Number<<":"<<" "<<newAssignment[x].Name;
    cout<<"\nCourse Code: "<<newAssignment[x].Course_code;
    cout<<"\nDescription: "<<newAssignment[x].Description;
    cout<<"\nDue Date: "<<newAssignment[x].Due_Date<<endl;
    cout<<"-----------------------------------------"<<endl;

    }


}



system("pause");
}

