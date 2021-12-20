#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {

    string data= " ";

fstream readFile;

readFile.open("C:\\Users\\CheeZee\\Downloads\\profits.html");

if (!readFile){

    cout<<"File did not open"<<endl;
    system("pause");
    exit(1);

}

 else {

    while(!readFile.eof()){

      getline(readFile, data);
      cout<<data<<endl;
    }
