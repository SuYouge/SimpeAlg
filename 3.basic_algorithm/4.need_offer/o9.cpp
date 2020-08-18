#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> s1; // 插入都向s1，要弹出的在栈底
    stack<int> s2; // 删除过程借助s2进行，如果s2是空的就检查s1，如果s1也是空的就返回失败
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s2.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()){
            return -1;
        }else{
            int res = s2.top();
            s2.pop();
            return res;
        }
    }
};


int main(){
    int value = 1;
    CQueue* obj = new CQueue();
    obj->appendTail(value);
    int param_2 = obj->deleteHead();
    cout<<param_2<<endl;
    cout<<int(2001>>1)<<endl;
    return 0;
}