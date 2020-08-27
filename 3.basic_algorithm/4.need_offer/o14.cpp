#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cuttingRope(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            int maxi = -1;
            for (int j = 1; j <= i / 2; j++) {
                // 4种 dp[i] dp[n-i]
                int k = i - j;
                maxi = max(maxi, dp[j] * k);
                maxi = max(maxi, j * dp[k]);
                maxi = max(maxi, j * k);
                maxi = max(maxi, dp[j] * dp[k]);
            }
            dp[i] = maxi;
        }
        // for(auto d:dp)
        //     cout<<d<<" ";
        // cout<<endl;
        return dp[n];
    }
};

int main() {
    Solution so;
    cout << so.cuttingRope(10);
    return 0;
}