#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<string>> phone = {
    {"a","b","c"},
    {"d","e","f"},
    {"g","h","i"},
    {"j","k","l"},
    {"m","n","o"},
    {"p","q","r","s"},
    {"t","u","v"},
    {"w","x","y","z"}
};

vector<string> fuse(vector<string> v1, vector<string> v2){
    vector<string> ret;
    for(auto vi1 = v1.begin(); vi1!=v1.end(); vi1++){
        for(auto vi2 = v2.begin(); vi2!=v2.end(); vi2++){
            string tmp = *vi1 + *vi2;
            ret.push_back(tmp);
        }
    }
    return ret;
}

vector<string> fun(int n, string s){
    string sub = s.substr(0,n);

    if(n==1) {
        return phone[s[0]-'0'-2];
    }
    vector<string> vec = fun(n-1, s);

    vector<string> ret;
    for(int i=0;i<sub.size();i++){
        ret = fuse(vec, phone[s[n-1]-'0'-2]);
    }

    return ret;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        return fun(digits.size(),digits);
    }
};


int main(){

    string s = "23";

    Solution so;
    auto output = so.letterCombinations(s);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }

    return 0;
}