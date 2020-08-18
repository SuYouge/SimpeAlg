#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
最长公共子序列

dp[i][j]
表示text1的前i个字符（不包括text1[i]）和text2的前j个字符（不包括text2[j]）
之前的最大子序列，目的是求dp[text1.size()][text2.size()];

dp[0][j] 表示空串和t2j的匹配，全部为0
dp[i][0] 表示空串和t1i的匹配，全部为0；

转移方程：
    if(text1[i]==text2[j]){
        dp[i+1][j+1] = max(dp[i][j], dp[i][j+1], dp[i+1][j]) + 1;
    else{
        dp[i+1][j+1] = max(dp[i][j], dp[i][j+1], dp[i+1][j])
    }
    }

*/

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        for (int i = 0; i <= text1.length(); i++) {
            vector<int> tmp(text2.length() + 1);
            dp.push_back(tmp);
        }
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        // for (auto v : dp) {
        //     for (auto d : v) {
        //         cout << d << " ";
        //     }
        //     cout << endl;
        // }
        return dp[text1.size()][text2.size()];
    };
};

int main() {

    string text1 = "ace", text2 = "babcde" ;
    // string text1 = "bsbininm", text2 = "jmjkbkjkv";
    Solution so;
    cout << so.longestCommonSubsequence(text1, text2);
    return 0;
}
