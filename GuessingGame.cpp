#include <iostream>
#include <windows.h>

using namespace std;

void MatchNumbers();

int main (){

char option=' ';

cout<<"Welcome to my guessing game. If you guess the number i am thinking of correctly, i will reward you :) "<<endl;
system("pause");
system("cls");

do {


cout<<" 1. Play Game "<<endl;
cout<<" 2. Exit     "<<endl;
cin>>option;


    switch(option) {

      case '1':
      MatchNumbers();
      break;

      case '2':
         cout<<"\nGoodbye!"<<endl;
         continue;
        break;

      default:
        cout<<"invalid character";
    }


}while(option!='2');
return 0;

}

void MatchNumbers(){
   int userGuess=0;
    char choice= ' ';

   cout<<" I am thinking of a number from 1 to 12. Can you guess the number? "<<endl;
   cin>>userGuess;

   int number = 1+ rand()%3;

   char option='Y';
   //int  streak=0;


   if (number==userGuess) {

    //streak++;
    cout<<"CONGRATULATIONS!!! you won 100 dollars"<<endl;
    //cout<<"Your streak is "<<streak<<endl;
    //cout<<"\n  Play again to increase your streak!! XD "<<endl;
    system("pause");
    system("cls");


      }




   else {
    cout<<"oops that was wrong.....Try again? :)"<<endl;
    //streak=0;
    system("pause");

    system("cls");
}

return;

}


