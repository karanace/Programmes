#include <iostream>
using namespace std;
int int_mod(int a,int b)
{
	return (a%b + b) % b;

}
int main(int argc, char const *argv[])
{
	/* code */
	int x = 1,a,b;
	while(x)
	{
		cin>>x>>a>>b;
		cout<<"Mod of "<<a<<" and "<<b<<" is "<<int_mod(a,b)<<endl;
	}


}