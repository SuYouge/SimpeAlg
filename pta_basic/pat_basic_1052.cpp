#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "string"
using namespace std;

int process(string temp, string* list) {
	int start = 0;
	int flag = 0;
	int k = 0;
	int j = 0;
	for (int i = 0; i < temp.length(); i++) {
		if ((temp[i] == '[') && (flag == 0)) {
			//开始记录
			start = i;
			flag = 1;
		}
		else if ((temp[i] == ']') && (flag == 1)) {
			list[j] = temp.substr(start + 1, k);
			flag = 0;
			k = 0;
			j++;
		}
		else if (flag == 1) {
			k++;
		}
	}
	return j;
}

int main() {

	string temp;
	string list1[11];
	string list2[11];
	string list3[11];

	int len1, len2, len3;

	getline(cin, temp);
	len1 = process(temp, list1);
	//cout << "len1 is " << len1 << endl;
	getline(cin, temp);
	len2 = process(temp, list2);
	//cout << "len2 is " << len2 << endl;
	getline(cin, temp);
	len3 = process(temp, list3);
	//cout << "len3 is " << len3 << endl;
	int n;
	cin >> n;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int hand1, eye1, mouth, eye2, hand2;
		scanf("%d %d %d %d %d", &hand1, &eye1, &mouth, &eye2, &hand2);
		//cout << hand1 << " " << eye1 << " " << mouth << " " << eye2 << " " << hand2 << endl;
		if (((hand1 < 1) || (eye1 < 1) || (mouth < 1) || (eye2 < 1) || (hand2 < 1))) {
			flag = 1;
		}
		//检查输入合法性
		if ((hand1 > len1) || (hand2 > len1) || (eye1 > len2) || (eye2 > len2) || (mouth > len3) || (flag == 1)) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		else {
			cout << list1[hand1 - 1] << "(" << list2[eye1 - 1] << list3[mouth - 1];
			cout << list2[eye2 - 1] << ")" << list1[hand2 - 1] << endl;
		}
	}
	return 0;
}