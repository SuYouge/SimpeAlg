#include "iostream"
#include "string"
#include "algorithm"
using namespace std;



int main() {

	int N;//月饼种类
	int M;//城市数量
	cin >> N >> M;
	int temp;
	int mooncake[1001] = { 0 };
	int store[1001] = { 0 };
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			mooncake[j] = mooncake[j] + temp;
			store[j] = store[j] + temp;
		}
	}
	sort(mooncake, mooncake + N, greater<int>());
	int maxloc = 0;
	int max = mooncake[0];
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if ((store[i] == max) && (flag == 0)) {
			maxloc = i;
			cout << maxloc + 1;
			flag = 1;
		}
		else if ((store[i] == max) && (flag != 0)) {
			cout << " " << i + 1;
		}
	}


	return 0;
}