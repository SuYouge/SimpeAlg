#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <climits>

using namespace std;

/*
计算键值：

哈希函数： int hash(int i, string s) 即给定位置和串长度求出哈希值
int reverse(int hash, string s) 由字符串和哈希值求出所在位置

假设小串长度为n， 大串长度为l

对于每一个小串都有可能出现在大串的0到(l-n+1)的位置上， 对每一个小串的每一个位置计算哈希值，以哈希值为键，小串为值插入map（unordered_map）。

接下来遍历大串，同样计算每个位置上长度为n的子串的hash值，得到一个向量H

创建一个长度为l的，初值为0的数组（字符串）F

遍历这个向量，检查map中是否有相应键值的元素，
    如果有相应的键值首先判断map中的元素小串是否与大串相应位置上的子串相同
    如果相同    
        根据小串值和哈希值反求位置，并将F中相应位置起始的n个元素+1（string updateF(string , int i , int n)）
        同时将小串值string形式插入set

遍历结束后开始判断
    首先set的大小不等于小串数目 就返回空
    然后遍历数组F找到长度为(n*小串数目)的全是1的子串位置并输出

O(n^2)级别
*/

int calKey(string s){
    int cnt =0;
    for(int i=0;i<s.size();i++){
        cnt = cnt + s[i];
    }
    return cnt;
}


vector<int> getKey(vector<string>& words){
    vector<int> key;
    for(int i=0;i<words.size();i++){
        int cnt = calKey(words[i]);
        key.push_back(cnt);
    }
    return key;
}

map<int,string> getstringtable(string s, int n){
    map<int,string> m;
    for(int i=0;i<(s.size()-n+1);i++){
        int key = calKey(s.substr(i,n));
        m.insert(make_pair(key,s.substr(i,n)));
        cout<<"key = "<<key<<" sub_str = "<<s.substr(i,n)<<endl;
        cout<<"\""<<i<<"\""<<endl;
    }
    return m;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.size()==0) return {}; // 如果s长度为空
        if(words.size()==0) return {}; // 如果words列表为空
        if(words[0].size()==0) return {}; // 如果words列表里都是空元素
        if(words[0].size()>s.size()) return {}; // 如果words列表里的元素长度都大于s，必不可能组成
        vector<int> key = getKey(words);
        map<int,string> table = getstringtable(s, words[0].size());

        for(int i=0;i<words.size();i++){
            auto loc = table.find(key[i]);
            if(loc!=table.end()){                
                cout<<"found : "<<words[i]<<endl;
            }
        }
        return key;
    }
};

int main(){

    // string s = "wordg";
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};

    Solution so;
    
    so.findSubstring(s,words);
    return 0;
}