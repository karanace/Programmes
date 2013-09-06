#include<stdio.h>
int facTail(int x,int a);
int main(int argc, char const *argv[])
{
	/* code */
	int x=2;
	printf("Factorial of x = %d\n",facTail(x,1));
	return 0;
}
int facTail(int x,int a)
{
	if(x<0)
		return 0;
	else if(x==0 || x==1)
		return a;
	else
		return facTail(x-1,x*a);
}

