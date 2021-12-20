#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main(){

string names[5]={"Age 1","Age 5","Age 8","Age 10","Age 12"};
int Length[5]={15,30,10,25,5};
int distance_from_zero[5]={1,5,8,10,12};

int arraySize= 5;
int height=0, width=0, area=0, lastArea=0, b=0, a=0, y=0;

cout<<"At least this part works"<<endl;
system("Pause");


for(int x=0; x<arraySize; x++){
     for(int y=x+1; y<arraySize; y++){

     if(Length[x]>Length[y]){

        height=Length[y];

        if(distance_from_zero[y]>distance_from_zero[x])
         width= distance_from_zero[y]-distance_from_zero[x];

        else
          width= Length[x]-Length[y];

        area= height*width;
        cout<<"The area of "<<names[x]<<" & "<<names[y]<<" is: "<<area<<endl;
     }
      else{
        height=Length[x];

        if(Length[y]>Length[x])
         width= distance_from_zero[y]-distance_from_zero[x];

        else
          width= distance_from_zero[x]-distance_from_zero[y];

        area= height*width;
        cout<<"The area of "<<names[x]<<" & "<<names[y]<<" is: "<<area<<endl;
      }
     if(area>lastArea){
        lastArea=area;
        a=x;
        b=y;
      }

}
}
 cout<<names[a]<<" and "<<names[b]<<" would have the most toys"<<endl;
}







