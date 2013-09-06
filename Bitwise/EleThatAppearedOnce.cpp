/*
	*	Aim is to find element in a given array which contains all elements 3 times
	* except 1 , which we have to find
	Time Complexity O(N)
	Space Complexity O(1)
*/

#include <iostream>
#include <sstream>
using namespace std;
int iAppearedOnce(int *a,int size);
int main(int argc, char const *argv[])
{
	int ele[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	cout<<iAppearedOnce(ele,10)<<" appeared once in given array "<<endl;
	return 0;
}

int iAppearedOnce(int *a,int size)
{
	
}
