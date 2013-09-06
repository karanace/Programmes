#include<stdio.h>
void insertion_sort(int *arrayToSort,int sizeOfArray);
void main()
{
	int a[10] ={10,9,8,7,6,5,4,3,2,1};
	int n=10,i;
	insertion_sort(a,10);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
			printf("\t");
		else
			printf("\n");
	}
}
void insertion_sort(int *arrayToSort,int sizeOfArray)
{
	int i,j,temp,k;
	for(i=1;i<sizeOfArray;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arrayToSort[i] <arrayToSort[j])
			{
				temp =arrayToSort[i];
				for(k=i;k>j;k--)
				arrayToSort[k] = arrayToSort[k-1];
				arrayToSort[j] = temp;
				break;
			}
		}
	}
}