#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
  int coins[3],sum=100,x,y;
  coins[0]=1;
  coins[1]=3;
  coins[2]=5;
  int min[101]; 
  for(int i=0;i<=sum;i++)
  {
    min[i] = 100000;
  }
    min[0] = 0;

  /*for(int i=1;i<=sum;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(coins[j] <=i && min[i-coins[j]]+1 < min[i])
        min[i] = min[i-coins[j]]+1;
    }
  }*/

    for(x=0;x<=100;x++)
    {
      for(int i=0;i<3;i++)
      {
          y = x + coins[i];
          if(y<=sum && min[x] + 1 < min[y] )
           min[y] = min[x] +1;
      }  
    }
    
  for(int i=1;i<=sum;i++)
  {
    cout<<"Minimum Number of Coin Required for "<<i<<" is "<<min[i]<<endl;
  }
  return 0;
}