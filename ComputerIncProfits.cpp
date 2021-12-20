
// I could not fin the problem, so i am not sure if this is complete however i did what i think i was supposed to do

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
//declaration of variables
    string data= " ", moneyData = " ", profitData=" ", LastProfit=" ", LowerProfit= " ";
    double  money= 0, Actual=0, TotalProfit=0, MaxProfit=0, profit=0, MinProfit=0, x=0;

//fancy waiting screen
cout<<"================================"<<endl;
cout<<"Opening File............."<<endl;
cout<<"================================"<<endl;
Sleep(1000);
system("cls");



//creating an object of the fstream class
fstream readFile;
//opening the target file
readFile.open("C:\\Users\\CheeZee\\Downloads\\profits.html");
//check to see if the file is open
if (!readFile){

    cout<<"File did not open"<<endl;
    system("pause");
    exit(1);

}
//if the file is open the program will get to work
 else {

//more fancy waiting screens
cout<<"================================"<<endl;
cout<<"Reading File............."<<endl;
cout<<"================================"<<endl;
Sleep(1000);
system("cls");

cout<<"================================"<<endl;
cout<<"Calculating Profits.........."<<endl;
cout<<"================================"<<endl;
Sleep(1000);
system("cls");



    while(!readFile.eof()){

        //this line of code will read through the file until the first dollar sign is met denoting the amount of profit
        getline(readFile, data, '$');

        //this line of code will read from the '$' sign until the end '<' sign which is essentially the profit
        getline(readFile, profitData, '<');






//this block of code will run once so that the lowerProfit variable has an initial value to compare
 if (x<1){

    LowerProfit=profitData;

 }
    x++;
 //this block of code compares the last profit recorded to see
        if(profitData>LastProfit){
            LastProfit=profitData;

        }


         if(LowerProfit>=profitData){

            LowerProfit=profitData;

        }

        stringstream(LastProfit)>>MaxProfit;
        stringstream(profitData)>>profit;
        stringstream(LowerProfit)>>MinProfit;


        TotalProfit+=profit;



    }
 cout<<fixed<<setprecision(2);

 cout<<"==============================="<<endl;
 cout<<"The maximum profit was: $"<<MaxProfit<<endl;
 cout<<"The minimum profit was: $"<<MinProfit<<endl;
 cout<<"The total profit is: $"<<TotalProfit<<endl;
 cout<<"==============================="<<endl;

 }

 readFile.close();

 return 0;
}
