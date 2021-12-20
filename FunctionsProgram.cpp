#include <iostream>
#include <windows.h>

using namespace std;

int test(int &);



int main(){

int num=7;

cout <<"\n Variable check 1: "<<num;
cout <<"\n Function returns: "<< test(num);
cout <<"\n Variable check 2: "<< num;

return 0;
}

int test(int &num){

num = num+1;
return  num;
}
