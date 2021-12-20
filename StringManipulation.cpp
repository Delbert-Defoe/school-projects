#include <iostream>
#include <cctype>


using namespace std;

int main(){

string name=" ", reversename=" ";

cout<<"Please enter a name"<<endl;
getline(cin, name);

for(int x=name.length(); x>0; x--){

    reversename+=name[x];

}

cout<<"That name backwards is: "<<reversename;


}
