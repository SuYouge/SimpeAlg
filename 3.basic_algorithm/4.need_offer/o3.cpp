#include <iostream>
#include <vector>
using namespace std;

/*
    数组中重复的数字

    在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
    数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
    请找出数组中任意一个重复的数字。

    n至少为2
    样例：{2, 3, 1, 0, 2, 5, 3};
*/

/*
    思路：如果数组有序则数字n应在第n个位置上
*/
class Solution {
  public:
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] !=
                   i) { // 只要当前的i上的数字不是自己的序号就一直交换
                if (nums[i] == nums[nums[i]]) { // 出现了重复
                    return nums[i];
                }
                int tmp = nums[i];       // 2
                nums[i] = nums[nums[i]]; // 1
                nums[tmp] = tmp;         // 使 nums[2] = 2
            }
        }
        return -1;
    }
    int countRange(vector<int> &nums, int start, int end) {
        int cnt = 0;
        for (auto n : nums) {
            if (n >= start && n <= end) {
                cnt++;
            }
        }
        return cnt;
    }
    // 第二种找出重复的问题，不修改原数组，不用额外的空间
    // 思路：长度为8的数组元素的范围是1-7，统计值为1-7的元素的个数大于7则表示有重复
    // 二分，将1-7分为两段，
    // 1-4和5-7，统计整个数组中1-4的数目，如果大于4则有重复
    int findRepeatNumber_t2(vector<int> &nums) {
        int start = 0;
        int end = nums.size();
        while (end >= start) {
            int middle = ((end - start) >> 1) + start;
            int count = countRange(nums, start, middle);
            if (end == start) {
                if (count>1)
                    return start;
                else
                    return -1;
            }
            if (count > (middle - start + 1)) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return -1;
    }
};

int main() {

    vector<int> input = {2, 3, 1, 0, 4, 3, 6};

    Solution so;

    cout << "repeat = " << so.findRepeatNumber(input) << endl;
    cout << "repeat = " << so.findRepeatNumber_t2(input) << endl;

    return 0;
}