#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", n, n);
        return res;
    }

    void func(vector<string> &res, string str, int l, int r){
        if(l == 0 && r == 0){
            res.push_back(str);
            return;
        }
        if(l > 0){
            func(res, str + '(', l-1, r);
        }
        if(r > 0 && r > l){
            func(res, str + ')', l, r-1);
        }
        return;
    }
};

int main(){

    int n = 3;

    Solution so;

    auto output = so.generateParenthesis(n);

    for(int i =0;i< output.size();i++){
        cout<<output[i]<<endl;
    }

    return 0;
}