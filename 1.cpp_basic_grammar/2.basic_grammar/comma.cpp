#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> P;

int main(){
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({1,5});
    pq.push({2,4});
    pq.push({3,3});
    P top;
    top = pq.top(), pq.pop(); // 按顺序执行的逗号表达式
    cout<<"top = "<<top.first<<endl;
    pq.pop();
    top = pq.top();
    cout<<"top = "<<top.first<<endl;
    return 0;
}