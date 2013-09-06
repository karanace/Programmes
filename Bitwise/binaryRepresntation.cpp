/*
	*	Aim is to add two bit string they may be of differnet length

*/

#include <iostream>
#include <sstream>
using namespace std;
string binaryRep(unsigned int num);
int main(int argc, char const *argv[])
{
	int num;
	string result;
	cout<<"Enter num"<<endl;
	cin>>num;
	result = binaryRep(num);
		cout<<"Binary Representation of "<<num<<" is : "<<result<<endl;
	return 0;
}

string binaryRep(unsigned int num)
{
	string result;
	for (int i = 31; i >=0 ; --i)
	{
		if( ( (1<<i) & num ) !=0)
			result += '1';
		else
			result +='0';
	}
	return result;
}
