#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0; // 数组为空
        if(nums.size()==1) return 1; // 数组里只有一个数字
        int i=0;
        auto j = nums.begin()+1;
        while(j!=nums.end()){ // j遍历nums
            if(*j == nums[i]){ // 如果j和当前的i值相同
                nums.erase(j); // 删除这个值,很不安全
            }else{
                i = distance(nums.begin(), j); //             j++;
                j = nums.begin()+i+1;
            }
        }
        cout<<endl;
        return nums.size();
    }
};


int main(){

    vector<int> input = {1,1,2};
    Solution so;
    cout<<so.removeDuplicates(input)<<endl;
    return 0;
}