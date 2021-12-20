#include <iostream>

using namespace std;

int main() {

bool DelbertIsBoy = true;
bool NiaIsGirl = false;
//now i am going to change one to false after i run the program

if(DelbertIsBoy) {
    cout<<"Delbert is Boy";
    //i should have left that... this is a comment
}

if(NiaIsGirl){
    cout<<"Nia is a girl";
    //pfft thing want to tell me how to spell the girl name...but anywhoooo
    //this should execute because NiaIsGirl is true...... i think...
}

if(NiaIsGirl && DelbertIsBoy){
    cout<<"Nia is a girl and Delbert is a boy";
    //this should execute because both of them are true

}

if(NiaIsGirl && DelbertIsBoy){
    cout<<"This is normal... i hope"<<endl;
}
//welse will execute if the statement in the if brackets evaluate to false
else{
   cout<<"SHiiii i knew she had a dingaling"<<endl;
   //this ran because NiaIsGirl is false... apparently..hehe
}
// however if i use the '||' operator
if(NiaIsGirl || DelbertIsBoy) {
    cout<<"One of these things true, but something still ain right"<<endl;
}


return 0;
}
