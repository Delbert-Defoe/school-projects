#include <iostream>

using namespace std;

int main() {
  double GrossBalance= 0, NetBalance= 0, Withdrawals= 0, deposits= 0, tax= 0;
  const double taxRate =0.01;

  cout <<" Please enter your Gross Balance:"<< endl;
  cin>> GrossBalance;

  cout <<" What is your total withdrawals? "<<endl;
  cin>> Withdrawals;

  cout <<" What is your total deposits? "<<endl;
  cin >> deposits;

  tax= GrossBalance*taxRate;

  NetBalance= GrossBalance-tax-Withdrawals-deposits;

  cout <<" Your Tax was '"<<tax<<"'"<<"\n your Net Balance is '"<<NetBalance<<"'"<<endl;



  return 0;

}
