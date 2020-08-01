#include "iostream"
#include "string"
#include "algorithm"
#include "cstdio"
#include "map"
using namespace std;
/*ĳ����ȷѡ��û��ѡҲ�Ǵ���*/
struct quest {
	int id = 0; //��Ŀ���
	double total_score = 0;//��Ŀ������
	int given_num = 0;//����ѡ������
	int right_num = 0;//��ȷѡ������
	map<char, int> ans; //��ȷ���б�
	int wrong_times = 0;
	map<char, int> ans_static; //�洢����ѡ��
};

bool cmp(quest a, quest b) {
	if (a.wrong_times != b.wrong_times) return a.wrong_times > b.wrong_times;
	else if (a.id != b.id) return a.id < b.id;
}

int main() {
	int n, m; //nΪѧ������ mΪ��Ŀ����
	quest list[101];
	cin >> n >> m;
	//printf("%d��ѧ�� %d����Ŀ\n",n,m);
	/*��Ŀ��Ϣͳ��*/
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
			//cout << "��ȷѡ��Ϊ" << temp_choice << endl;
			list[i].ans[temp_choice] = 1;
		}
	}



	/*ѧ���������ͳ��*/
	double score_list[1001] = { 0 }; //���ѧ���ɼ�
	for (int i = 0; i < n; i++) {
		//printf("��%d��ѧ��\n",i+1);
		/*��ʼ��ÿһ������ж�*/
		for (int j = 0; j < m; j++) {
			//cout << "��ʼ�жϵ�" << j + 1 << "��" << endl;
			string temp_num;
			cin >> temp_num;//����ѭ������
			int num = temp_num[1] - '0';
			//cout << "ѭ��" << num << "��" << endl;
			int wrong_flag = 0;
			int cnt = 0;
			map<char, int> temp_map = list[j].ans;
			for (int k = 0; k < num; k++) {
				string temp;
				cin >> temp;//��ȡ�׶μ�ʹ����Ҳ�����˳�ѭ��      
				//cout<<"��ǰѡ��Ϊ"<<temp[0]<<endl;
				if (temp_map.find(temp[0])!= temp_map.end()) {//map��find
					//
					//cout << "��ȷѡ��֮һΪ" << temp[0] << endl;
					temp_map.erase(temp[0]);
					cnt += 1;
				}
				else {
					//���Ӧ����Ŀ�洢����ѡ��
					list[j].ans_static[temp[0]]+=1;
					//cout << temp[0] << "ѡ����� ��ǰ��" << j + 1 <<" ���ѡ "<< temp[0] << " " << list[j].ans_static[temp[0]] << "��" << endl;
					//printf("%sѡ����� ��ǰ��%d���ѡ%s %d��\n", temp[0].c_str(), j + 1, temp[0],list[j].ans_static[temp[0]]);
					wrong_flag = 1;
				}
			}
			if (temp_map.size() != 0) {
				for (map<char, int>::iterator it = temp_map.begin(); it != temp_map.end(); it++){
					list[j].ans_static[it->first] += 1;
					//cout << "��" << j + 1 << "��©ѡ" << it->first << "����" << endl;
				}
			}
			if (num > list[j].right_num) {
				//ȫ��
				score_list[i] += 0;
				list[j].wrong_times += 1;
				//cout << num << "������ ����Ҫ" << list[j].right_num << "������" << endl;
				//printf("��%d����Ϊ�����������Ѵ�%d��\n", j + 1, list[j].wrong_times);
			}
			else if (wrong_flag == 1) {
				//ȫ��
				score_list[i] += 0;
				list[j].wrong_times += 1;
				//printf("��%d����ӳ���������Ѵ�%d��\n", j + 1, list[j].wrong_times);
			}
			else if (cnt == list[j].right_num) {
				//ȫ��
				//printf("��%d��ȫ��\n", j + 1);
				score_list[i] += list[j].total_score;
			}
			else {
				//���
				//printf("��%d����\n", j + 1);
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