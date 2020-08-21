#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return int整型
     */
    int climbStairs(int n) {
        // write code here
        if(n==1) return 1;
        if(n==2) return 2;
        int a1 = 1;
        int a2 = 2;
        for(int i = 2;i<n;i++){
            int tmp = a2;
            a2 = a1 + a2;
            a1 = tmp;
        }
        return a2;
    }
};

int main(){
    Solution so;
    cout<<so.climbStairs(4)<<endl;
    return 0;
}