#include <iostream>
#include <windows.h>

using namespace std;

int main() {

int score=0, total_score=0;



 for (int a=1; a<=amount; a++){
    cout<<"\n Enter Score for Exam #"<<a<<" : ";
    cin>> score;



    total_score+=score;
 }

 system("cls");
 system("pause, 20000");
 cout <<"\n Total Exam Score: "<<total_score<< endl;

 return 0;
}

