#include <iostream>
#include <sstream>
#include <string>
#include <strings.h>


using namespace std;


void TestInteger(int num){


if(isdigit(num)){
    cout<<"You entered a number"<<endl;
}
  else{
   cout<<"You did not nter a number"<<endl;
  }


}


int main(){

int num=0;

cout<<"Enter a number: "<<endl;
cin>>num;

TestInteger(num);
 return 0;

}
