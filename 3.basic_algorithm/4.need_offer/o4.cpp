#include <iostream>
#include <vector>
using namespace std;

/*
数组特点：每一列都是增大的，每一行都是增大的

首先选取数组右上角的数字，
    如果该数字等于要找的数字，则过程结束
    如果该数字大于要查找的数字则删除这一列
    如果该数字小于要查找的数字则删除这一行
*/

class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        // 用col和row定位右上角
        if(matrix.size() == 0 || matrix[0].size()==0){
            return false;
        }
        int col = matrix[0].size()-1; // 范围大于0
        int row = 0;  // 范围小于等于 matrix.size()-1
        bool res = false;
        while(col>=0 && row<=matrix.size()-1){
            cout<<"matrix at row "<<row<<" col "<<col<<" ="<<matrix[row][col]<<endl;
            if(matrix[row][col] == target){
                res = true;
                break;
            }else if(matrix[row][col]>target){
                col = col - 1;
            }else{
                row = row + 1;
            }
        }
        return res;
    }
};

int main() {
    int target = 25;
    vector<vector<int>> m = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
    Solution so;
    cout<<"res = "<<so.findNumberIn2DArray(m, target);

    return 0;
}