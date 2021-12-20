#include <iostream>
#include <windows.h>

using namespace std;

int main() {

int numbers[10]={0}, sum=0, x=0;

for(int x=0; x<10; x++){

    cout<<" Enter a number "<<endl;
    cin>>numbers[x];

    sum+=numbers[x];

}
 cout<<" The sum of "<<numbers[x];

 do{
   x++;
   cout<<", "<<numbers[x];

 }while(numbers[x]<9);

 cout<<", and "<<numbers[9]<<", is "<<sum<<endl;

system("pause");

return 0;
}
