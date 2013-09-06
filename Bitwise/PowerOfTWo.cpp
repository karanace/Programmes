#include <iostream>
using namespace std;
bool powerOfTwo(int num);
int main(int argc, char const *argv[])
{
	int num;
	cout<<"Enter num to check"<<endl;
	cin>>num;
	if(powerOfTwo(num))
		cout<<"Number : "<<num<<" is power of 2"<<endl;
	else
		cout<<"Number : "<<num<<" is not power of 2"<<endl;
	return 0;
}
bool powerOfTwo(int num)
{
	if( (num & (num-1)) == 0)		//Carefull priority of & is less than == use proper parenthesis
		return true;
	else
		return false;
}