#include <iostream>
#include <windows.h>

using namespace std;

int choice();

int main() {
char number=' ';

cout<<"Type one or 2"<<endl;
cin>>number;

switch(number) {
case '1':
 cout<<"bye!";
    break;

case '2':
    choice();
    break;


cout<<"you chose \n"<<choice();
}
 }

int choice () {
int x=0;

cout<<"option 1"<<endl;
cout<<"option 2"<<endl;
cout<<"option 3"<<endl;

cin>>x;
int option= x;

return option;

}



