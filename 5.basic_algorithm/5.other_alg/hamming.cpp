#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x!=0||y!=0){
            if((x&1)!=(y&1)){
                res++;
            }
            x>>=1; 
            y>>=1;
        }
        cout<<res<<endl;
        return res;
    }
};

int main(){
    Solution so;
    so.hammingDistance(1,4);
    return 0;
}