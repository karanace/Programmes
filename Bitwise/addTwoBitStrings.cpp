/*
	*	Aim is to add two bit string they may be of differnet length

*/

#include <iostream>
#include <sstream>
using namespace std;
string addBitStrings(string a,string b);
void  makeEqualLength(string &a,string &b);
int main(int argc, char const *argv[])
{
	int num,swappedNum;
	string a,b,result;
	cout<<"Enter two bit strings to add"<<endl;
	cin>>a>>b;
	result = addBitStrings(a,b);
		cout<<"Addition of "<<a<<" and "<<b<<" is : " <<result<<endl;
	return 0;
}

void  makeEqualLength(string &a,string &b)
{
	int size1 = a.size();
	int size2 = b.size();
	if(size1>size2)
	{
		for (int i = 0; i < size1-size2; ++i)
		{
			b = '0' + b;
		}
	}
	else if(size1 <size2)
	{
		for (int i = 0; i < size2-size1; ++i)
		{
			a = '0' + a;
		}
	}
}
string addBitStrings(string a,string b)
{
	string result;
	makeEqualLength(a,b);
	int len = a.size();
	int carry = 0;
	int firstBit,secondBit,sum;
	stringstream out;
	for (int i = len-1; i >=0; i--)	//Starting from LSB
	{
		firstBit = a.at(i) - '0';	//Extracting ith bit will be 0 or  1 by ascii subtarction
		secondBit = b.at(i) - '0';  //Extracting ith bit will be 0 or  1 by ascii subtarction
		sum = (firstBit ^ secondBit ^ carry) + '0'; //Sum is xor of all 3 bits + adding ascii of '0'
		result = (char)sum + result ; //Updating result string
		carry = (firstBit & secondBit) |(firstBit &carry) |(secondBit &carry);	//Updating carry 
		//Carry is 1 when atleast any two bits are 1
	}
	if(carry)	//Overflow case 
		result = '1' + result;	//Adding one of carry
	return result;
}
