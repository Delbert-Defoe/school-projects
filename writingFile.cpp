#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void UseData();

int main(){

ifstream readFile; //create an object of ifstream
string data= "";

readFile.open("C:\\Users\\CheeZee\\Documents\\Hello.txt"); //readFile opens the file

if(!readFile) { //check to to see if the file is open

 cout<<"\a File not opened"<<endl;
 cout<<"Terminating program"<<endl;

 exit(1);

}

else{
    while(!readFile.eof()){


    getline(readFile, data);


    cout<<data<<endl;


    }
    system("pause");
    system("cls");

    UseData();
}

return 0;
}

 void UseData() {

 fstream useFile;


 string line="Age", age= " ";

 useFile.open("C:\\Users\\CheeZee\\Documents\\Hello.txt");

 if(!useFile){

    cout<<"File Error!"<<endl;
    exit(1);
 }

 else{
    while(!useFile.eof()){

        if(line=="Age"){

            getline(useFile, age);
            cout<<age;
            break;
        }

    }


 }

 }
