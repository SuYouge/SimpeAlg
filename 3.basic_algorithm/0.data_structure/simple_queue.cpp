#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    int tail;
    int head;
    int size;
    vector<int> data;
  public:
    /** Initialize your data structure here. Set the size of the queue to be k.
     */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation
     * is successful. */
    bool enQueue(int value) {
        bool res;
        if(isFull()){
            res = false;
        }else if(isEmpty()){
            head = 0;
            tail = 0;
            res = true;
            data[tail] = value;
        }else{
            tail = (tail+1)%size;
            data[tail] = value;
            res = true;
        }
        return res;
    }

    /** Delete an element from the circular queue. Return true if the operation
     * is successful. */
    bool deQueue() {
        bool res;
        if(isEmpty()){
            res = false;
        }else if(head == tail){ // 最后一个元素
            head = -1;
            tail = -1;
            res = true;
        }else{
            head = (head+1)%size;
            res = true;
        }
        return res;
    }

    /** Get the front item from the queue. */
    int Front() {
        int res;
        if(isEmpty()){
            res = -1;
        }else{
            res = data[head];
        }
        return res;
    }

    /** Get the last item from the queue. */
    int Rear() {
        int res;
        if(isEmpty()){
            res = -1;
        }else{
            res = data[tail];
        }
        return res;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() { return head == -1; }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return  ((tail+1)%size==head);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* obj = new MyCircularQueue(5);
    bool param_1 = obj->enQueue(5); // 5 0 0 0 0
    bool param_2 = obj->deQueue(); // 0 0 0 0 0
    int param_3 = obj->Front(); // -1
    int param_4 = obj->Rear(); // -1
    bool param_5 = obj->isEmpty(); // 1
    bool param_6 = obj->isFull(); // 0
    cout<<param_1<<endl;
    cout<<param_2<<endl;
    cout<<param_3<<endl;
    cout<<param_4<<endl;
    cout<<param_5<<endl;
    cout<<param_6<<endl;
    return 0;
}