/*
	*	Retuen true if two nums have opp sign otherwisw false
	* can not use arithmetic operator
*/

#include <iostream>
using namespace std;
bool oppositeSign1(int num1,int num2);
bool oppositeSign2(int num1,int num2);
int main(int argc, char const *argv[])
{
	int num1,num2;
	cout<<"Enter two numbers"<<endl;
	cin>>num1>>num2;
	if(oppositeSign2(num1,num2))
	cout<<num1<<" and "<<num2<<" have opposite sign"<<endl;
	else
	cout<<num1<<" and "<<num2<<" have same sign"<<endl;
	return 0;
}

bool oppositeSign2(int num1,int num2)
{
	return ((num1^num2)>>31);	//Shifting right 31 times will make it 1 for -ve no 
}
