#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
存在疑惑
https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/
*/

class Solution {

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows==0) return 0;
        int cols = matrix[0].size();
        // vector<vector<dp_unit>> dp(rows, vector<dp_unit>(cols,cols));
        // 比数组慢
        // vector<int> left(cols,0);
        // vector<int> right(cols,cols);
        // vector<int> height(cols,0);

        int left[cols];
        int right[cols];
        int height[cols];
        fill(left, left+cols, 0);
        fill(right, right+cols, cols);
        fill(height, height+cols, 0);

        int maxarea = 0;
        for(int i=0;i<rows;i++){
            int cur_left = 0, cur_right = cols;
            // 更新高度
            cout<<"height : ";
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
                cout<<height[j]<<" ";
            }
            cout<<endl;
            // 更新左边界
            cout<<"left : ";
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1') left[j] = max(left[j], cur_left);
                else{
                    left[j] = 0;
                    cur_left = j+1;
                }
                cout<<left[j]<<" ";
            }
            cout<<endl;
            // 更新右边界
            cout<<"right : ";
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else{
                    right[j] = cols;
                    cur_right = j;
                }
                cout<<right[j]<<" ";
            }
            cout<<endl;
            // 更新面积
            cout<<"area : ";
            for(int j = 0;j<cols;j++){
                maxarea = max(maxarea, (right[j]-left[j])*height[j]);
                cout<<(right[j]-left[j])*height[j]<<" ";
            }
            cout<<endl;
        }
        return maxarea;
    }
};


int main(){
    vector<vector<char>> matrix = {
                        {'1','0','1','0','1'},
                        {'1','0','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','0','0','1','0'}
                        };
    Solution so;
    cout<<so.maximalRectangle(matrix);
    return 0;
}