#include "iostream"
#include "algorithm"
#include "string"
#include "cmath"
using namespace std;

int main() {

	int n;
	cin >> n;
	int list[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		list[i] = temp;
	}
	sort(list, list + n);
	//for (int i = 0; i < n; i++) {
	//	cout << list[i] << endl;
	//}
	int total = list[0];
	for (int i = 1; i < n; i++) {
		total = (total + list[i]) / 2;
	}
	cout << floor(total);


	return 0;
}