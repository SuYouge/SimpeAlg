#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 暴力算法
        int n = prices.size();
        int max = -1;
        // int min = 0xffff;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(prices[j]>prices[i]){
                    int get = prices[j] - prices[i];
                    max = max<get? get:max;
                }
            }
        }
        if(max==-1) return 0;
        return max;
    }
    int maxProfit_2(vector<int>& prices) {
        // 暴力算法
        int n = prices.size();
        if(n==0) return 0;
        int max = 0;
        int min = prices[0];
        for(int i =0;i<n;i++){
            min = min > prices[i]? prices[i] : min;
            max = max < (prices[i]-min)? (prices[i]-min) : max;
        }
        return max;
    }
};

int main(){

    vector<int> input = {7,6,4,3,1};
    Solution so;

    cout<<so.maxProfit_2(input);

    return 0;
}