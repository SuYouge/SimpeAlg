#include "iostream"
#include "string"
using namespace std;

int check(string temp) {
	int num = 0;
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] == 'A') {
			num++;
		}
	}
	return num;
}


int main() {
	string input;
	cin >> input;
	int total = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'P') {
			for (int j = i; j < input.length(); j++) {
				if (input[j] == 'T') {
					string temp = input.substr(i+1,j-i-1);
					total = total + check(temp);
				}
			}
		}
	}
	cout << total;
	return 0;
}
