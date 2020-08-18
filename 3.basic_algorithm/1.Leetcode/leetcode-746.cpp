#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

  public:
    int minCostClimbingStairs(vector<int> &cost) {
        if (cost.size() == 0) {
            return 0;
        }
        if (cost.size() == 1)
            return cost[0];
        vector<int> dp(cost.size());
        dp[0] = 0;
        // printf("dp[0] = %d\n",dp[0]);
        dp[1] = min(cost[1], cost[0]);
        // printf("dp[1] = %d\n",cost[1]);
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 2] + cost[i - 1], dp[i - 1] + cost[i]);
            // printf("dp[%d] = %d\n",i,dp[i]);
        }
        return dp[cost.size()-1];
    }
};

int main() {
    // vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost = {1, 1, 1, 0};
    // vector<int> cost = {10,15,20};
    Solution so;
    cout << "res = " << so.minCostClimbingStairs(cost);
    return 0;
}