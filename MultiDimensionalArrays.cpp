#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

const int Rows=3;
const int Columns=5;


void SearchArray(string code){

system("cls");
int row=0, column=0;
string Assignment1="", Assignment2="";
bool found;

string Class_Info[Rows][Columns]={{"CPTR150","MATH182","SPAN171","CHEM107","ENGL125"},{"Coding Lab","Integration","Vocabulary","Atoms","Letter Writing"}
                                  ,{"Final Project","Differentiation","Verbs","Elements","Short Stories"}};


 for(int x=0; x<Columns; x++){

     if(Class_Info[0][x]==code){

        column=x;
        found=true;
        break;
     }

     else
        found=false;

    }

if(found==true){

cout<<"Course code: "<<Class_Info[0][column];

for(int x=1; x<Rows; x++)
 cout<<"\nAssignment "<<x<<": "<<Class_Info[x][column];

}
else
    cout<<"Course not found";
    exit(2);




}








int main(){

string code="";


cout<<"Please Enter the Course Code you would like to search (In all caps)"<<endl;
cin>>code;


SearchArray(code);

}
