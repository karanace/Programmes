#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s= "haveaniceday";
    int minwidth,maxheight,height,width,i,j;
    int length = s.length();
    minwidth = floor(sqrt(length));
    maxheight = ceil(sqrt(length));
    width = minwidth;
    height = maxheight;
    cout<<s;
    cout<<"Min Width"<<minwidth<<endl;
    cout<<"Max Height"<<maxheight<<endl;
    if(width * height < length)
   	{
   		while(width * height < length)
    	{
    		width++;
    	}	
   	}
   	else if(height !=width)
   	{
   			height--;
   			width++;
   	}
   	cout<<"Width"<<width<<endl;
    cout<<"Height"<<height<<endl;
   	char encrypt[height][width];
   	int count=0;
   	for(i=0;i<height;i++)
   	{
   		for(j=0;j<width;j++,count++)
   		{
   			if(count >= length)
   			encrypt[i][j]='1';
   			else
   			encrypt[i][j]=s[count];
   		}
   	}

   for(i=0;i<width;i++)
   	{
   		for(j=0;j<height;j++)
   		{
   			if(encrypt[j][i] !='1')
   			printf("%c",encrypt[j][i]);
   		}
   		if(i !=width-1)
   		cout<<" ";
   	}
    


    
}