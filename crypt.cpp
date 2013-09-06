#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int testCases;
    set< char > alphabets;
    vector < char > colSpace;
    vector < char > keyRow;
    vector < char > keyRow1;
    map <char,char> mapping;
    cin>>testCases;
    string keyword;
    string data;
    string data1;
     for(int i=0;i<testCases;i++)
     {
         getline(cin,keyword);
         getline(cin,data);
     }
    data1 = data;
    data.erase(remove(data.begin(),data.end(),' '),data.end());
    for(int i=0;i<keyword.length();i++)
    {
        char c = keyword[i];
        const bool is_in = alphabets.find(c) != alphabets.end();

        if(!is_in)
        {
            alphabets.insert(c);
            keyRow.push_back(c);
        }
    }
    
    
    int num_col = keyRow.size();
    int num_rows = (alphabets.size()/num_col);
    
    for(int i=0;i<num_col;i++)
    {
        colSpace.push_back(keyRow[i]);
    }
    for(int i=0;i<data.length();i++)
    {
        char c = data[i];
        const bool is_in = alphabets.find(c) != alphabets.end();

        if(!is_in)
        {
            alphabets.insert(c);
            colSpace.push_back(c);
        }
    }
    
keyRow1 = keyRow;    
vector < vector <char> > newColSpace;
sort(keyRow1.begin(),keyRow1.end());
    vector< int > order;
for(int i=0;i<keyRow1.size();i++)
{
    char c = keyRow1.at(i);
    for(int j=0;j<keyRow1.size();j++)
    {
        if(keyRow1.at(j) ==c)
        {
            order.push_back(c);
            break;
        }
    }
}
vector <char> row[order.size()] ;
string abcd = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
for(int i =0 ;i<order.size();i++)
{
          int x = order.at(i);
            for(int k=0;k<num_rows;k++)
            {
                row[i].push_back(colSpace[k]);
                //mapping.insert(abcd.at(j),colSpace[k][x]); 
            }
}
for(int i =0 ;i<order.size();i++)
{
         sort(row[i].begin(),row[i].end());    
}

count =0;
 for(int i =0;i<order.size();i++)
 {
    for(int j=0;j<row[i].size();j++)
        {
            mapping.insert(abcd.charat(count),row[i].at(j))
            count++;    
        }
 }
        
for(int i =0;i<data1.size();i++)
{
    char x = data1.charat(i);
    if( == ' ')
    cout<<" ";
    else
    {
        cout<<*mapping.find(x);
    }
}
    cout<<endl;
    return 0;
}