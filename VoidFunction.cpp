#include <iostream>

using namespace std;

void message(string);

int main(){

string name=" ";

cout<<"Please input your name"<<endl;
getline(cin, name);

message(name);

return 0;
}

void message(string name){


cout<<"\n Hello "<<name;

}
