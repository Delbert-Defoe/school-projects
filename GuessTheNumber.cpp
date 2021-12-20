#include <iostream>
#include <windows.h>
#include <cctype>
#include <cstdlib>

using namespace std;


class GuessingGame{
private:
   string PlayerName;
   int attempts;
   int RandomNumber;


public:
    GuessingGame();
    void setPlayerName(string);
    const string getPlayerName();
    void trackAttempts();
    const int getAttempts();
    int GenerateRandomNumber();

};

int main() {

GuessingGame player;
string name;
int number;

int RandomNumber=0;
RandomNumber=player.GenerateRandomNumber();

cout<<RandomNumber;

cout<<"Please enter your name"<<endl;
cin>>name;

player.setPlayerName(name);

cout<<"The game chose a random number, please guess this number"<<endl;
cin>>number;
if(number!=RandomNumber){
do{

    cout<<"Sorry, You guessed Wrongly...Try again"<<endl;
    cin>>number;
    player.trackAttempts();



}while(number!=RandomNumber);
}

cout<<"Congratulations "<<player.getPlayerName()<<" You guessed the Number after "<<player.getAttempts()<<" Attempt(s) ";
system("pause");

return 0;
}


GuessingGame::GuessingGame(){

PlayerName= "John Doe";
attempts= 1;
RandomNumber=1;
}

void GuessingGame::setPlayerName(string name){


PlayerName= name;

}

const string GuessingGame::getPlayerName(){

return PlayerName;
}

void GuessingGame::trackAttempts(){

attempts+=1;
}

const int GuessingGame::getAttempts(){

return attempts;
}

int GuessingGame::GenerateRandomNumber(){

 RandomNumber= rand() % 20 + 1;

return RandomNumber;
}

