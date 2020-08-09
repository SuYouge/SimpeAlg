#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* stringToListNode(vector<int> list) {
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* h = head;
        stack<int> s;
        while(h!=nullptr){
            s.push(h->val);
            h = h->next;
        }
        vector<int> res;
        while(s.size()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

void printv(vector<int> input){
    for(auto v : input){
        cout<<v<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> input = {1,9,3,4};
    ListNode* root = stringToListNode(input);
    Solution so;
    vector<int> res = so.reversePrint(root);
    printv(res);
    return 0;
}