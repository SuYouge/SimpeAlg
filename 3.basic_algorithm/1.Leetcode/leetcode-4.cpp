/*
第k小的元素问题
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int getKth(vector<int>& nums1,int start1, int end1 ,vector<int>& nums2,int start2, int end2,int k){

    int len1 = end1-start1 + 1;
    int len2 = end2-start2 + 1;

    if(len1>len2) return getKth(nums2,start2, end2, nums1, start1, end1, k);
    if(len1==0) return nums2[start2+ k-1];
    if(k==1) return min(nums1[start1], nums2[start2]);

    int i = start1 + min(len1,k/2) - 1;
    int j = start2 + min(len2, k/2) - 1;

    if(nums1[i]>nums2[j]){ // 这种情况下 j前面的部分都不要了
        return getKth( nums1, start1, end1, nums2, j+1 , end2, k-(j-start2+1));
    }else{//否则i前面的部分都不要了
        return getKth(nums1, i+1, end1, nums2,start2, end2,k-(i-start1+1));
    }

}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int left = (len1+len2+1)/2;
        int right = (len1+len2+2)/2; // 将两个数组合并后获得其中点
        return ((double)getKth(nums1, 0, len1-1,nums2,0,len2-1,left) +
             (double)getKth(nums1, 0, len1-1,nums2,0,len2-1,right))/2;
    }
};



int main(){

    vector<int> a = {1,2,4,5};
    vector<int> b = {2,5,6,8,9};
    multiset<int> s;
    for(auto vi = a.begin();vi!=a.end();vi++){
        s.insert(*vi);
    }
    for(auto vi = b.begin();vi!=b.end();vi++){
        s.insert(*vi);
    }

    for(auto vi = s.begin();vi!=s.end();vi++){
        cout<<*vi<<" ";
    }
    cout<<endl;
    Solution sol;

    cout<< sol.findMedianSortedArrays(a,b)<<endl;

    return 0;
}