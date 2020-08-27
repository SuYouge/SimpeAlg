#include <iostream>

using namespace std;

/*
如何判断处理器是大端还是小端
*/

struct num {
    char l[4];
    int a;
};

void test_little() {
    int i = 1; // int占用4个字节
    char *p = (char *)&i;
    if (*p == 1)
        cout << "little endian" << endl;
    else
        cout << "big endian" << endl;
}

int main() {
    num x;
    x.a = 0x1234;
    cout << (int)x.l[3] << endl;
    // test_little();
    return 0;
}