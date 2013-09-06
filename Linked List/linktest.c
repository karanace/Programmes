#include"list.h"
#include<stdlib.h>
#include<stdio.h>
void main()
{
	List *l;
	list_init(l,l->destroy);
	printf("%d",list_size(l));
}
