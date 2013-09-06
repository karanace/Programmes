#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int e,f,w;
		cin>>e>>f;
		w = f - e;
		int coins[w + 1];
		coins[0] = 0;
		int no_of_coins;
		int price[no_of_coins];
		int weight[no_of_coins];
		for (int j = 0; j < no_of_coins; ++j)
		{
			cin>>price[j];
			cin>>weight[j];
		}
		for (int j = 1; j <= w; ++j)
		{
				for (int k = 0; k < no_of_coins; ++k)
				{
					if(weight(k))
				}
		}



	}
	return 0;
}