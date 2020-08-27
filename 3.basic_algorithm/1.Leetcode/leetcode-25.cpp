#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode *makeList(vector<int> &input) {
    ListNode *dummy = new ListNode(0);
    ListNode *ptr = dummy;
    for (int item : input) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummy->next;
    delete dummy;
    return ptr;
}

class Solution {

  public:
    pair<ListNode *, ListNode *> reverseall(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return make_pair(tail, head);
    }

  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while (head) {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            ListNode *nex = tail->next; // 保存下一段的头节点
            pair<ListNode *, ListNode *> res = reverseall(head, tail);
            head = res.first;
            tail = res.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};

void printlist(ListNode *head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    if (head->next != nullptr)
        cout << head->val << "->";
    else
        cout << head->val;
    printlist(head->next);
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode *head = makeList(input);
    printlist(head);
    Solution so;
    ListNode *res = so.reverseKGroup(head, 3);
    printlist(res);
    return 0;
}
