#include <iostream>
#include <stdlib.h>
using namespace std;
int mul(int x, int y) { 
    int result = 0;
    while (y) { 
        if (y&1)
            result += x;
        x <<= 1;
        y >>= 1;
    }
    return result;
}
double power(double x, int y) { 
    double z = 1.0;

    while (y > 0) {
        while (!(y&1)) {
            y >>= 2;
            x *= mul(x,x);
        }
        --y;
        z = mul(x,z);
    }
    return z;
}

int main(int argc, char const *argv[])
{
	cout<<power(5,4)<<endl;
}