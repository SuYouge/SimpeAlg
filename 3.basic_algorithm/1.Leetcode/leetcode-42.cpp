#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
每一个柱子的高度方向可以接的雨水的数量 = min(从当前柱子向左看的最高柱子高度, 从当前柱子向右看的最高柱子高度) - 当前柱子高度
https://leetcode-cn.com/problems/trapping-rain-water/solution/javazui-jian-dan-jie-fa-chao-ji-yi-li-jie-yong-shi/
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if(length==0) return 0;
        int left[length];
        int right[length];
        int leftMax = 0;
        int rightMax = 0;
        int sum =0;

        //计算left和right数组
        for (int i = 0; i < length; i++) {
            if (height[i] > leftMax) {
                leftMax = height[i];
            }
            left[i] = leftMax;
            if (height[length-1-i] > rightMax) {
                rightMax = height[length-1-i];
            }
            // cout<<rightMax<<" ";
            right[length-1-i] = rightMax;
        }
        // cout<<endl;
        // 只有当height[i]的高度，比left[i]和right[i]都要小的时候才能接住雨水（否则总有一边会漏，接不到雨水）
        //遍历，只有当前柱子往左看、往右看的最高柱子都比当前柱子高，才能接住雨水
        for (int j = 0; j < length; j++) {
            if (height[j] < left[j] && height[j] < right[j]) {
                sum = sum + min(left[j], right[j]) - height[j];
            }
        }
        return sum;
    }
};


int main(){

    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution so;
    cout<<so.trap(input)<<endl;

    return 0;
}