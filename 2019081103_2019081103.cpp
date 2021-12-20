/*
  This program displays each student's name,
  scores for three (3) quizzes,
  total score and percentage.
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 7;

//function to calculate and display student scores
void studentScores(string firstName[], string lastName[], int quiz01[], int quiz02[], int quiz03[])
{
  //record will be the number which displays based on the record being shown
  int record=1;
  //'x' will be the index of the arrays being displayed
  int x=0;
  //this constant is used to calculate average
  const int possibleScore=75;

  //this do-while loop will run as much times as the size of the array (7)
do {

  cout<<fixed<<setprecision(0);
  cout<<"------------------------------"<<endl;
  cout<<"Record #"<<record<<endl;
  cout<<"------------------------------"<<endl;
  cout<<"Name: "<<firstName[x]<<" "<<lastName[x]<<endl;
  cout<<"Quiz 01: "<<quiz01[x]<<endl;
  cout<<"Quiz 02: "<<quiz02[x]<<endl;
  cout<<"Quiz 03: "<<quiz03[x]<<endl;
  cout<<"------------------------------"<<endl;
  //the total score is calculated by adding the scores together
  double totalScore=quiz01[x]+quiz02[x]+quiz03[x];
  //the percentage is then calculated using the total score divided by the possible score
  cout<<"Total Score: "<<totalScore<<" ("<<(totalScore/possibleScore)*100<<"%)"<<endl;
  cout<<"------------------------------"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;

  //both 'x' and record are incremented to display the next parallel arrays
  x++;
  record++;

  }while(x<ARRAY_SIZE);
}//end studentScores


int main()
{
    system("title QUIZ RECORDS");

    //arrays
    string firstName[ARRAY_SIZE] = {"Abigail", "Beth", "Carice", "Donna", "Ellory", "Fiona", "Gloria"};
    string lastName[ARRAY_SIZE] = {"Henry", "Ingram", "John", "Kellog", "Long", "Morris", "Neville"};
    int quiz01[ARRAY_SIZE] = {25, 23, 24, 25, 20, 15, 18};
    int quiz02[ARRAY_SIZE] = {25, 25, 20, 25, 22, 25, 24};
    int quiz03[ARRAY_SIZE] = {25, 19, 25, 25, 12, 23, 25};

    //call function to display student scores
    studentScores(firstName, lastName, quiz01, quiz02, quiz03);

    return 0;
}//end main





