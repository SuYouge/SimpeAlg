#include "string"
#include "stack"
#include "iostream"
#include "algorithm"
using namespace std;
//���뷭ת
//�������
//�жϻ�����
//ѭ��10��

string add(string a, string b) {
	int temp = 0;
	int len = a.length();
	string c;
	c = to_string((a[len - 1] - '0' + b[len - 1] - '0' + temp) % 10);
	temp = (a[len - 1] - '0' + b[len - 1] - '0' + temp) / 10;
	for (int i = len - 2; i >= 0; i--) {
		//cout << "a[i] = " << a[i] << " b[i] = " << b[i] << endl;
		c = to_string((a[i] - '0' + b[i] - '0' + temp) % 10) + c;
		temp = (a[i] - '0' + b[i] - '0' + temp) / 10;
		//cout << "temp = " << temp << endl;
	}
	/*���һ�ν�λ*/
	if (temp != 0) c = to_string((temp) % 10) + c;
	return c;
};
/*�����ж�������*/
// bool ispalind(string a)//�ж��Ƿ�Ϊ����
// {
// 	int l = a.length();
// 	for (int i = 0; i < l / 2; i++)
// 	{
// 		if (a[i] != a[l - i - 1])
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

bool ispalind(string str) {
	int l = str.length();
	int push_times = 0;
	int pop_times = 0;
	stack<char> mystack;

	if (l % 2 == 0) {
		//ż��
		push_times = l / 2;
		pop_times = push_times;
	}
	else {
		//����
		push_times = (l - 1) / 2;
		pop_times = push_times;
	}
	for (int i = 0; i < push_times; i++) {
		mystack.push(str[0]); // ��Զ�����ַ����ĵ�0λ
		str.erase(0, 1);
	}
	if (l % 2 != 0) {
		str.erase(0, 1);
	}
	for (int i = 0; i < pop_times; i++) {
		if (mystack.top() == str[0]) {
			mystack.pop();
			str.erase(0, 1);
		}
		else {
			return 0;
		}
	}

	return 1;
}

int main() {
	//string test = "45";
	//string testb = "78";
	//cout << add(test,testb) << endl;
	string str;
	cin >> str;
	string rev = str;
	reverse(rev.begin(), rev.end());
	if (ispalind(str)) {//�����жϵ�һ�������ǲ��ǻ���
		cout << str << " is a palindromic number.";
		return 0;
	}
	else {
		for (int i = 0; i < 10; i++) {
			string result = add(str, rev);
			cout << str << " + " << rev << " = " << result << endl;
			if ((ispalind(result) && (result[0] != '0')) || (result == "0")) {
				cout << result << " is a palindromic number.";
				return 0;
			}
			else {
				str = result;
				rev = str;
				reverse(rev.begin(), rev.end());
			}
		}
	}
	cout << "Not found in 10 iterations.";
	return 0;
}