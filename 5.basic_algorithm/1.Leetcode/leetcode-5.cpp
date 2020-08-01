/*
动态规划：
    dp[i][j] 表示s[i]至s[j]是否是回文串， 是则为1，不是则为0
    状态转移：
        （1）若s[i]==s[j]， 那么只要s[i+1]至s[j-1]是回文串，s[i]至s[j]就是回文串
        若s[i+1]至s[i-1]不是回文串， s[i]到s[j]必不是回文串
        （2）若s[i]!=s[j]，s[i]到s[j]必不是回文串

        if(s[i]==s[j]){
            dp[i][j] = dp[i+1][j-1]
        }else{
            dp[i][j] = 0;
        }

*/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        int ans = 1;
        // vector<vector<bool >> dp(len,vector<bool>(len,false));
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        int start = 0;
        /* 首先根据相邻的两个字符添加临界状态 */
        for (int i = 0; i < len; i++)
        {
            // if(len>1) start = 1;
            dp[i][i] = 1;
            if (i + 1 < len)
            {
                if (s[i] == s[i + 1])
                {
                    start = i;
                    dp[i][i + 1] = 1;
                    ans = 2; //
                }
            }
        }
        /* 为避免状态转移失败， 按照子串的长度进行遍历 */
        for (int L = 3; L <= len; L++)
        {
            for (int i = 0; i + L < len + 1; i++)
            {
                int j = i + L - 1; // 子串的右端点
                // printf("s[%d]-%c-s[%d]-%c-dp[%d][%d]=%d \n",i,s[i], j,s[j] ,i+1,j-1 ,dp[i+1][j-1]);
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    // printf("next state : %d \n", dp[i][j]);
                    start = i;
                    ans = L;
                }
            }
        }
        printf("start : %d - ans : %d \n", start, ans);
        return s.substr(start, ans);
    }
};

int main()
{

    string s = "cbbd";

    Solution sol;

    cout << sol.longestPalindrome(s);

    return 0;
}