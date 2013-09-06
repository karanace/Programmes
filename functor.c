#include<stdio.h>
#include<stdlib.h>
int areEqual(int *x,int *y);
int (*equal)(int *x,int *y);
int main(int argc, char const *argv[])
{
	/* code */
	int x=5,y=7,z;
	equal = areEqual;
	z=equal(&x,&y);
	printf("%d\n",z);
	return 0;
}
int areEqual(int *x,int *y)
{
	if(*x == *y)
		return 1;
	else
		return 0;
}