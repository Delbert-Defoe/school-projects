#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

//this function reads data from the file "appointments.txt" and assigns the data into arrays passed into it from main
void readDataFromFile(string studentNames[], string Id[], string Contact[], string Date[], string Time[], const int Array_Size){

char Filename[]="appointments.txt";


//object of ifstream
ifstream readFile;

//opening file
readFile.open(Filename);

//testing whether the file is opened or not
if(!readFile){

    cout<<"Error: File was not opened......Exiting program"<<endl;
    exit(2);
}

else{
//if the file is open, this code will loop until every array index has data assigned to it
    while(!readFile.eof()){
       for(int x=0; x<Array_Size; x++){
        getline(readFile, studentNames[x],'#');
        getline(readFile, Id[x],'#');
        getline(readFile, Contact[x],'#');
        getline(readFile, Date[x],'#');
        getline(readFile, Time[x]);


       }
       if(readFile.eof())
        break;
    }
}
}

//this function displays the data
void DisplayData(string studentNames[], string Id[], string Contact[], string Date[], string Time[], const int Array_Size){

for(int x=0; x<Array_Size; x++){

    cout<<"------------------------------"<<endl;
    cout<<"Appointment "<<x+1<<":"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Student name: "<<studentNames[x]<<endl;
    cout<<"Id #: "<<Id[x]<<endl;
    cout<<"Contact #: " <<Contact[x]<<endl;
    cout<<"Date: "<<Date[x]<<endl;
    cout<<"Time: "<<Time[x]<<endl;
    cout<<"------------------------------\n"<<endl;



}



}



//main is calling both functions and passing the data into them
int main(){

const int Array_Size=5;
string studentNames[Array_Size]={" "}, Id[Array_Size]={" "}, Contact[Array_Size]={" "}, Date[Array_Size]={" "}, Time[Array_Size]={" "};

readDataFromFile(studentNames, Id, Contact, Date, Time, Array_Size);
DisplayData(studentNames, Id, Contact, Date, Time, Array_Size);




}
