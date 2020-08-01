#include "iostream"
#include "string"
using namespace std;
int main() {

	string broken;
	getline(cin, broken);

	int list[128] = {0};

	int cap_flag = 0;

	for (int i = 0; i < broken.length(); i++) {
		list[broken[i]] = 1;
		if (broken[i] == '+') {
			cap_flag = 1;
		}
	}


	string input;
	cin >> input;

	//for (int i = 0; i < 128; i++) {
	//	if (list[i] == 1) {
	//		cout << (char)i;
	//	}

	//}
	//cout << endl;

	int output_flag = 0;

	for (int i = 0; i < input.length(); i++) {
		int temp;
		temp = input[i];
		if ((temp >= 'a') && (temp <= 'z')) {//小写转大写
			temp = temp - ('a'-'A');
			//cout << "检查值 " << temp << endl;
		}
		if (list[temp] == 1) continue;
		else if ((cap_flag == 1) && ((input[i] >= 'A') && (input[i] <= 'Z'))) continue;
		else {
				cout << input[i];
				output_flag = 1;
		}
	}
	if (output_flag == 0) cout << '\n';

	return 0;
}