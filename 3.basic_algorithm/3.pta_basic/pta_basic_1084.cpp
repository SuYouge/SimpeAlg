#include "string"
#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;

string process(string arr) {
	char temp = arr[0];
	string result;
	int cnt = 0;
	int len = arr.length();
	string add;
	int it = 0;
	for (int i = 0; i < len + 1; i++) {
		if (temp == arr[it]) {
			cnt += 1;
			it = it + 1;
		}
		else {
			add = temp + to_string(cnt);
			result = result + add;
			cnt = 0;
			temp = arr[it];
			cnt += 1;
			it = it + 1;
		}
	}
	//.substr(1,result.length()-1)
	return result;
}



int main() {
	string d;
	int n;
	cin >> d >> n;

	string arr = d;

	for (int i = 1; i < n; i++) {//
		arr = process(arr);
	}
	cout << arr;

	return 0;
}