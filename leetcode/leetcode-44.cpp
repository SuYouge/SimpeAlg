#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
c++版本在评论区
https://leetcode-cn.com/problems/wildcard-matching/solution/dong-tai-gui-hua-si-yao-su-by-a380922457-4/
*/

/*
dp[i][j]:
    s串的前i个和p的前j个匹配。
    dp[0][0] = true;
    对于s="aa", p="*"
    dp[0][1] = true --- 空串可以和空串匹配
    dp[1][0] = false --- ""+a 和""不可以匹配
    dp[1][1] = true --- ""+a 和""*可以匹配
    dp[2][0] = false --- ""aa 和""不可以匹配
    dp[2][1] = true --- ""aa 和""+* 可以匹配

    矩阵形式：
        p[0]    p[1]
s[0]    true,   true,
s[1]    false,  true,
s[2]    false,  true,

*/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0] = true;
        /* 初始化第一行,即和空串进行匹配 */
        for (int i = 1; i < plen + 1; i++)
        {
            if (p[i - 1] == '*' && dp[0][i - 1])
            {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i < slen + 1; i++)
        {
            for (int j = 1; j < plen + 1; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                }
            }
        }

        return dp[slen][plen];
    }
};

int main()
{
    string s = "acdcb";
    string p = "a*c?b";
    // string s = "aa";
    // string p = "*";

    Solution so;

    cout << so.isMatch(s, p) << endl;

    return 0;
}