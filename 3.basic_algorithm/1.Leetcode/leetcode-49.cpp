#include<string>
#include<unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

public:
    int hashcode(string s){
        int total = 0;
        sort(s.begin(),s.end());
        for(int i =0;i<s.size();i++){
            total = total+ (int)s[i]*(i+1)*(int)s[i]*(i*i+1);
        }
        // if(s=="tho"||s=="pay") cout<<"hash :"<<total<<endl;
        return total;
    }
// public:
//     bool check(vector<string> v, string s){
//         for(int i=0;i<v.size();i++){
//             if(v[i]==s) return true;
//         }
//         return false;
//     }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> m;
        for(int i=0;i<strs.size();i++){
            int code = hashcode(strs[i]);
            // cout<<code<<endl;
            if(m.count(code)==0) m.insert({code, {strs[i]}});
            // else if(check(m[code],strs[i])) continue;
            else m[code].push_back(strs[i]);
        }
        vector<vector<string>> output;
        for(auto vi = m.begin();vi!=m.end();vi++){
            // vector<string> tmp;
            // for(int i=0; i<vi->second.size();i++){
            //     tmp.push_back(vi->second[i]);
            // }
            output.emplace_back(vi->second); // 精髓
        }
        // cout<<m.size()<<endl;
        return output;
    }
};

int main(){
    
    vector<string> strs = {"tho","tin","erg","end","pug","ton",
                        "alb","mes","job","ads","soy","toe","tap","sen",
                        "ape","led","rig","rig","con","wac","gog","zen",
                        "hay","lie","pay","kid","oaf","arc","hay","vet","sat",
                        "gap","hop","ben","gem","dem","pie","eco","cub","coy","pep","wot","wee"};
    // vector<string> strs = {"ola","wow","ave","fey","pin","soy","pat","lee","dot","lot","bet","pug","hex","nip","lbj","pod","lea","han","nub","mel","rca","son","far","cot","mad","pyx","web","ply","ark","ere","tut","jog","wed","maj","jon","lag","mar","ina","noh","qom","ifs","mom","fox","and","cog","buy","con","ivy","coy","can","any"};
    Solution so;
    auto out = so.groupAnagrams(strs);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
    // [   ["wot"],["pep"],["coy"],["pie"],["dem"],["wee"],["gem"],["ben"],["gap"],["sat"],
    //     ["arc"],["kid"],["soy"],["ads"],["ton"],["hop"],["mes"],["job"],["zen"],["alb"],
    //     ["tin"],["led"],["end"],["hay","hay"],["tho","pay"],["erg"],["oaf"],["tap"],
    //     ["rig","rig"],["lie"],["toe"],["cub"],["sen"],["pug"],["con"],["vet"],["ape"],["wac"],["eco"],["gog"]]
    return 0;
}