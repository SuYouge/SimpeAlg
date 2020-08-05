#include "string"
#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;

/*测试点5需要用Long long*/
/*通过记录上一次的退出点来减少时间*/

int main() {
	long long n;
	long long p;
	cin >> n >> p;
	vector<long long> vi;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		vi.push_back(temp);
	}
	sort(vi.begin(), vi.end());
	long long dist_list[100001];
	long long dis = 0;
	vector<long long>::iterator temp = vi.begin();
	for (auto it = vi.begin(); it != vi.end(); it++) {
		auto now = temp;
		for (; now != vi.end(); now++) {
			if (*now > (*it)* p) {
				temp = now;
				//cout << *now << endl;
				break;
			}
		}
		dis = distance(it, now);
		dist_list[distance(vi.begin(), it)] = dis;
	}
	sort(dist_list, dist_list + n, greater<long long>());
	cout << dist_list[0];
	return 0;
}