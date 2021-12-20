#include <iostream>

using namespace std;

double VolumeOfRect(double, double, double);

int main(){

//variable declaration
double length =0, breadth=0, height =0;

//get user input
cout <<"\n Enter the length, breadth, and height of the rectangle\n"<<" separated by a space (eg. 1 2 3): ";
cin >>length>>breadth>>height;

cout<<"\n\n Volume of Rectangle is: "<< VolumeOfRect(length, breadth, height)<<endl;

return 0;
}

double VolumeOfRect(double length, double breadth, double height) {

int result=0;

result= length*breadth* height;

return result;
}
