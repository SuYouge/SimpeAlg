#include "string"
#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;

int main() {
	string d;
	int n;
	cin >> d >> n;

	string arr = d;
	char temp;
	int cnt;
	int len;
	int it;

	for (int i = 1; i < n; i++) {//
		temp = arr[0];
		string result;
		cnt = 0;
		len = arr.length();
		//string add;
		it = 0;
		for (int i = 0; i < len + 1; i++) {
			if (temp == arr[it]) {
				cnt += 1;
				it = it + 1;
			}
			else {
				result = result + temp + to_string(cnt);
				cnt = 0;
				temp = arr[it];
				cnt += 1;
				it = it + 1;
			}
		}
		arr = result;
	}
	cout << arr;

	return 0;
}