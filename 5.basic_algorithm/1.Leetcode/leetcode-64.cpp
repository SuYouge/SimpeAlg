#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    dp[i][j]保存左上和右上中的最小值
*/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<long>> dp(rows, vector<long>(cols, 0)); // int会溢出

        /* 遍历第一行 */
        dp[0][0] = grid[0][0];
        for (int i = 1; i < cols; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < rows; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        /**/
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

int main()
{

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    Solution so;
    cout << so.minPathSum(grid);
    return 0;
}