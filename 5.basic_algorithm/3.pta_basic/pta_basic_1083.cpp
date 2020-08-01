#include "iostream"
#include "cmath"
using namespace std;
int main() {

	int n;
	cin >> n;
	int subtr[10005] = { 0 }; \
		int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		subtr[abs((i + 1) - temp)] += 1;
	}

	for (int i = 10004; i >= 0; i--) {
		if (subtr[i] != 0) {
			cout << i << " " << subtr[i] << endl;
		}
	}


	return 0;
}