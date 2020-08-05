#include "iostream"
#include "string"
using namespace std;

int main() {
	string input;
	cin >> input;
	int total = 0;
	int len = input.length();
	int AP[100001] = { 0 };
	int pnum = 0;
	//从左边开始把每一个A左侧的P个数统计出来
	for (int i = 0; i < len; i++) {
		//cout << input[i] << endl;
		if (input[i] == 'P') {
			pnum+=1;
		}
		else if (input[i] == 'A') {
			AP[i] = pnum;
		}
		//cout << "AP[" << i << "]=" << AP[i] << endl;
	}

	//从右边开始加和 如果遇到
	//if A total = total + AP[i]*tnum;因为同一个A可以和右侧所有T组合 
	//if T tnum++
	int tnum = 0;
	for (int i = len - 1; i >= 0; i--) {
		//cout << input[i] << endl;
		if (input[i] == 'A') {
			//cout << "AP[" << i << "]=" << AP[i] << endl;
			total = (total + AP[i] * tnum)% 1000000007;	
		}
		else if (input[i] == 'T') {
			//cout << "AP[" << i << "]=" << AP[i] << endl;
			tnum += 1;
		}
	}
	cout << total % 1000000007;
	//cout << "max_size: " << input.max_size() << "\n";
	return 0;
}