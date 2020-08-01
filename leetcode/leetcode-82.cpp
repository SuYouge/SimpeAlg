#include <iostream>
using namespace std;

class MyLinkedList {

private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x):val(x),next(nullptr){};
    };
    ListNode* head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* p = head;
        int i =0;
        while(p&&i<index){
            p = p->next;
            i++;
        }
        if(p) return p->val;
        else return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* p = new ListNode(val);
        if(head==nullptr){
            head = p;
            return ;
        }
        ListNode* q = head;
        while(q->next){
            q = q->next;
        }
        q->next = p;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val);
        if(index<=0){
            node->next = head;
            head = node;
            return ;
        }
        int i =0;
        ListNode* p = head;
        while(p&&i<index-1){
            p = p->next;
            ++i;
        }
        if(p){
            node->next = p->next;
            p->next = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0&&head!=nullptr){
            ListNode* del = head;
            head = head->next;
            delete del;
            return ;
        }
        int i=0;
        ListNode* p = head;
        while(p&&i<index-1){
            p = p->next;
            i++;
        }
        if(!p){
            return ;
        }
        if(p->next){
            ListNode* del = p->next;
            p->next = del->next;
            delete del;
        }
    }
    void print(){
        ListNode* p = head;
        int i=0;
        while(p){
            cout<<p->val<<" ";
            p = p->next;
            i++;
        }
        cout<<"length = "<<i<<endl;
    }

    // https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/si-chong-fang-fa-by-24shi-01fen-_00_01-2/
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1),*slow = dummy,*fast = head;
        dummy->next = head;
        while(fast!=NULL&&fast->next!=NULL){ //快指针用于查找相同元素
            if(fast->val!=fast->next->val) {                  
                if(slow->next == fast) slow = fast; //快指针先前没查找到相同数
                else slow->next = fast->next; //先前查找到相同数，将出现相同数的前一个数连接到相同数后第一个不同数 
            }
            fast = fast->next;
        }
        if(slow->next != fast) slow->next = fast->next; // 针对类似[1,1]的情况
        return dummy->next;
    }

    void deleteDuplicates_head(){
        head  = deleteDuplicates(head);
    }
};



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtTail(1);
    obj->addAtTail(1);
    // obj->addAtTail(3);
    // obj->addAtTail(3);
    // obj->addAtTail(4);
    // obj->addAtTail(4);
    // obj->addAtTail(5);
    obj->print();
    obj->deleteDuplicates_head();
    obj->print();

    return 0;
}