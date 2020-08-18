#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        if(n==1) return 0;
        if(n%2==0){
            int d = n/2;
            return d*d;
        }else{
            int d = (n-1)/2;
            return d*(d+1);
        }
    }
};

int main(){

    Solution so;
    cout<<so.minOperations(7);

    return 0;
}