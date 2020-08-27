#include <bits/stdc++.h>

using namespace std;

/*
42. 接雨水，单调递减栈
*/
class lt42 {
  public:
    int trap(vector<int> &height) {
        int sum = 0;
        stack<int> s;
        int current = 0;
        while (current < height.size()) {
            while (!s.empty() &&
                   height[current] > height[s.top()]) { // 当前高度大于栈顶
                int h = height[s.top()];
                cout << height[s.top()] << " pop out" << endl;
                s.pop();
                if (s.empty())
                    break;
                int dis = current - s.top() - 1;
                int minus =
                    min(height[current], height[s.top()]); // 此时的栈顶大于h
                sum = sum + (minus - h) * dis;
            }
            cout << height[current] << " in stack" << endl;
            s.push(current);
            current++;
        }
        return sum;
    }

    void test() {
        vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << "下雨之后能接 ：" << trap(input) << " 的雨水" << endl;
    }
};

// 单调递减栈
class lt496 {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // 利用第二个数组，构造每一个数对应的右侧更大元素
        stack<int> s;
        unordered_map<int ,int> m;
        for(int i =0;i<nums2.size();i++){
            while(!s.empty() && nums2[i]> s.top()){ // top比当前小
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            m[s.top()] = -1;
            s.pop();
        }
        vector<int> res;
        for(int i =0;i<nums1.size();i++)
            res.emplace_back(m[nums1[i]]);
        return res;
    }

    void test() {
        vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
        auto res = nextGreaterElement(nums1, nums2);
        for(auto r: res){
            cout<<r<<" ";
        }
    }
};

int main() {

    // lt42 a;
    // a.test();
    lt496 b;
    b.test();

    return 0;
}