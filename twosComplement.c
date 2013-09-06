#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long count_bits(long n) {     
  long c; // c accumulates the total bits set in v
  for (c = 0; n; c++) 
    n &= n - 1; // clear the least significant bit set
  return c;
  }  
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int testCases,i,j;
    int Positive[32];
    int Negative[32];
    int zero =0;
    scanf("%d",&testCases);
    for(i=1;i<=32;i++)
    {
        Positive[i] = count_bits(i);
    }
    for(i=1;i<=32;i++)
    {
        Negative[i] = count_bits(-i);
    }
    /*for(i=1;i<=32;i++)
    {
        printf("%d\n",Positive[i]);
    }
    for(i=1;i<=32;i++)
    {
        printf("%d\n",Negative[i]);
    }*/
    
    for(i=0;i<testCases;i++)
    {
        long num1,num2;
        unsigned long long count =0 ,x; 

        scanf("%ld%ld",&num1,&num2);
        for(j=num1;j<=num2;j++)
        {
            if(j>0)
            {
                if(j>32)
                {
                    if(j%32 ==0)
                    count +=1;
                    else
                    count+=Positive[j%32] +1;        
                }   
                else
                {
                    count += Positive[j];            
                }    
            }   
            else
            {
                if(j > -32)
                {
                    count += Negative[-j];            
                }   
                else
                {
                    if((-j)%32 ==0)
                    count += 31;
                    else
                    count += Negative[(-j)%32] -1;
                } 
            } 
            
        }
        
        
        printf("%llu\n",count);
    }
    
  
    return 0;
}
