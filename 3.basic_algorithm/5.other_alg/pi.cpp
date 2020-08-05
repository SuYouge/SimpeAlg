#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-6

/*
    x-x^3/3+x^5/5-x^7/7...
*/

double arctan(double x){
    double prev=1, res=0;
    int expo = x;
    double deno = 1.0;
    int sign = 1;
    double step = 1;
    double q = x*x;
    while(abs(step)>1e-6){
        step = (sign*expo)/deno;
        res += step;
        deno += 2.0;
        expo = expo * q;
        sign = -sign;
        prev = res;
    }
    return res;
}

void test_pi(){
    cout<<arctan(1.0)*4<<endl;
}

int main (){
    test_pi();
    cout<<atan(1)*4;
    return 0;
}