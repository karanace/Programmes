#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;

bool isSubsetSum(vi givenSet,int sum)
{
	cout<<"size is"<<givenSet.size()<<endl;
	bool subsetSum[sum+1][givenSet.size()+1];

	/*for Sum 0 Always True */
	for (int i = 0; i <= givenSet.size(); ++i)
	{
		subsetSum[0][i] = true;
	}

	/*If  Sum is not 0 and set is empty Always False */
	for (int i = 1; i <=sum; ++i)
	{
		subsetSum[i][0] = false;
	}

	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 1; j <= givenSet.size(); ++j)
		{
			/* code */
			subsetSum[i][j] = subsetSum[i][j-1];
			if(i >= givenSet[j-1])
			{
				subsetSum[i][j] = subsetSum[i][j] || subsetSum[i - givenSet[j-1]][j-1];
			} 

		}
	}
	for (int i = 0; i <= sum; i++)
	{
		for (int j = 0; j <= givenSet.size(); j++)
    	cout<<subsetSum[i][j]<<"\t";
    	cout<<endl;   
	}
	return subsetSum[sum][givenSet.size()];
    
 }
 int main()
{
	int a[] = {1,2,3,4,5,5};
  	vector<int> v(a,a+6); 

  int sum = 9;
  int n = v.size();
  if (isSubsetSum(v,sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}		