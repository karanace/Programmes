#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
string myAdd(int len,unsigned long *mya,unsigned long *myb)
{
	string result;
	//int len = a.size();
	int carry = 0;
	int sum;
	int lenby32=len/32;
	unsigned long a,b;
	unsigned long long x;
	cout<<"len by 32"<<lenby32<<endl;
	for (int i = 0; i <=lenby32; ++i)
	{
		x = mya[i] + myb[i];
		cout<<"myai is "<<mya[i]<<endl;
		cout<<"mybi is "<<myb[i]<<endl;
		cout<<"x is "<<x<<endl;
	}
	for (int i = 0; i <len; i++)	//Starting from LSB
	{
		sum = (mya[i] ^ myb[i] ^ carry) + '0'; //Sum is xor of all 3 bits + adding ascii of '0'
		result = result + (char)sum   ; //Updating result string
		carry = (mya[i] & myb[i]) |(mya[i] &carry) |(myb[i] & carry);	//Updating carry 
	}
	if(carry)	//Overflow case 
		result =  '1' + result  ;	//Adding one of carry
	return result;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    int nby32 = n/32;
    cin>>n>>q;
    string a,b,c;
    cin>>a;
    cin>>b;
    int x,y;
    unsigned long long sum ;
    unsigned long mya[nby32];
    unsigned long myb[nby32];
    for (int i = 0; i <= nby32; ++i)
    {
    	mya[i] = 0;
    	myb[i] = 0;
    }
    /*for (int i = 0; i <n; ++i)
    {
    	x = i / 32;
    	y = i % 32;
    	if(a[n-i-1] - 48)
    	mya[x] = mya[x] |  1<<y;
    	if(b[n-i-1] - 48)
    	myb[x] = myb[x] |  1<<y;
    }*/
    
    string query;
    int index,indexby32;
    int val;
    for(int i=0;i<q;i++)
    {
        cin>>query;
        cin>>index;
        indexby32 = index/32;
        if(query.compare("set_a") == 0)
        {
            cin>>val;
            //cout<<"Hello"<<endl;
            if(val)
            mya[indexby32] = mya[indexby32] & 1<<(index%32);
        	else
        	mya[indexby32] = mya[indexby32] | ~(1<<(index%32));
            //cout<<"mya :"<<mya[index]<<endl;
        }
        if(query.compare("set_b") == 0)
        {
            cin>>val;
            if(val)
            myb[indexby32] = myb[indexby32] & 1<<(index%32);
        	else
        	myb[indexby32] = myb[indexby32] | ~(1<<(index%32));
            //cout<<"myb :"<<myb[index]<<endl;
        }
        if(query.compare("get_c") == 0)
        {
                //cout<<c.size();
                c = myAdd(n,mya,myb);
                if(index<c.size())
                cout<<c.at(c.size()-1-index);
                else
                cout<<0;
                //cout<<"c :"<<c<<endl;
                
        }    
            
    }
    return 0;
}
