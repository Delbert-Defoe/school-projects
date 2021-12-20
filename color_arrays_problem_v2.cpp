/*
  This program displays a series of sentences
  in various colors.
*/

#include <iostream>
#include <windows.h>
using namespace std;

//prototypes
void setColor(short int); // NO ERROR ON THIS LINE

void changeColor(short int [], string [], const int);


int main()
{
    system("title Text Color"); // NO ERROR ON THIS LINE

    int Array_Size =7;

    //------- THIS SECTION HAS NO ERRORS --------------------------------------------------------
    short int color[Array_Size] = {9, 10, 11, 12, 13, 14, 15};                                           //
    string names[Array_Size] = {"DARK BLUE", "GREEN", "LIGHT BLUE", "RED", "PURPLE", "YELLOW", "WHITE"}; //
    const int LOOPS = 7;                                                                       //
    //-------------------------------------------------------------------------------------------

    while(true)
    {
        changeColor(color, names, LOOPS);//call function
    }//end while

    return 0;
}//end main


void changeColor(short int color[], string names[], const int LOOPS)
{
    //loop through array
    for(int index = 0; index < LOOPS; index++)
    {
        Sleep(500); // NO ERROR ON THIS LINE
        setColor(color[index]);
        cout << "\n This sentence is displayed in " << names << "!!!" << endl;
    }//end for

    Sleep(3000); // NO ERROR ON THIS LINE
    system("cls"); // NO ERROR ON THIS LINE
}//end changeColor



//------- THIS SECTION HAS NO ERRORS ---------------------------------
void setColor(short int col){                                       //
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col); //
}                                                                   //
//--------------------------------------------------------------------
