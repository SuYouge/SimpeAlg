#include "string"
#include "iostream"
#include "unordered_map"
#include "cctype"
#include "vector"
#include "algorithm"
using namespace std;

struct school {
	int total;
	string name;
	int cnt;
};

bool cmp(school a, school b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.cnt != b.cnt) return a.cnt < b.cnt;
	else return a.name < b.name;
}

int main() {
	int n;
	cin >> n;
	unordered_map<string, double> score_list;
	unordered_map<string, int> cnt_list;
	for (int i = 0; i < n; i++) {
		string temp_id;
		double score;
		string school_name;
		cin >> temp_id >> score >> school_name;
		//cout<< temp_id <<" "<< score <<" "<< school_name<<endl;
		for (int x = 0; x < school_name.length(); x++) {
			school_name[x] = tolower(school_name[x]);
		}
		//cout << "temp_id[0]" << temp_id[0] << endl;
		if (temp_id[0] == 'T') score = score * 1.5;
		//else if (temp_id[0] == 'A') score = score * 1.0;
		else if (temp_id[0] == 'B') score = score / 1.5;
		score_list[school_name] += score;
		//cout << school_name << " score " << score_list[school_name] << endl;
		cnt_list[school_name] += 1;
		//cout << school_name << " cnt " << cnt_list[school_name] << endl;
	}
	vector<school> list;
	for (auto it = cnt_list.begin(); it != cnt_list.end(); it++) {
		school temp;
		temp.total = (int)score_list[it->first];
		temp.name = it->first;
		temp.cnt = it->second;
		list.push_back(temp);
	}
	sort(list.begin(), list.end(), cmp);
	cout << list.size() << endl;
	int rank = 0; int now = -1;
	for (int i = 0; i < list.size(); i++) {
		if (now != list[i].total) rank = i + 1;//改变一次当前值 更新一次rank
		now = list[i].total;
		printf("%d ", rank);
		cout << list[i].name;
		printf(" %d %d\n", list[i].total, list[i].cnt);
		/*下面的输出方法是错的*/
		//if (list[i].total < now) {
		//	rank = i + 1;
		//	cout << rank << " " << list[i].name << " " << (int)list[i].total << " " << list[i].cnt << endl;
		//	now = list[i].total;
		//}
		//else if (list[i].total = now) {
		//	cout << rank << " " << list[i].name << " " << (int)list[i].total << " " << list[i].cnt << endl;
		//	//rank = rank + 1;
		//}
	}
	return 0;
}