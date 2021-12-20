#include <iostream>

using namespace std;

int main() {

 int num1 =0, num2 =0, num3 =0, odd=0, even=0, factor=0;

 cout << " Input the factor then separated by a space, Input 2 numbers separated with a space "<<endl;
 cin  >>factor>>num2>>num3;

 num1=num2+1;

 while (num1<num3)
{
    if (num1%factor==0){

        cout<<num1<<endl;
        even++;

    }
    else {
        odd++;
    }
 num1++;
}
    cout<<"There are: "<<even<<" multiples of "<<factor<<" between "<<num2<<" And "<<num3<< endl;

 return 0;
}
