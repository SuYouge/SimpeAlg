#include "iostream"
using namespace std;

int list[1000] = { 0 };

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int total = 0;
		for (int j = 0; j < temp.length(); j++) {
			//cout << temp[i] << endl;
			total = total + temp[j] - '0';
		}
		//cout << total << endl;
		if (list[total] == 0) list[total] = 1;
		if (list[total] == 1) { list[total] = 2; cnt += 1; }
	}
	int flag = 0;
	cout << cnt << endl;
	for (int i = 0; i < 999; i++) {
		if ((list[i] == 2) && (flag != 1)) {
			flag = 1;
			cout << i;
		}
		else if ((list[i] == 2) && (flag == 1)) {
			cout << " " << i;
		}

	}
	return 0;
}