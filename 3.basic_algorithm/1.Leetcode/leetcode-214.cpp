#include <bits/stdc++.h>
using namespace std;

int brutalmatch(string a, string b) {
    int lena = a.length();
    int lenb = b.length();
    int i = 0;
    int j = 0;

    while (i < lena && j < lenb) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0; // j = next[j];
        }
    }

    if (j == lenb) {
        return i - j;
    } else {
        return -1;
    }
}

class Solution {
public:
void getnext(string p, vector<int> &next) {
    int lenp = p.length();
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < lenp - 1) {
        if (k == -1 || p[j] == p[k]) 
		{
			++k;
			++j;
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
				next[j] = next[k];
		}
		else 
		{
			k = next[k];
		}
    }
    return;
}

int kmp(string a, string b) {
    vector<int> next(b.length());
    int lena = a.length();
    int lenb = b.length();
    int i = 0;
    int j = 0;
    getnext(b, next);
    while (i < lena && j < lenb) {
        if (j == -1 || a[i] == b[j]) { // 表示第一次开始或者重新开始匹配
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    // if (j == lenb) {
    //     return i - j;
    // } else {
    //     return -1;
    // }
    return j;
}
public:
    string shortestPalindrome(string s) {
        if(s.length()==0) return "";
        string b = s;
        reverse(b.begin(),b.end());
        int end = kmp(b,s);
        string tmp = b.substr(0, s.length()-end);
        return tmp+s;
    }
};

int main() {

    return 0;
}