#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int candyCal(int i,int *,int,int*);


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a[n],min;
    int candy[n];
    vector<int> minIndices;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        candy[i] = -1;
        
    }
    min = a[0];
    minIndices.push_back(0);
    for(int i=1;i<n;i++)
    {
       if(a[i] < min)
       {
           minIndices.clear();
           minIndices.push_back(i);
       }
        else if(a[i] == min)
        {
            minIndices.push_back(i);
        }
            
    }
    for(int i=0;i<minIndices.size();i++)
    {
        candy[i] == 1;
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(candy[i] == -1)
        {
            candy[i] = candyCal(i,a,n,candy);
        }
    }
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum += candy[i];
    }
    cout<<sum<<endl;
       return 0;
    }

int candyCal(int i,int *a ,int n,int* candy)
{
	if(candy[i] != -1) 
		return candy[i];
    if(i==0)
    {
        if(a[1] < a[0])
        {
            return candyCal(1,a,n,candy) + 1;
        }
        else
        {
            return 1;
        }
    }
    else if(i == n-1)
    {
        if(a[i] > a[i-1])
        {
            return candyCal(i-1,a,n,candy) + 1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
    if(a[i-1] < a[i])
    {
        if(a[i+1] < a[i])
        {
            return max(candyCal(i-1,a,n,candy),candyCal(i+1,a,n,candy)) +1;
        }
        else 
        {
            return candyCal(i-1,a,n,candy) + 1;
        }
    }
    else
    {
        if(a[i+1] < a[i])
        {
            return candyCal(i+1,a,n,candy) + 1;
        }
        else 
        {
            return 1;
        }
       
    }
    }
    
}
   
