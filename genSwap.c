#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int swap(void *x,void *y,int size);
int main()
{
	char *x="karanchughisalwaysright",*y="pankaj";
	int z = swap(&x,&y,4);
	printf("x=%s\ty=%s\n",x,y);
	return 0;
}
int swap(void *x,void *y,int size)
{
	void *tmp;
	if((tmp=malloc(size))==NULL)
	{
		return -1;
	}
	memcpy(tmp,x,size);
	memcpy(x,y,size);
	memcpy(y,tmp,size);
	free(tmp);
	return 0;
}