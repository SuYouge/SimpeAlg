#include <vector>
#include <iostream>

using namespace std;

/*
    动态规划：
        dp[i][j] 表示抵达当前点的路径数目，如果为0表示不可达；
        状态转移：
            （1）grid[i][j] = 1， 当前点上有障碍物则当前点不可达。
            （2）if(grid[i][j] != 1) dp[i][j] = dp[i-1][j]+ dp[i][j-1]
        初始化：
            遍历第一行和第一列， 只要遇到了障碍物则后面所有点都不再可达
        
*/

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<long>> dp(rows, vector<long>(cols, 0)); // int会溢出
        bool flag = false;
        for (int i = 0; i < cols; i++)
        {
            if (flag == true)
                dp[0][i] = 0;
            if (obstacleGrid[0][i] == 1)
            {
                dp[0][i] = 0;
                flag = true;
            }
            if (flag != true && obstacleGrid[0][i] != 1)
                dp[0][i] = 1;
            // cout<<dp[0][i]<<" ";
        }
        // cout<<endl;
        flag = false;
        for (int i = 0; i < rows; i++)
        {
            if (flag == true)
                dp[i][0] = 0;
            if (obstacleGrid[i][0] == 1)
            {
                dp[i][0] = 0;
                flag = true;
            }
            if (flag != true && obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            // cout<<dp[i][0]<<" ";
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    vector<vector<int>> obgrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    Solution so;
    cout << so.uniquePathsWithObstacles(obgrid);
    return 0;
}