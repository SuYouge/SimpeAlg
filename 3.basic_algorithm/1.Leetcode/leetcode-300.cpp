#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        vector<int> dp(nums.size());
        // fill(dp.begin(),dp.end(),1);
        dp[0] = 1;
        for(int i = 1;i<nums.size();i++){
            int max = 0;
            for(int j = i;j>=0;j--){
                if(nums[i] > nums[j]){
                    max = dp[j]>max ? dp[j] : max;
                }
            }
            dp[i] = max + 1;
        }
        auto it = max_element(dp.begin(),dp.end());
        // for(auto v:dp) cout<<v<<" ";
        // cout<<endl;
        return *it;
    }
};

int main(){

    vector<int> input{10,9,2,5,3,7,101,18};
    Solution so;
    cout<<so.lengthOfLIS(input);
    return 0;
}