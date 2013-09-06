/* Sample program illustrating input and output */

#include<iostream>
using namespace std;
int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   
   string s[N];   
   float x[N];
   float sorted[N];
    
    int isEmpty =1,size=0,flag;
    float result;
   
   for(int i = 0; i < N; i++){
      cin >> s[i] >> x[i];
      sorted[i] = 0; 
   }
   for(int i = 0; i < N; i++)
   {
      flag =1;
      if(s[i] == "r")
       {
           if(isEmpty)
           {
               cout<<"Wrong!"<<endl;
               //cout<<"Removing when empty"<<endl;
               flag=0;
           }
           
           else
           {
               for(int j=size-1;j>=0;j--)
               {
                   if(sorted[j] == x[i])
                   {
                       for(int k= j;j<size-1;j++)
                       {
                           sorted[k] = sorted[k+1];
                       }
                       size--;
                       break;

                  }
               }  
                       if(size ==0)
                           isEmpty =1;
                       if(!isEmpty)
                       {
                           if(size %2 ==0)
                           {
                               result = (sorted[size/2 -1] + sorted[size/2])/2;
                 //              cout<<"Removing makes even "<<endl;
                           }
                           else
                           {
                               result =sorted[(size-1)/2];
                   //            cout<<"removing makes odd "<<endl;
                           }
                       }
                   
                   else
                   {
                       cout<<"Wrong!"<<endl;
                       flag=0;
                   }
                   
               
           }
       }
       else
       {
           if(isEmpty)
           {
               sorted[size] = x[i];
               size++;
               isEmpty = 0;
               result = x[i];
               //cout<<"Add when empty"<<endl;
           }
           else
           {
               int j;
               for(j= size-1;size>=0;j--)
               {
                   
                   if(sorted[j]<=x[i])
                   {
                       for(int k=j+1;k<=size-1;k++)
                       sorted[k+1] = sorted[k]  ;  
                       break; 
                   }
               }
               sorted[j+1] = x[i];
               size++;
              if(size %2 ==0)
              {
                  result = (sorted[size/2 -1] + sorted[size/2])/2;
                 // cout<<"Adding makes even "<<endl;
              }
              else
              {
                  result =sorted[(size-1)/2];
                  //cout<<"Adding makes odd "<<endl;
              }
               
               }
                           
           }
           
       
       /*cout<<endl<<"Sorted Array till now\t";
       for(int p=0;p<size;p++)
       {
         cout<<sorted[p]<<"\t";
       }
       
       cout<<endl;
       */
       if(flag)
       cout<<result<<endl; 
   }
   return 0;
}