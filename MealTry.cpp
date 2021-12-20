#include <iostream>
#include <windows.h>

using namespace std;

//prototyping of all functions
void SelectMeal();
void CreateLunch();
void CreateBreakfast();
void CreateDinner();
int Randomizer(int &, int &, int &, int &, int &,int base,int limit);

//initialization of all the parallel arrays. Each double is a parallel array to the string array above it
string Cabohydrates[10]={"bread &peanut butter","Apple pudding","cereal","Cream of wheat","Oats","Macaroni","rice","Potato pie","Fig pie","Spaghetti"};
double CarbsPrice[10]={2.00,4.56,7.00,7.00,6.75,5.00,5.00,4.00,5.00,5.00};

string protein[10]={"Egg whites","Sausages","Baked beans","Bread &Cheese paste","Bread &Tuna","Stewed chicken","Baked Chicken","Lentils","Red Beans","String Beans"};
double ProteinsPrice[10]={3.00,3.50,5.50,6.00,6.00,7.00,7.00,4.00,4.00,4.00};

string fat[10]={"Avocados","Boiled Egg","Cashews","Chia Seeds","Fried potato","Fried Chicken","Meatball","Pizza","Fried Drummets","Deviled Eggs"};
double FatPrice[10]={3.00,3.00,3.25,3.25,4.00,7.00,6.00,4.00,4.00,4.00};

string fruitVegetable[10]={"Apple","Banana","Orange","carrots","Grapes","Pear","Tomatoes","Pumpkin","Lettuce","Cabbages"};
double FruitPrice[10]={3.00,2.00,3.00,3.00,4.00,4.00,4.00,4.00,3.00,3.00};

string drinks[10]= {"Milk","Lime skin tea","Lipton tea","Mint Tea","Bay Leaf tea","Guava Juice","Grapefruit Juice","Lime Squash","Lemonade","Apple Juice"};
double DrinksPrice[10]={6.00,5.00,6.75,5.50,5.50,5.75,6.00,6.75,5.00,5.00};

//main function provide us with the main menu and keeps the program looping until the user exits
int main(){

system("Title USC Cafe");

//choice and decision are two variables used to exit the program later on in the code
  char choice=' ', decision=' ';

//welcome message
cout<<" Welcome to The University's Cafe!! ";

system("pause");
system("cls");

//this menu will loop until the user indicates that they want to leave
do{
system("cls");

cout<<"========================"<<endl;
cout<<"      Meal Builder      "<<endl;
cout<<"========================"<<endl;
cout<<"   1. Create Meal       "<<endl;
cout<<"   2. Help              "<<endl;
cout<<"   3. Exit              "<<endl;
cout<<"========================"<<endl;
cout<<"Select an option(1-3)   "<<endl;
cout<<"========================"<<endl;
cin>>choice;


switch(choice){

//this case calls the function "SelectMeal" Which contains another menu
case '1':

    SelectMeal();
    break;

//this case provides the user with information about the program
case '2':
    system("cls");
    cout<<" >This program creates a nutritional meal based on the course of your choice (Breakfast, Lunch, Supper).\n";
    cout<<" >To start creating a meal, return to the main menu by pressing any key, and choose option one '1'.\n";
    cout<<" >If you wish to exit choose option '3'\n";
    system("pause");
    break;

//this case Provides the user with an exit from the program after it warns the user of the action they are about to take
case '3':

    system("cls");
    cout<<"\n==========================================="<<endl;
    cout<<" Are you sure that you want to exit!??  "<<endl;
    cout<<"==========================================="<<endl;
    cout<<" 1. Yes "<<endl;
    cout<<" 2. No  "<<endl;
    cout<<"==========================================="<<endl;
    cin>>decision;

//this switch case will take the data captured in case 3 of the last switch case, and will exit if it was 1, and return to the menu if it was 2
    switch(decision){
        case '1':
        system("cls");
        cout<<"\nThank you for using visiting University's cafe! "<<endl;
        continue;

        case '2':
        cout<<" Will return to menu "<<endl;
        decision='0';
        choice='0';
        break;

        default:
            cout<<" INVALID OPTION ";
            system("pause");
            decision='0';
            choice='0';
            break;
}
        break;

default:
 cout<<" INVALID OPTION! ";
 Sleep(4000);
 break;

}
}while(decision!='1'&&choice!='3');
/*the while statement above checks to see if the user chose to exit AND confirmed that choice. If the user does not confirm, the menu is looped,
   if he/she does, the program is exited*/
return 0;
}

/*SelectMeal() function provides the user with a menu which will lead them to the random meal builder of the course of their choice, and also offers a
  back option */
void SelectMeal(){
system("cls");

//char meal, stores the option of which meal the user would like to generate
char meal=' ';

cout<<"================================================="<<endl;
cout<<"Please type in the corresponding number of the   "<<endl;
cout<<"meal you would like to be created! "<<endl;
cout<<"================================================="<<endl;
cout<<" 1. Breakfast                                    "<<endl;
cout<<" 2. Lunch                                        "<<endl;
cout<<" 3. Dinner                                       "<<endl;
cout<<" 4. Back                                         "<<endl;
cout<<"================================================="<<endl;
cin>>meal;

switch(meal){

//option 1 calls the breakfast creating function
case '1':
    CreateBreakfast();
    break;

//option 2 calls the lunch creating function
case '2':
    CreateLunch();
    break;

//option 3 calls the dinner creating function
case '3':
    CreateDinner();
    break;

//option 4 returns to the main menu
case '4':
    break;


default:
    cout<<" INVALID OPTION! ";
    Sleep(4000);


}
}
/*
The next 3 functions are the same, therefore one will be commented on.
Where each function varies, there will be individual comments within that function
*/


// CreateBreakfast() function displays a random breakfast based on conditions set within
void CreateBreakfast(){

//integers a, b, c, d and e are all passed into the Randomizer function to be randomized into an integer
int a=0, b=0, c=0, d=0, e=0;
//total stores the prices from the array parallel to the item chosen
double total=0.0;
//these two constants provide the randomizer with a range, of specifically ordered food, so that impractical foods will not be chosen for a meal

//option will store the users decision whether to make a new meal or not
char option=' ';

//this do-while loop will loop and create a new meal until the user decides to stop
do{

//randomizer will take each integer's reference, place a random integer into it, and send it back to the function it was called in
Randomizer(a, b, c, d, e, base, limit);


//this short block of code checks to see if the randomizer chose both bread and peanut butter, and bread and cheese, and changes the bread and cheese.
if
}

/*the function now displays a random meal using the random integers returned from the Randomizer() function as indexes. The parallel arrays use the
same index */

system("cls");
cout<<"==============================="<<endl;
cout<<"Your breakfast meal is:        "<<endl;
cout<<"==============================="<<endl;
cout<<"> "<<Cabohydrates[a]<<" : $"<<CarbsPrice[a]<<endl;
cout<<"> "<<protein[b]<<" : $"<<ProteinsPrice[b]<<endl;
cout<<"> "<<fruitVegetable[c]<<" : $"<<FruitPrice[c]<<endl;
cout<<"> "<<fat[d]<<" : $"<<FatPrice[d]<<endl;
cout<<"> "<<drinks[e]<<" : $"<<DrinksPrice[e]<<endl;
cout<<"==============================="<<endl;
cout<<"Your Total is $";
//the total price is calculated using the indexes of the parallel arrays to the corresponding to each food item
total=CarbsPrice[a]+ProteinsPrice[b]+FruitPrice[c]+FatPrice[d]+DrinksPrice[e];

cout<<total<<endl;
cout<<"==============================="<<endl;
cout<<"\n"<<endl;

//after a meal is created, the program gives the user a chance to change it if they are dissatisfied, or return to the menu if they are satisfied
cout<<"Are you satisfied with your meal?(type '1') or would you like another one?(type '2')"<<endl;
cin>>option;

switch(option){

//case 2 displays a friendly message and returns to the menu
case '1':
    system("cls");
    cout<<"=========================================="<<endl;
    cout<<"Thank you for purchasing at USC CAFE :D !!"<<endl;
    cout<<"=========================================="<<endl;
    system("pause");
    break;

//case 2 causes the function to loop, creating different meal
case '2':
    break;

//default is executed if invalid options are inputed
default:
    cout<<"Invalid Option!! Type '1' to exit, or '2' to generate another meal!!"<<endl;
    system("pause");
    break;
}

}while(option!='1');
// the function will loop until the user chooses option 1, after a meal is created




}


//Randomizer() generates 5 random numbers between two numbers (base and limit) passed from the function it was called from.
int Randomizer(int &a, int &b, int &c, int &d, int &e, int base, int limit){

a= rand() % limit + base;
b= rand() % limit + base;
c= rand() % limit + base;
d= rand() % limit + base;
e= rand() % limit + base;

return 0;
}

