#include <bits/stdc++.h>
using namespace std;

class sort_alg {
  public:
    virtual void sort(vector<int> &input) = 0;
    vector<int> data;
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void printv(vector<int> &input) {
        for (auto v : input) {
            cout << v << " ";
        }
        cout << endl;
    }
    void test() {
        data = {2, 8, 3, 0, 5};
        cout << "before sort : ";
        printv(data);
        sort(data);
        cout << "after sort : ";
        printv(data);
    }
};

/*
    冒泡排序：
        每次排1位，让目标（最大或最小）到最后面
        下一次排其余的部分
*/
class bubble : public sort_alg {
  public:
    void sort(vector<int> &input) {
        if (input.size() == 0)
            return;
        for (int i = 0; i < input.size() - 1; i++) {
            for (int j = 0; i + j < input.size() - 1; j++) {
                if (input[j] > input[j + 1])
                    swap(&input[j], &input[j + 1]);
            }
        }
    }
};

/*
    选择排序：
        每次让一位有序，从后面选最大（最小）和它交换
*/
class select_sort : public sort_alg {
  public:
    void sort(vector<int> &input) {
        if (input.size() == 0)
            return;
        int ind;
        for (int i = 0; i < input.size() - 1; i++) { // n个数字需要排n-1次
            ind = i;
            for (int j = i; j < input.size(); j++) {
                if (input[ind] > input[j]) {
                    ind = j;
                }
            }
            swap(&input[i], &input[ind]);
        }
    }
};

class insert_sort : public sort_alg {
  public:
    void sort(vector<int> &input) {
        if (input.size() == 0)
            return;
        int key;
        for(int i = 1;i<input.size();i++){
        // for(int i = input.size()-1;i>=0;i--){
            key = input[i];
            int j = i -1;
            while(j>=0 && input[j]>key){
                input[j+1] = input[j];
                j--;
            }
            input[j+1] = key;
        }
    }
};

int main() {
    // bubble sb;
    // sb.test();

    // select_sort ss;
    // ss.test();

    insert_sort is;
    is.test();

    return 0;
}