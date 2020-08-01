#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
    public:
        int romanToInt(string s){
        //unordered map 内部实现了一个哈希表
        unordered_map<char, int > mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int pos = 0, neg = 0;
        for (int i = 0;i< s.size()-1; ++i){
            if (mp[s[i]]<mp[s[i+1]])
                neg -= mp[s[i]];
            else
                pos += mp[s[i]];
        }
        pos += mp[s.back()];
        return pos + neg;
        }
};

int main(){
    string str = "IV";
    Solution solution;
    int ret = solution.romanToInt(str);
    cout<<ret<<endl;
    return 0;
}
