#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <string>


using namespace std;

int main(){


    string firstname = " ", lastname = " ",idNumber =" ", quizOne =" ", quizTwo=" ", quizThree =" " ;
    char space=' ';
    int x=1, Total=0, quiz1=0, quiz2=0, quiz3=0;

fstream readFile;

readFile.open("C:\\Users\\CheeZee\\Downloads\\scores.txt");

if (!readFile){

    cout<<"**FILE NOT OPENED!**"<<endl;
    cout<<"  EXITING PROGRAM!   "<<endl;

    exit(1);
}
else{

while(!readFile.fail()){



    getline(readFile, idNumber, ';');
    getline(readFile, lastname, ';');
    getline(readFile, firstname, ';');
    readFile>>quizOne;
    readFile>>quizTwo;
    readFile>>quizThree;
    readFile.get();

    if(readFile.eof())
        break;


    stringstream(quizOne)>>quiz1;
    stringstream(quizTwo)>>quiz2;
    stringstream(quizThree)>>quiz3;



    Total= quiz1+quiz2+quiz3;


    cout<<"-------------------------"<<endl;
    cout<<"        Student"<<x<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Name: "<<firstname<<" "<<lastname<<endl;
    cout<<"ID: "<<idNumber<<endl;
    cout<<"Quiz 1: "<<quiz1<<endl;
    cout<<"Quiz 2: "<<quiz2<<endl;
    cout<<"Quiz 3: "<<quiz3<<endl;
    cout<<"Total Score: "<<Total<<endl;
    cout<<"-------------------------"<<endl;
    cout<<endl;


    x++;
    Total=0;



}







}
readFile.close();
return 0;
}
