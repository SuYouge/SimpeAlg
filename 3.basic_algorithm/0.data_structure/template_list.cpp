#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr){};
};

// ListNode *makeList(vector<int> &input) {
//     ListNode *dummy = new ListNode(0);
//     ListNode *ptr = dummy;
//     for (int item : input) {
//         ptr->next = new ListNode(item);
//         ptr = ptr->next;
//     }
//     ptr = dummy->next;
//     delete dummy;
//     return ptr;
// }

ListNode *makeList(vector<int> &input) {
    if (input.size() == 0)
        return nullptr;
    ListNode *dummy = new ListNode(0);
    ListNode *tmp = dummy;
    for (auto i : input) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    // delete tmp;
    tmp = dummy->next;
    delete dummy;
    return tmp;
}

void printList(ListNode *head) {
    if(head== nullptr){
        return ;
    }
    if (head->next == nullptr) {
        cout << head->val;
        return;
    }
    cout << head->val << " -> ";
    printList(head->next);
    return;
}

ListNode *getKth(ListNode *head, int k) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return k == 1 ? head : nullptr;
    ListNode *res = head;
    for (int i = 1; i < k; i++) {
        if (res->next != nullptr) {
            res = res->next;
        } else {
            return nullptr;
        }
    }
    return res;
}

// 删除非头节点
void deleteNode(ListNode *node) {
    if (node == nullptr)
        return;
    if (node->next == nullptr) {
        node = nullptr;
        return;
    }
    // cout<<"delete "<<node->val;
    node->val = node->next->val;
    ListNode *tmp = node->next->next;
    // delete node->next;
    ListNode *n = node->next;
    delete n;
    node->next = tmp;
    return;
}

ListNode* deleteDuplicates_2(ListNode* head) { // 删到不重复
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy->next;
        while(prev && prev->next){
            ListNode* curr = prev->next;
            if(curr->val != prev->val){
                prev = curr;
            }else{
                while(curr && curr->val == prev->val){ // 直到不重复为止
                    if(curr->next)
                        curr = curr->next;
                    else
                        curr = nullptr;
                }
                if(curr) prev->next = curr; 
                else prev->next = nullptr;
            }
        }
        return dummy->next;
    }

ListNode *deleteDuplicates(ListNode *head) { // 删掉所有重复的
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    // unordered_map<int, int> m;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy; // prev始终指向没有重复的节点
    while(prev&& prev->next){
        ListNode* curr = prev->next;
        // 如果curr到了最后一位，或者当前curr所指的元素没有重复值
        if(!curr->next||curr->next->val != curr->val)
            prev = curr;
        else
        {
            while(curr->next && curr->val == curr->next->val){
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        
    }
    return dummy->next;
}

void traverse(ListNode* head){
    while(head){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    return ;
}

int main() {

    // vector<int> input = {1, 2, 3, 4, 5, 6};
    vector<int> input = {1,1};

    ListNode *head = makeList(input);
    ListNode* res = deleteDuplicates(head);
    
    // traverse(res);
    printList(res);
    // cout << endl;

    // ListNode *kth = getKth(head, 4);
    // deleteNode(kth);
    // printList(head);
    // cout << endl;

    return 0;
}
