#include "iostream"
#include "string"
#include "algorithm"
#include "map"
//memset��ͷ�ļ� <string.h>��<cstring>
using namespace std;
/*�����ǲ������ָ���ô��*/

int main() {
	int n;//�����ݶ���
	int m;//�����ĵ���

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
		//memset(list,0,sizeof(list));//��ÿһ����һ����������Ʒ�ĳ������
		for (int j = 0; j < items; j++) {
			int temp;
			cin >> temp;
			//ÿһ���ٿ�һ�������ŵ���������Ʒ���
			item_list[j] = temp;
			//cout << "temp = "<<temp << endl;
			list[temp] = 1;
		}
		int flag = 1;
		/*��ʼ���*/
		for (int j = 0; j < items; j++) {
			auto it = mp.find(item_list[j]);//���ȱ�֤����Ʒ����Ҫע��ģ���keyֵ����
			if (it != mp.end() && (list[it->second] == 1)) {//valueֵ�µ�����Ԫ����ҪΪ1
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