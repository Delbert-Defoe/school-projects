#include <iostream>

using namespace std;

int main() {

 int num1 =0, num2 =0, num3 =0, odd=0, even=0;

 cout << " Input 2 numbers separated with a space "<<endl;
 cin >>num2>>num3;

 num1=++num2;

 while (num1<num3)
{
    if (num1%2==0){
        even++;
    }
    else {
        odd++;
    }
 num1++;
}
    cout<<"There are: "<<even<<" Even Numbers, And "<<odd<<" Odd Numbers between "<<num2<<" And "<<num3<< endl;

 return 0;
}
