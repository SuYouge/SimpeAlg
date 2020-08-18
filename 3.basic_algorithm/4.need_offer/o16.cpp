#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double ans = 1;
        long num = n;
        if(n < 0){
            num = -num;
            x = 1/x;
        }
        while(num){
            if(num & 1) ans *= x;
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};

int main(){
    // 快速幂
    Solution so;
    cout<<so.myPow(11, 2)<<endl;
    return 0;
}