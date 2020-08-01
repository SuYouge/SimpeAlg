#include "cstdio"
#include "iostream"
#include "string"
#include "cmath"
#include "algorithm"
using namespace std;

int main() {
	int n;
	cin >> n;
	double list[10001];
	for (int i = 0; i < n; i++) {
		string temp1, temp2;
		cin >> temp1;
		if (temp1[0] == '-') temp1 = temp1.substr(1, temp1.length() - 1);
		cin >> temp2;
		if (temp2[0] == '-') temp2 = temp2.substr(1, temp2.length() - 1);

		int real = stoi(temp1);
		int img = stoi(temp2);

		list[i] = sqrt(real * real + img * img);

	}
	sort(list, list + n, greater<double>());
	printf("%.2f", list[0]);
	return 0;
}