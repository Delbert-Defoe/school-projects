#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {

 ifstream readFile; //create an object of "ifstream"
 int num =0, sum =0;

 readFile.open("C:\\Users\\CheeZee\\Desktop\\numbers.dat.txt");

 if(!readFile) {

    cout<<" \a ERROR! Cannot open file!"<<endl;
    cout<<"\n Terminating Program...."<<endl;

    system("pause");
    exit(1);

 }

 else {

    while(readFile >> num) //loop until there is nothing to read

        sum+=num;

    cout<<"\n Sum: "<<sum<<endl;

 }
  readFile.close();
  return 0;

}
