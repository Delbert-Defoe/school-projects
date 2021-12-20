#include <iostream>

using namespace std;

int main()
{

  string Myname;
  int age=0,bdate =0, cdate=0;

  cout << "input someone's name"<< endl;
  cin >> Myname;

  cout << "input birth date"<<endl;
  cin >> bdate;

  cout << "input current date"<<endl;
  cin >> cdate;

  age= cdate-bdate;

  cout <<Myname<<" Is "<<age<<" years old"<< endl;

  return 0;
}
