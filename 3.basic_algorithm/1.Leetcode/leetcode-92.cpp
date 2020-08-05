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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p =  head;
        dummy ->next = head;
        int i =0;
        ListNode* a = dummy;
        while(p&&i<n-1){
            if(i>=m-1){
            cout<<"case 1 "<<"a :"<<a->val<<" p : "<<p->val<<endl;
                ListNode* next = p->next->next;
                p->next->next = a->next;
                a->next = p->next;
                p->next = next;
            }else{
            cout<<"case 2 "<<"a :"<<a->val<<" p : "<<p->val<<endl;
                a = a->next;
                p = p->next;
            }
            i++;
        }
        return dummy->next;
    }
    void reverseBetween_head(int m , int n){
        head = reverseBetween(head, m, n);
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
    obj->addAtTail(2);
    obj->addAtTail(3);
    // obj->addAtTail(4);
    // obj->addAtTail(5);
    obj->print();
    // obj->rotateRight_head(2);
    obj->reverseBetween_head(1,2);
    obj->print();
    // obj->swapPairs_head();
    // obj->print();
    return 0;
}