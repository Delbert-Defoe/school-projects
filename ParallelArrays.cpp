#include <iostream>
#include <windows.h>

using namespace std;

int main(){

string FirstName[4]={" "};
string Position[4]={" "};
int Number[4]={0};

for(int x=0; x<4; x++){
cout<<" Enter a player's name "<<endl;
cin>>FirstName[x];

cout<<"What is "<<FirstName[x]<<"'s position? "<<endl;
cin>>Position[x];

cout<<"What is "<<FirstName[x]<<"'s number? "<<endl;
cin>>Number[x];
system("cls");
}

cout<<"This is the team sheet"<<endl;
cout<<"\nPlayer Name                Player position           Player number"<<endl;

for(int x=0; x<4; x++){

cout<<"\n"<<FirstName[x]<<"                                  "<<Position[x]<<"                "<<Number[x]<<endl;


}

return 0;
}
