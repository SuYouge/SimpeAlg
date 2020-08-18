#include <iostream>
#include <set>
using namespace std;

string solution(string input) {
    string res;
    set<char> se;
    for (auto v : input) {
        if (se.count(v) == 0) {
            cout << v;
            se.insert(v);
        }
    }
    return res;
}

int main() {
    string input;
    while (cin >> input) {
        solution(input);
        cout << endl;
    }
    return 0;
}