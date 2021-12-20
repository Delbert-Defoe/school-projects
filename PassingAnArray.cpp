#include <iostream>
#include <windows.h>

using namespace std;

string itemName[5]={" "};
double itemPrices[5]={0.0};


void GetItems(string itemName[], double itemPrices[]){

for (int x=0; x<5; x++){

    system("cls");
    cout<<"Enter the name of an item "<<endl;
    cin>>itemName[x];

    cout<<"\nWhat is the price of that item?"<<endl;
    cin>>itemPrices[x];
}



}

void DisplayItems(string itemName[], double itemPrices[]){


cout<<"\n The prices are : "<<endl;
for(int x=0; x<5; x++){

    cout<<"\n"<<itemName[x]<<" : $"<<itemPrices[x];

}

}



int main (){

GetItems(itemName, itemPrices);
DisplayItems(itemName, itemPrices);

}
