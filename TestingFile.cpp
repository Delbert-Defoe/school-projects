#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

ofstream writeFile;

int points=0, counter=1;

writeFile.open("open.db");

if(!writeFile){

    cout<<"\a ERROR! Cannot open file!"
        <<"\n Terminating Application....\n";

        system("pause");
        exit(1);
}

else {

    cout<<"\n Enter points for student  #"<<counter++<<"(-1 to exist): ";
    cin>>points;

    while(points >=0 ){

        writeFile<<points<<endl;

        cout<<"\n Enter points for student #"<<counter++<<" (-1 to exit): ";
        cin>>points;

    }







}

writeFile.close();
return 0;

}
