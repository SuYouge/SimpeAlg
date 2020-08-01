#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size();i++){
            int start = i + 1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum)<abs(target - ans))
                    ans = sum;
                if(sum>target)
                    end--;
                else if (sum<target)
                    start++;
                else return ans;
            }
        }
        return ans;
    }
};

int main(){

    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution so;
    cout<<so.threeSumClosest(nums, target);

    return 0;
}