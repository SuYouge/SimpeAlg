#include "iostream"
#include "string"
#include "algorithm"
#include "cmath"
using namespace std;

/*质数判断需要注意0和1的情况*/

bool isprime(long long n) {
	bool flag = 1;
	/*下面两句不正确都有可能导致超时*/
	if (n == 0 || n == 1) return 0;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			flag = 0;
		}
	}
	return flag;
}

int main() {
	int l;//位数
	int k;//需要判断的位数
	string input;
	cin >> l >> k >> input;
	int flag = 0;
	for (int i = 0; i < input.length() - k + 1; i++) {
		long long temp = stoll(input.substr(i, k));
		if (isprime(temp)) {
			//cout << temp << endl;
			flag = 1;
			cout << input.substr(i, k);
			break;
		}
	}
	if (flag == 0) {
		cout << "404";
	}

	return 0;
}
