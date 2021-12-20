#include <iostream>
#include <windows.h>
#include <cctype>
#include <fstream>

using namespace std;


//initializing the struct
struct StudentData {

string name;
string studentid;
string contact;
string date;
string time;

};

//this function captures data from appointments.txt and reads them into the struct variables
void readDataFromFile(StudentData student[], const int Array_Size){

char Filename[]="appointments.txt";


//object of ifstream
ifstream readFile;

//opening file
readFile.open(Filename);

if(!readFile){

    cout<<"Error: File was not opened......Exiting program"<<endl;
    exit(2);
}

else{


//if the file is opened, the program loops, reading the file in a specific format, and saving the respective data
    while(!readFile.eof()){

//this for loops increments the variable 'x' which is used as an index for the struct array
       for(int x=0; x<Array_Size; x++){
        getline(readFile, student[x].name,'#');
        getline(readFile, student[x].studentid,'#');
        getline(readFile, student[x].contact,'#');
        getline(readFile, student[x].date,'#');
        getline(readFile, student[x].time);


       }
       if(readFile.eof())
        break;
    }


}
}

//this function displays the data by using a for loop
void DisplayData(StudentData student[],const int Array_Size){

for(int x=0; x<Array_Size; x++){

    cout<<"------------------------------"<<endl;
    cout<<"Appointment "<<x+1<<":"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Student name: "<<student[x].name<<endl;
    cout<<"Id #: "<<student[x].studentid<<endl;
    cout<<"Contact #: " <<student[x].contact<<endl;
    cout<<"Date: "<<student[x].date<<endl;
    cout<<"Time: "<<student[x].time<<endl;
    cout<<"------------------------------\n"<<endl;

}

}

//int main is used to call the function and pass data to them.
int main(){

const int Array_Size=5;


StudentData student[Array_Size];


readDataFromFile(student, Array_Size);
DisplayData(student, Array_Size);

return 0;
}
