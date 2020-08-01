/*统计下来6天大于6 7天大于7*/
#include "algorithm"
#include "vector"
#include "iostream"
#include "string"
#include "cstdio"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vi;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vi.push_back(temp);
	}

	sort(vi.begin(), vi.end(), greater<int>());
	auto now = -1;
	int flag = 0;
	for (auto it = vi.begin(); it != vi.end(); it++) {
		if (now != *it) {
			now = *it;
			//cout << now << endl;
			//cout << "distance is "<<distance(vi.begin(), it) << endl;
			if (distance(vi.begin(), it) == now) {
				cout << now;
				flag = 1;
				break;
			}
		}
	}
	if (flag != 1) {
		cout << now - 1;
	}
	
	return 0;
}