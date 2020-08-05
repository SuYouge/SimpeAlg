#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
/*
vector 容器
vector<int> vector_name
题目：
给定一个整数数组nums和一个目标值target，在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };
};

int main(int argc, char *argv[])
{
	vector<int> nums = { 2, 7, 11, 15};
	int target = 9;
	Solution solution;
	vector<int> vec;
	vec = solution.twoSum(nums,target);
	std::cout<<nums[vec[0]]<<" is [i] and "<<nums[vec[1]]<<" is [j]."<<std::endl;
	return 0;
}
