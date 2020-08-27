#include <iostream>
#include <cstdio>
using namespace std;

// 测试数组定义和初始化的位置对未初始化值的影响

// int arr[10]; // 0 0 0 0 0 0 0 0 0 0

int main() {

    int arr[10] = {1, 2}; // 1 2 0 0 0 0 0 0 0 0
    // int arr[10]; // -136422928 32767 0 0 1431652752 21845 1431652272 21845
    // -11888 32767

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int *)(&a + 1);
    printf("%d", *(p - 1));

    int c;
    c = 3*5, c = c*4;
    printf("%d",c);

    return 0;
}