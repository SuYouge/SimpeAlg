#include <iostream>
#include <queue>
using namespace std;

int proc(int input) {
    queue<int> q;
    for (int i = 0; i < input; i++) {
        q.push(i);
    }
    // cout << endl;
    int cnt = 0;
    while (q.size() != 1) {
        if (cnt % 2 == 0 && cnt != 0) {
            // cout<<"pop "<<q.front()<<endl;
            q.pop();
            cnt = -1;
        } else {
            // cout<<"process "<<q.front()<<endl;
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    return q.front();
}

int main() {

    int input;
    while (1)
    {
        /* code */
        cin >> input;
        cout << proc(input) << endl;
    }

    return 0;
}