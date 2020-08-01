#include "iostream"
#include "string"
#include "algorithm"
#include "map"
//memset的头文件 <string.h>或<cstring>
using namespace std;
/*如果标记不是数字该怎么做*/

int main() {
	int n;//不相容对数
	int m;//待检查的单数

	cin >> n >> m;
	multimap<int, int> mp;
	//mp.clear();//?
	for (int i = 0; i < n; i++) {
		int a;
		int b;
		cin >> a >> b;
		mp.insert(pair<int, int>(a, b));
		mp.insert(pair<int, int>(b, a));
	}

	for (int i = 0; i < m; i++) {
		int items = 0;
		cin >> items;
		int list[100005] = { 0 };
		int item_list[1001];
		//memset(list,0,sizeof(list));//对每一单开一个数组存放物品的出现情况
		for (int j = 0; j < items; j++) {
			int temp;
			cin >> temp;
			//每一单再开一个数组存放单内所有物品序号
			item_list[j] = temp;
			//cout << "temp = "<<temp << endl;
			list[temp] = 1;
		}
		int flag = 1;
		/*开始检查*/
		for (int j = 0; j < items; j++) {
			auto it = mp.find(item_list[j]);//首先保证该物品是需要注意的，按key值搜索
			if (it != mp.end() && (list[it->second] == 1)) {//value值下的数组元素需要为1
				//cout << "conflict in " << it->first << " and " << it->second << endl;
				flag = 0;
				break;
			}
		}
		if (flag == 1) cout << "Yes" << endl;
		if (flag == 0) cout << "No" << endl;
	}




	return 0;
}