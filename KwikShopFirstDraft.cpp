#include <iostream>
using namespace std;

int main ()
{

//prices corresponding to the item in the item array
 int price[5] = {5,6,8,2,4}, x=0,total =0;
 string item[6] = {"nothing","Malt","Gatorade","Big water","oh henry","fruta"};
 char status= 'f';


//will store amount of items bought
// int numOfItems num[5] = {0,0,0,0,0};


 cout<<"  Items list  "<<endl;
 cout<<" ============="<<endl;
 cout<<"  1. Malt  "<<endl;
 cout<<"  2. Gatorade  "<<endl;
 cout<<"  3. Big Water   "<<endl;
 cout<<"  4. Oh Henry    "<<endl;
 cout<<"  5. Fruta     "<<endl;
 cout<<" =============  "<<endl;

 //variable responsible for incrementing
 x=0;

  do {


 cout<< " Following every item number, please use a space, then type 'f' when done "<<endl;

 cin>>price[x]>>status;

 total += price[x];
 x++;
 } while (status!='f');
 cout <<total<<endl;
}






