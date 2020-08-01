#include "iostream"
#include "string"
using namespace std;

int main() {
	//cout << int('a') << endl;
	//cout << int('A') << endl;
	string standard;
	cin >> standard;
	char list[128];
	for (int i = 0; i < standard.length(); i++) {
		if ((standard[i] <= 'z') && (standard[i] >= 'a')) {
			list[standard[i] + int('A' - 'a')] = 1;
			//cout << char(standard[i] + int('A' - 'a')) << " is set to 1" << endl;
		}
		else {
			list[standard[i]] = 1;
			//cout << char(standard[i]) << " is set to 1" << endl;
		}		
	}

	string match;
	cin >> match;
	int temp = 0;
	for (int i = 0; i < match.length(); i++) {
		if ((match[i] <= 'z') && (match[i] >= 'a')) {
			temp = match[i] + int('A' - 'a');
		}
		else {
			temp = match[i];
		}
		list[temp] = 0;
		/*cout <<"match " <<(char)temp << endl;
		if (list[temp] != 1) cout << (char)temp;*/
	}
	//遍历清洗过的数组
	for (int i = 0; i < standard.length(); i++) {
		int check;
		if ((standard[i] <= 'z') && (standard[i] >= 'a')) {
			check = standard[i] + int('A' - 'a');
			//cout << char(standard[i] + int('A' - 'a')) << " is set to 1" << endl;
		}
		else {
			check = standard[i];
			//cout << char(standard[i]) << " is set to 1" << endl;
		}
		if (list[check] == 1) {
			cout << (char)check;
			list[check] = 0;
		}
	}
	return 0;
}