//#include "bits/stdc++.h"
#include "iostream"
#include "cstdio"
#include "string"
using namespace std;

struct question {
	int score;//题目满分
	int choice;//答案选项个数
	int ans_num;//正确选项个数
	char ans[6];//正确选项
	int log;//错误次数
};

int main() {
	int N, M;
	cin >> N >> M;//N为学生人数M为题目数
	question qlist[101];
	for (int i = 0; i < M; i++) { //正确答案循环M次
		int score;
		int choice;
		int ans_num;
		cin >> score >> choice >> ans_num;
		qlist[i].score = score;
		qlist[i].choice = choice;
		qlist[i].ans_num = ans_num;
		qlist[i].log = 0;
		for (int j = 0; j < ans_num; j++) {
			char temp_ans;
			cin >> temp_ans;
			qlist[i].ans[j] = temp_ans;
		}
	}

	// for(int i=0;i<M;i++){
	//     for(int j=0;j<qlist[i].ans_num;j++){
	//         cout<<qlist[i].ans[j]<<" "; 
	//     }
	//     cout<<endl;
	// }

	//学生答题情况输入均以空格为分界线
	for (int i = 0; i < N; i++) {//学生循环N次
		int total = 0; //记录学生总分
		for (int j = 0; j < M; j++) {//回答循环M次
			string temp_num;
			cin >> temp_num;
			int num = temp_num[1]-48;//stoi不能对char重载
			//cout << "第" << j << "题" << endl;
			//cout << "temp_num为" <<temp_num << endl;
			//cout << "输入了" << num << "个选项" << endl;
			char ans_list[6];//存储一道题的答案
			int flag = 1;//记录题目是否有出错环节
			//检查选项
			
			for (int k = 0; k < num; k++) {
				string temp_choice;
				cin >> temp_choice;
				//cout << "学生选择了" << temp_choice << endl;
				ans_list[k] = temp_choice[0];
				if (num != qlist[j].ans_num) {//选项数量错误
					flag = 0;
					//qlist[j].log += 1;
					continue;//如果选项数量错误退出当前k循环，将所有输入吸收
				}
				else {
					if (ans_list[k] != qlist[j].ans[k]) {
						flag = 0;
						//qlist[j].log += 1;
						continue;//不设置flag置为1的条件，防止第二个选项正确导致flag为1的情况
					}
				}
			}

			if (flag == 1) {
				//选项全部检查正确，学生加分
				total = total + qlist[j].score;
			}
			else {
				qlist[j].log += 1;
			}
		}
		cout << total << endl;
	}

	int max = 0;
	int maxloc = 0;
	//遍历qlist
	for (int i = 0; i < M; i++) {
		//cout <<"第"<<(i+1) <<"题出错"<<qlist[i].log <<"次" <<endl;
		if (max < qlist[i].log) {
			max = qlist[i].log;
			maxloc = i;
		}
	}

	if (max == 0)cout << "Too simple";
	else {
		cout << max;
		for (int i = 0; i < M; i++) {
			if (qlist[i].log == max) cout << " " << (i + 1);
		}
	}
	return 0;
}