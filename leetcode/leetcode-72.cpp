#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
    每个单词有i,d,r三个操作，其中对A进行i相当于对B进行d，只要删除B中A缺少的那个即可
    同理对A进行d相当于对B进行i，只要删除A中B缺少的那个，或者对B插入A多出来的那个即可
    修改A或者修改B都是等价的
    以上操作有效的理由在于目的是让二者相同，
    dp[i][j]中保存A的前i个字符和B的前j个字符之间的编辑距离
    
    1.对于horse和ros， 假设horse到ro之间的编辑距离为X，则此时horse到ros之间的编辑距离即为X+1
    即dp[i][j] = dp[i][j-1]+1
    
    2.对于hors和ros，假设它们之间的编辑距离为Y， 则此时horse到ros之间的编辑距离即为Y+1（删除A的e或者增加B的e）
    即dp[i][j] = dp[i-1][j]+1
    
    3.对于hors和ro， 假设它们之间的编辑距离为Z，则先为hors经过Z步变为ro，再添加s，即不会超过Z+1步
    dp[i][j] = dp[i-1][j-1]+1，如果此时w1[i]==w2[j]，即最后一个字母本就相同，则可以减少1个距离

    整合以上：
    if(w1[i]!=w2[j]){
        dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
    }else{
        dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]-1);
    }

    边界初始化：
        dp[0][i] 从空串变成B[i]需要i步， d[i][0]从空串变成A[i]需要i步
表格，逻辑有误：
    https://blog.csdn.net/nicezheng_1995/article/details/104737742
*/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        if (n * m == 0)
            return n + m; // 如果n或m为空串
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < m + 1; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++)
            {
                int x = dp[i - 1][j]+1;
                int y = dp[i][j - 1]+1;
                int z = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                {
                    z+=1;
                }
                dp[i][j] = min(x, min(y, z));
            }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};

int main()
{

    string word1 = "zoologicoarchaeologist";

    string word2 = "zoogeologist";
    Solution so;
    cout << so.minDistance(word1, word2);
    return 0;
}