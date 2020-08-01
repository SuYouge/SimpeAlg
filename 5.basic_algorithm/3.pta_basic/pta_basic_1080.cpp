#include "iostream"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "cstdio"
#include "cmath"
#include "vector"
using namespace std;
/*
3 3 2
a 200
b 200
c 200
a 0
b 60
c 0
c 0
a 0
*/
/*考0分和没参加考试不同*/
struct stu {
	string name;
	double p_score = -1;
	double m_score = -1;
	double final_score = -1;
	int total = -1;
};

bool cmp(stu a, stu b) {
	if (a.total != b.total) return a.total > b.total;
	else return a.name < b.name;
};

int main() {
	int p, m, n;
	cin >> p >> m >> n;
	//stu name_list[10001];
	unordered_map<string, stu> p_score;
	vector<stu> list;
	/*online work*/
	string temp_name;
	double temp_score;
	for (int i = 0; i < p; i++) {
		cin >> temp_name >> temp_score;
		if (temp_score >= 200) {//只保存大于200分的学生成绩
			stu temp;
			temp.p_score = temp_score;
			temp.name = temp_name;
			p_score.insert(pair<string, stu>(temp_name, temp));
		}
	}
	/*mid*/
	auto tit = p_score.find(temp_name);
	for (int i = 0; i < m; i++) {
		cin >> temp_name >> temp_score;
		tit = p_score.find(temp_name);
		if (tit != p_score.end()) {
			(tit->second).m_score = temp_score;
		}
	}
	/*final*/
	for (int i = 0; i < n; i++) {
		cin >> temp_name >> temp_score;
		tit = p_score.find(temp_name);
		if (tit != p_score.end()) {
			(tit->second).final_score = temp_score;
		}
	}
	/*遍历p列表 存储各个成绩*/
	//int pos = 0;
	double temp_m = 0;
	double temp_final = 0;
	double temp_p = 0;
	for (auto it = p_score.begin(); it != p_score.end(); it++) {
		//pos = distance(p_score.begin(), it);
		temp_name = (it->second).name;
		//cout << temp_name << endl;
		//name_list[pos].name = (it->second).name;
		temp_p = (it->second).p_score;
		temp_m = (it->second).m_score;
		temp_final = (it->second).final_score;


		//name_list[pos].p_score = temp_p;
		//name_list[pos].m_score = temp_m;
		//name_list[pos].final_score = temp_final;
		int temp_total = 0;
		/*计算总评*/
		if (temp_m != -1 && temp_final != -1) {
			/*期中和期末考试都参加了*/
			//cout << "参加了全部" << endl;
			if (temp_m > temp_final) {
				temp_total = round(0.4 * temp_m + 0.6 * temp_final);
				if (temp_total >= 60) {
					list.push_back(stu{ temp_name ,temp_p ,temp_m ,temp_final,temp_total });
				}
			}
			else {
				temp_total = round(temp_final);
				if (temp_total >= 60) {
					list.push_back(stu{ temp_name ,temp_p ,temp_m ,temp_final,temp_total });
				}
			}
		}
		else if (temp_m == -1 && temp_final != -1) {
			/*只参加了期末*/
			//cout << "参加期末" << endl;
			temp_total = round(temp_final);
			if (temp_total >= 60) {
				list.push_back(stu{ temp_name ,temp_p ,temp_m ,temp_final,temp_total });
			}
		}
		else if (temp_m != -1 && temp_final == -1) {
			/*只参加了期中*/
			//cout << "参加了期中" << endl;
			temp_total = round(0.4 * temp_m);//忘记检查了
			if (temp_total >= 60) {
				list.push_back(stu{ temp_name ,temp_p ,temp_m ,temp_final,temp_total });
			}
		}
	}
	int flag = 0;
	sort(list.begin(), list.end(), cmp);
	for (auto it = list.begin(); it != list.end(); it++) {
		flag = 1;
		cout << (*it).name << " " << (*it).p_score << " " << (*it).m_score << " " << (*it).final_score << " " << (*it).total << endl;
	}
	if (flag == 0) cout << endl;

	return 0;
}