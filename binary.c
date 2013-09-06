#include<iostream.h>
using namespace std;
int fact[10] ={0};
int factorial(int n)
{
	if(factorial[n] !=0)
	return factorial[n];
	else
	return n* factorial(n-1);
}
void main()
{
	fact[0]=1;
	fact[1]=1;

}