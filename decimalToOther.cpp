#include<iostream>
using namespace std;
int decimalToOther(int num,int base);
int main(int argc, char const *argv[])
{
	int num,base,result;
	cout<<"Enter Number in decimal and base in which you want to convert"<<endl;
	cin>>num>>base;
	result = decimalToOther(num,base);
	cout<<"Decimal Number "<<num<<" is equivalent to "<<result<<" in base "<<base<<endl;
	return 0;
}
int decimalToOther(int num,int base)
{
	int result =0;
	int mul=1;
	while(num>0)
	{
		result += num%base*mul;
		mul *=10;
		num = num/base;
	}
	return result;
}