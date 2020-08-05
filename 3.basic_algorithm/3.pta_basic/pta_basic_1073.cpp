#include "iostream"
#include "string"
#include "algorithm"
#include "cstdio"
#include "map"
using namespace std;
/*某个正确选项没有选也是错误*/
struct quest {
	int id = 0; //题目编号
	double total_score = 0;//题目的满分
	int given_num = 0;//给定选项数量
	int right_num = 0;//正确选项数量
	map<char, int> ans; //正确答案列表
	int wrong_times = 0;
	map<char, int> ans_static; //存储错误选项
};

bool cmp(quest a, quest b) {
	if (a.wrong_times != b.wrong_times) return a.wrong_times > b.wrong_times;
	else if (a.id != b.id) return a.id < b.id;
}

int main() {
	int n, m; //n为学生数量 m为题目数量
	quest list[101];
	cin >> n >> m;
	//printf("%d个学生 %d个题目\n",n,m);
	/*题目信息统计*/
	for (int i = 0; i < m; i++) {
		list[i].id = i + 1;
		int temp_total_score;
		int temp_given_num;
		int temp_right_num;
		cin >> temp_total_score >> temp_given_num >> temp_right_num;
		list[i].given_num = temp_given_num;
		list[i].total_score = temp_total_score;
		list[i].right_num = temp_right_num;
		//printf("total score :%d givennum: %d right_num: %d\n", temp_total_score,temp_given_num,temp_right_num);
		for (int j = 0; j < temp_right_num; j++) {
			char temp_choice;
			cin >> temp_choice;
			//cout << "正确选项为" << temp_choice << endl;
			list[i].ans[temp_choice] = 1;
		}
	}



	/*学生答题情况统计*/
	double score_list[1001] = { 0 }; //存放学生成绩
	for (int i = 0; i < n; i++) {
		//printf("第%d个学生\n",i+1);
		/*开始对每一题进行判断*/
		for (int j = 0; j < m; j++) {
			//cout << "开始判断第" << j + 1 << "题" << endl;
			string temp_num;
			cin >> temp_num;//接受循环次数
			int num = temp_num[1] - '0';
			//cout << "循环" << num << "次" << endl;
			int wrong_flag = 0;
			int cnt = 0;
			map<char, int> temp_map = list[j].ans;
			for (int k = 0; k < num; k++) {
				string temp;
				cin >> temp;//读取阶段即使出错也不能退出循环      
				//cout<<"当前选项为"<<temp[0]<<endl;
				if (temp_map.find(temp[0])!= temp_map.end()) {//map中find
					//
					//cout << "正确选项之一为" << temp[0] << endl;
					temp_map.erase(temp[0]);
					cnt += 1;
				}
				else {
					//向对应的题目存储错误选项
					list[j].ans_static[temp[0]]+=1;
					//cout << temp[0] << "选项错误 当前第" << j + 1 <<" 题错选 "<< temp[0] << " " << list[j].ans_static[temp[0]] << "次" << endl;
					//printf("%s选项错误 当前第%d题错选%s %d次\n", temp[0].c_str(), j + 1, temp[0],list[j].ans_static[temp[0]]);
					wrong_flag = 1;
				}
			}
			if (temp_map.size() != 0) {
				for (map<char, int>::iterator it = temp_map.begin(); it != temp_map.end(); it++){
					list[j].ans_static[it->first] += 1;
					//cout << "第" << j + 1 << "因漏选" << it->first << "而错" << endl;
				}
			}
			if (num > list[j].right_num) {
				//全错
				score_list[i] += 0;
				list[j].wrong_times += 1;
				//cout << num << "个输入 而需要" << list[j].right_num << "个输入" << endl;
				//printf("第%d题因为输入过多而错，已错%d次\n", j + 1, list[j].wrong_times);
			}
			else if (wrong_flag == 1) {
				//全错
				score_list[i] += 0;
				list[j].wrong_times += 1;
				//printf("第%d题因映射错误而错，已错%d次\n", j + 1, list[j].wrong_times);
			}
			else if (cnt == list[j].right_num) {
				//全对
				//printf("第%d题全对\n", j + 1);
				score_list[i] += list[j].total_score;
			}
			else {
				//半对
				//printf("第%d题半对\n", j + 1);
				score_list[i] += 0.5 * list[j].total_score;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%.1f\n", score_list[i]);
	}
	sort(list, list + m, cmp);
	int value = 0;
	for (int i = 0; i < m; i++) {
		for (map<char, int>::iterator it = list[i].ans_static.begin(); it != list[i].ans_static.end(); it++) {
			if (it->second > value) value = it->second;
		}
	}

	if (list[0].wrong_times != 0) {
		for (int i = 0; i < m; i++) {
			for (map<char, int>::iterator it = list[i].ans_static.begin(); it != list[i].ans_static.end(); it++) {
				if (it->second == value) cout << it->second << " " << list[i].id << "-" << it->first << endl;
			}				
		}
	}
	else {
		cout << "Too simple";
	}
	return 0;
}