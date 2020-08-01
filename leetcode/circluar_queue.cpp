#include <iostream>
#include <vector>

using namespace std;

/*
    isEmpty()
    isFull()
    Front():isEmpty()
    Rear():isEmpty()
    enQueue():isEmpty(),isFull()
    deQueue():isEmpty(),head==tail
*/
class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        cout<<value<<" in queue"<<endl;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        cout<<"dequeue head = "<<head<<" tail = "<<tail<<endl;
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            cout<<data[head]<<" de queue"<<endl;
            cout<<"queue is Empty now"<<endl;
            head = -1;
            tail = -1;
            return true;
        }
        cout<<data[head]<<" de queue"<<endl;
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */


int main(){

    MyCircularQueue* circularQueue = new MyCircularQueue(5); // 设置长度为 3

    cout<<circularQueue->enQueue(5);  // 返回 true
    cout<<endl;
    cout<<circularQueue->enQueue(13);  // 返回 true
    cout<<endl;
    cout<<circularQueue->enQueue(8);  // 返回 true
    cout<<endl;
    cout<<circularQueue->enQueue(2);  // 返回 false，队列已满
    cout<<endl;
    cout<<circularQueue->enQueue(10);  // 返回 false，队列已满
    cout<<endl;
    // cout<<circularQueue->Rear();  // 返回 3
    // cout<<endl;
    // cout<<circularQueue->isFull();  // 返回 true
    // cout<<endl;
    // cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->enQueue(23);  // 返回 true
    cout<<endl;
    cout<<circularQueue->enQueue(6);  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    cout<<circularQueue->deQueue();  // 返回 true
    cout<<endl;
    return 0;
}