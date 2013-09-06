#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int a[6] = {5,3,4,8,6,7};
	int max[6] ={1,1,1,1,1,1};
	for(int i=1;i<6;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j] <= a[i] && max[j] + 1 > max[i])
				max[i] = max[j] + 1;
		}
	}
	for(int i=0;i<6;i++)
	{
		cout<<max[i]<<endl;
	}

return 0;
}
