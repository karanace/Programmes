#include <iostream>
using namespace std;
int toDecimal(int num,int base);
int main(int argc, char const *argv[])
{
	/* code */
	int num,base,result;
	cout<<"Enter num and base respectivally"<<endl;
	cin>>num>>base;
	result = toDecimal(num,base);
	cout<<num<<" of base "<<base<<" in equivalent to "<<result<<" in base 10"<<endl;
	return 0;
}
int toDecimal(int num,int base)
{
	int mul =1;
	int result =0;
	while(num>0)
	{
		result += num%10*mul;
		mul *=base;
		num = num /10;
	}
	return result;
}