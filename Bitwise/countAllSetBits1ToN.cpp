/*
	*	return sum of all set bits from 1 to n 
		Complexity O( log(n) )
*/

#include <iostream>
using namespace std;
unsigned int posLeftMostSetBit(int num);
unsigned int nextLeftMostSetBit(int num,int pos);
unsigned int countSetBits(unsigned int num);
unsigned int countSetBits(unsigned int num,int pos);
int main(int argc, char const *argv[])
{
	int num;
	cout<<"Enter the number"<<endl;
	cin>>num;
	int sumOfSetBits = countSetBits(num);
	cout<<"Number of set bits from 1 to "<<num<<" is "<<sumOfSetBits<<endl;
	return 0;
}
unsigned int posLeftMostSetBit(int num)
{
	int pos=0;
	while(num>1)
	{
		num = (num>>1);
		pos++;
	}
	return pos;
}
unsigned int nextLeftMostSetBit(int num,int pos)
{
	unsigned int temp = 1<<pos;
	while(num < temp)
	{
		temp = temp >>1;
		pos--;
	}
	
	return pos;
}

unsigned int countSetBits(unsigned int num)
{
	unsigned int pos = posLeftMostSetBit(num);
	return countSetBits(num,pos);
}
unsigned int countSetBits(unsigned int num,int pos)
{
	//Base Case n=0
	if(num==0)
		return 0;
	pos = nextLeftMostSetBit(num,pos);
	
	if(num == ((unsigned int)1<<(pos+1) )-1 )
		return (unsigned int)(pos+1) *(1<<pos);

	//Update n for next recursive call
	num = num - (1<<pos);
	cout<<"NUM is "<<num<<endl;
	return (num+1) + countSetBits(num) + pos *(1 << (pos-1));
}

