#include "iostream"
#include "string"
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		int start = 0;
		int flag = 1;
		int cnt = 0;
		int end = input.length() - 1;
		for (int j = 0; j < input.length(); j++) {
			if ((input[j] != 'P') && (input[j] != 'A') && (input[j] != 'T')) {
				flag = 0;
				break;
			}
			else {
				//找到P和T
				if ((input[j] == 'P') && (start == 0)) {
					start = j;
					//cnt += 1;
				}
				else if ((input[j] == 'P') && (start != 0)) {
					//两个P
					flag = 0;
					break;
				}
				else if ((input[j] == 'T') && (start != 0)) {
					//cout << "END in " << j << endl;
					end = j;
					break;
				}
				else if ((input[j] != 'T') && (start != 0)) {
					cnt += 1;
				}
			}
		}
		if (end == start + 1) flag = 0;
		//check()
		string sec = input.substr(start + 1, (end - start - 1));
		int A_cnt = 0;
		for (int i = 0; i < (end - start - 1); i++) {
			if (sec[i] != 'A') {
				flag = 0;
				break;
			}
			else {
				A_cnt += 1;
			}
		}
		string temp = input.substr(0, (start));
		for (int i = 1; i < A_cnt; i++) {
			temp = temp + input.substr(0, (start));
		}

		if (temp != input.substr(end + 1, (input.length() - (start + cnt + 1)))) flag = 0;

		if (flag == 1) {
			cout << "YES" << endl;
		}
		else if (flag != 1) cout << "NO" << endl;
	}
	return 0;
}