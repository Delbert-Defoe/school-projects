#include <iostream>

using namespace std;

int Firstfactorial(int num){

cout<<"I ran again: "<<num<<endl;


return num<=1? 1 : num*Firstfactorial(num-1);
}

int main(){
int num=8;
cout<< Firstfactorial(num);
return 0;
}
