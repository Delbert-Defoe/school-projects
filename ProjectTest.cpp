/*
you have to find a way to get the last index
try saving it to the file
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


const int ArraySize=50;

char filename[] = "AllAssignments.txt";

 struct Assignment{

  string Course_code;
  string Name;
  string Description;
  string Due_Date;
  string Assignment_Number;
  };



class Manager{

public:

    Manager();
    int menu();
    void readEntireFile(int &);
    void addAssignment(int &);
    void updateAssignment();
    void removeAssignment(int &);
    void displayALl(int &);
    void displaySpecific();



private:
  Assignment newAssignment[ArraySize];
  char option;
  int index;
  int lastIndex;
  string coursecode;
  string name;
  string description;
  string duedate;
  int assignmentNumber;

  ifstream readFile;
  ofstream writeFile;

};

int main() {

Manager UserEvent;
int ex_it=0;
do{
ex_it=UserEvent.menu();
}while(ex_it!='6');

return 0;
}



Manager::Manager(){
 lastIndex=0;
}

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

case '6':
    cout<<"Closing Program Goodbye....."<<endl;
    break;

default :
    cout<<"invalid input"<<endl;
    break;
}

return option;
}

void Manager::readEntireFile(int &lastIndex){


readFile.open(filename);

if(!readFile){
    cout<<"oops....Error opening file!....Returning to main menu"<<endl;
    Sleep(5000);
    return;
}

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

    if(readFile.eof()){
//  lastIndex-=1;
        break;
    }

 x++;
}
}


readFile.close();
}

void Manager::addAssignment(int &lastIndex){

system("cls");
cout<<"Please provide the following details: \n\n\n";

cout<<"Course Code (All CAPS): ";
cin>> coursecode;

cin.ignore();

cout<<"\nName of Assignment: ";
getline(cin, name);

cout<<"\nDescription: ";
getline(cin, description);

cout<<"\nDue Date (dd/mm/yyyy): ";
cin>> duedate;

writeFile.open(filename, ios::app);
writeFile.close();

readEntireFile(lastIndex);

writeFile.open(filename, ios::app);

if(!writeFile){
    cout<<"oops....Error opening file!....Returning to main menu"<<endl;
    Sleep(5000);
    return;
}

else{
    assignmentNumber=lastIndex+1;

    writeFile<<"%"<<assignmentNumber<<"$"<<coursecode<<"#"<<name<<"#"<<description<<"#"<<duedate<<"\n";
    }

writeFile.close();

}




void Manager::removeAssignment(int &lastIndex) {

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

cout<<"Which Assignment would you like to delete? (Use #)"<<endl;
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

cout<<"Are you sure you want to delete this assignment? (1=Yes/2=No)"<<endl;
cin>>decision;


switch(decision){

case '1':

writeFile.open(filename);


//If the assignment chosen is the first assignment the program will skip it and continue as normal
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

//if(y==lastIndex-1)
//    break;

}while(y!=Asgnmt_Index);

//when the assignment is encountered, the next assignment is given its number using int Y, however the index of the next assignment will remain unchanged
 for(int z=y+1; y<lastIndex; z++){
    writeFile<<"%"<<y+1<<"$"<<newAssignment[z].Course_code<<"#"<<newAssignment[z].Name<<"#"<<newAssignment[z].Description<<"#"<<newAssignment[z].Due_Date<<"\n";
 y++;
 if(y==lastIndex-1)
    break;
 }
}
cout<<"Assignment deleted.... Updated Assignments will show on restart..."<<endl;
Sleep(3000);
writeFile.close();
    break;

case '2':
    break;

default:
    cout<<"Invalid Option"<<endl;
    break;

}

}



void Manager::updateAssignment() {

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
writeFile.close();
}

void Manager::displayALl(int &lastIndex) {
system("cls");

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

void Manager::displaySpecific() {


cout<<"Which course would you like to view courses for?"<<endl;
cin>>coursecode;

system("cls");

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



