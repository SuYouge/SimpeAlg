#include "string"
#include "cstdio"
#include "iostream"
using namespace std;
int main() {
	string correct;
	cin >> correct;
	int num;
	cin >> num;
	int sharp = 0;
	int flag = 0;
	int cnt = 0;
	int successful = 0;
	while (sharp != 1) {
		string temp;
		cin >> temp;
		if ((temp[0] == '#')&&(temp.length()==1)) sharp = 1;
		else if ((cnt < num) && (temp == correct)) {//n次内输入成功
			cout << "Welcome in" << endl;
			successful = 1;
			return 0;
		}
		else if ((cnt < num) && (temp != correct) && (successful != 1)) {
			cnt += 1;
			if (cnt >= num) {//locked
				cout << "Wrong password: " << temp << endl;
				cout << "Account locked" << endl;
				sharp = 1;
			}
			else {//try again
				cout << "Wrong password: " << temp << endl;
			}
		}
	}
	return 0;
}