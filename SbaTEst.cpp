#include <iostream>

using namespace std;

int main() {

   string cashier1 = "Julie", cashier2 = "Betty", cashier3 = "John", password = "1234";
   bool nightTime = true;

   do {
     cout<<"Welcome to Botanic Bistro"<<endl;
     cout<<"Please Enter your Username: ";
     string username;
     cin >> username;

     if(username != cashier1 && username != cashier2 && username != cashier3) {
       cout<< "username is invalid"<<endl;
       continue;
     }
    cout<<"Rest of code";
   } while(true); //it will check to see if what is in the while brackets is true or false
   return 0;
}
