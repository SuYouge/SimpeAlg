#include <iostream>
#include <map>
#include <stack>
using namespace std;
//由于未知原因运行程序会多一行1
//修改名称后编译可以正常输出
class Solution{
    public:
        bool isValid(string s){
            if(s.length()%2!=0) return false;
        map<char,char> wordbook;
        wordbook.insert(map<char,char>::value_type(')','('));
        wordbook.insert(map<char,char>::value_type('}','{'));
        wordbook.insert(map<char,char>::value_type(']','['));
        stack<char> mystack;
        for (int i=0;i<s.length();i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='(')
                mystack.push(s[i]);
            else if(s[i]==']'||s[i]=='}'||s[i]==')'){
                if(mystack.empty()) return false;
                if(wordbook[s[i]]== mystack.top()){
                    mystack.pop();
                    continue;
                }
                else return false;
            }
        } 
        if(mystack.empty()) return true;
        else return false;
        };
};
int main(){
    string str = "[[[[]]]]";
    Solution solution;
    bool ret = solution.isValid(str);
    cout<<ret<<endl;
    return 0;
};
