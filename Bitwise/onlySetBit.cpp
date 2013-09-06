#include <iostream>
using namespace std;
bool powerOfTwo(int num);
int onlySetBit(int num);
int main(int argc, char const *argv[])
{
	int num,pos;
	cout<<"Enter num to check"<<endl;
	cin>>num;
	if( (pos = onlySetBit(num)) == -1)
		cout<<"Number : "<<num<<" is not a power of 2"<<endl;
	else
		cout<<"Number : "<<num<<" has a bit set at index(starting at 0) "<<pos<<endl;
	return 0;
}
bool powerOfTwo(int num)
{
	if( (num & (num-1)) == 0)		//Carefull priority of & is less than == use proper parenthesis
		return true;
	else
		return false;
}
int onlySetBit(int num)
{
	int count =-1;
	if(powerOfTwo(num))
	{
		while(num !=0)
		{
			cout<<"Num is "<<num<<endl;
			++count;
			num = (num>>1);
		}
		return count;
	}
	else
		return -1;
}
