#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a[n];
    int candy[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        candy[i] = 1;
    }
    int j,k;
    for(int i=0;i<n;i++)
    {
        j = i - 1;
        k = i + 1;
        if(j < 0)
        {
            if(a[k] < a[i])
                a[i] = a[k] + 1;
            continue;
        }
        if(k==n)
        {
            if(a[j] < a[i])
            {
                a[i] = a[j] +1; 
            }
            continue;
        }
        if(a[i] > a[k])
        {
            if(a[i] > a[j])
            {
                if(candy[k] > candy[j])
                    candy[i] = candy[k] + 1;
                else
                    candy[i] = candy[j] + 1;
            }
        }
        else
        {
            if(a[i] > a[j])
            {
                candy[i] = candy[j] + 1;
            }
        }
        
    }
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum +=candy[i];
    }
    cout<<sum;
}