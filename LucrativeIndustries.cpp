//lucrative industries salary calculator
#include <iostream>
#include <windows.h>


using namespace std;

//prototype of function
void PrintEmpSalary(char [], double [], double [], string, char, int, int);

int main(){

//parallel arrays holding information about the paying system
char PayGrade[5]={'A','B','C','D','E'};
double RegHourRate[5]={10.00,12.50,14.00,16.50,19.00};
double OvertimeRate[5]={1.50,2.50,4.00,5.50,7.00};

//variables which store the inputted information
string EmpName=" ";
char EmpPayGrade=' ';
int HoursWorked=0, overtime=0;

//option  stores the users decision to exit or continue
char option=' ';

//this loop runs the program from the menu until the user chooses to exit
do{

    system("cls");

    cout<<"------------------------------"<<endl;
    cout<<" Choose option 1 or 2 "<<endl;
    cout<<"------------------------------"<<endl;
    cout<<">1. Calculate employee salary"<<endl;
    cout<<">2. Exit"<<endl;
    cout<<"------------------------------"<<endl;
    cin>>option;

    switch(option){

//option one captures all the data required from the user
case '1':

//cin.ignore() ignores the previous input from the previous cin operator, so that getline does not cause a bug.
    cin.ignore();
    system("cls");
    cout<<" Please input the employees name to continue: "<<endl;
    getline(cin,EmpName);


    system("cls");

    cout<<" What is "<<EmpName<<"'s pay grade? (Please use a capital letter A-E)"<<endl;
    cin>>EmpPayGrade;


    system("cls");

    cout<<" How many hours did "<<EmpName<<" work for?"<<endl;
    cin>>HoursWorked;

//this block of code determines how much overtime hours were worked if there was any, and resets hours worked to 40
    if(HoursWorked>40){

        overtime= HoursWorked-40;
        HoursWorked= 40;
    }

//calling the function
    PrintEmpSalary(PayGrade, RegHourRate, OvertimeRate, EmpName, EmpPayGrade, HoursWorked, overtime);
    break;

//this case allows us to exit
case '2':
    system("cls");
    cout<<"Goodbye"<<endl;
    Sleep(2000);

    }

}while(option!='2');

return 0;
}

//this function calculates the salary of the employee
void PrintEmpSalary(char Grade[], double NormalRate[], double OvertimeRate[], string Name, char EmpGrade, int Hours, int overtime){

double salary=0.0;

//these series of if-else's simply check what the pay grade entered was, and performs the appropriate calculation
if(EmpGrade==Grade[0]){

 salary= (NormalRate[0]*Hours)+(OvertimeRate[0]*overtime);

}
else if(EmpGrade==Grade[1]){

 salary= (NormalRate[1]*Hours)+(OvertimeRate[1]*overtime);

}
else if(EmpGrade==Grade[2]){

 salary= (NormalRate[2]*Hours)+(OvertimeRate[2]*overtime);

}


else if(EmpGrade==Grade[3]){

 salary= (NormalRate[3]*Hours)+(OvertimeRate[3]*overtime);

}


else if(EmpGrade==Grade[4]){

 salary= (NormalRate[4]*Hours)+(OvertimeRate[4]*overtime);

}

//displays salary
system("cls");
cout<<"---------------------------------"<<endl;
cout<<Name<<"'s Salary is: $"<<salary<<endl;
cout<<"---------------------------------"<<endl;

//gives space before system pause to make result more readable
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;


system("pause");

}


