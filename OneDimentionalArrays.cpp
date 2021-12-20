#include <iostream>

using namespace std;

void displayArrays(string Names[]);


void GetArrays(){


string Names[3]={" "};

for(int x=0; x<3; x++){

    cout<<" Please enter a name "<<endl;
    cin>>Names[x];


}

displayArrays(Names);

}

int main(){

GetArrays();

return 0;

}

void displayArrays(string Names[]){
int a=0;
int b=1;
do{

    cout<<" Name "<<b<<" is "<<Names[a]<<endl;
    a++;
    b++;

}while(a<3);


}
