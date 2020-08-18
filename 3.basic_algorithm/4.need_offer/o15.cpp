#include <iostream>
using namespace std;

// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         unsigned int flag = 1;
//         int cnt = 0;
//         int t = 0;
//         while(flag){
//             if(flag && n){
//                 cnt++;
//             }
//             t++;
//             flag<<=1;
//         }
//         cout<<t<<" 次循环"<<endl;
//         return cnt;
//     }
// };


class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n){
            n = (n-1)&n;
            cnt++;
        }
        return cnt;
    }
};

int main(){

    Solution so;
    cout<<so.hammingWeight(0x80000000);

    return 0;
}