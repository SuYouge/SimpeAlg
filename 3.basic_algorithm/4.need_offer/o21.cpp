#include<bits/stdc++.h>
using namespace std;

/*
    奇数都在前面 偶数都在后面
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return nums;
        int left = 0, right = nums.size()-1;
        while(left<right){
            // if(left +1 == right) break;
            while(left<right && (nums[left]&1)==1){ // 结合性问题
                left++;
            }

            while (left<right && (nums[right]&1)==0){   
                right--;
            }

            if(left<right){
                // cout<<"交换"<<nums[left]<<" "<<nums[right]<<endl;
                // cout<<"at"<<left<<" "<<right<<endl;
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return nums;
    }
};

int main(){

    vector<int> input = {1,2,3,4};
    Solution so;

    auto o = so.exchange(input);
    for(auto d:o){
        cout<<d<<" "; 
    }
    cout<<endl;
    return 0;
}