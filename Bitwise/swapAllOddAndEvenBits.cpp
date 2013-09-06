/*
*	Aim is to  Swap Every even bit with adjacent bit on right side and
	Aim is to  Swap Every odd bit with adjacent bit on left side

*/

#include <iostream>
using namespace std;
int swapEvenWithOdd(unsigned int num);
int main(int argc, char const *argv[])
{
	int num,swappedNum;
	cout<<"Enter num to swap even and odd bits"<<endl;
	cin>>num;
	swappedNum =swapEvenWithOdd(num);
		cout<<"Number : "<<num<<" is swapped and became "<<swappedNum<<endl;
	return 0;
}

int swapEvenWithOdd(unsigned int num)
{
	unsigned int odd= 0x55555555;	//Only odd bits are set in odd
	unsigned int even = 0xAAAAAAAA;//Only even bits are set in even
	unsigned int myOdd = odd & num ;//Extracting odd bits from num
	unsigned int myEven = even & num;//Extracting even bits from num
	myOdd = myOdd<<1;	//Making odd bits even
	myEven = myEven>>1; //making even bits odd
	return (myEven | myOdd);	
}
