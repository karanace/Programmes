#include<stdio.h>
void bubble_sort(int *arrayToSort,int sizeOfArray);
void main()
{
	int a[5] ={73,24,51,12,11};
	int n=5,i;
	bubble_sort(a,5);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i!=n-1)
			printf("\t");
		else
			printf("\n");
	}
}
void bubble_sort(int *arrayToSort,int sizeOfArray)
{
	int i,j,temp;
	for(i=0;i<sizeOfArray;i++)
	{
		for(j=0;j<sizeOfArray-i-1;j++)
		{
			if(arrayToSort[j+1] <arrayToSort[j])
			{
				temp = arrayToSort[j+1];
				arrayToSort[j+1] = arrayToSort[j];
				arrayToSort[j] = temp;
			}
		}
	}
}