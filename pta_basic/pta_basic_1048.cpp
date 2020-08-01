#include "cstdio"
#include "string"
#include "iostream"
#include "cmath"
using namespace std;
int main() {
	string A, B;
	cin >> A >> B;
	int len = (A.length()>B.length())? A.length(): B.length();
	int cnt = 0;
	//如果B比较短，也需要补0
	/*cout << A << endl;
	cout << B << endl;*/
	//cout << B.length() - A.length() << endl;
	char list[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
	for (int i = 0; i < len; i++) {
		if (A.length() <= B.length()) {//B长
			//cout<<endl;
			if ((A.length() < B.length()) && (cnt != (B.length() - A.length()))) {
				//B比A长，A前补0，循环B.length()-A.length()次
				cout << B[i];
				cnt += 1;
			}
			else {
				//A[len-i-A.length()]和B[i]进行操作
				if ((len - i) % 2 != 0) {//奇数位
					//cout << "odd" << endl;
					/*cout << len << " " << i << " " << A.length() << endl;
					cout << "B in " << i << " A in " << (i + A.length() - len) << endl;*/
					//cout << "A奇数位" << (i + A.length() - len)<<"为"<< A[i + A.length() - len] << endl;
					int index = ((A[i + A.length() - len] + B[i]) - 96) % 13;
					//cout <<"index is" <<index << endl;
					cout << list[index];
					//cout << endl;
				}
				else {//偶数位
					if ((B[i] - A[i + A.length() - len]) < 0) {
						//cout << "even" << endl;
						/*cout << len << " " << i << " " << A.length() << endl;
						cout << "B in " << i << " A in " << (i + A.length() - len) << endl;*/
						cout << (B[i] - A[i + A.length() - len]) + 10;
						//cout << endl;
					}
					else {
						//cout << "B in " << i << " A in " << (i + A.length() - len) << endl;
						//cout << "even" << endl;
						cout << B[i] - A[i + A.length() - len];
						//cout << endl;
					}
				}
			}
		}
		else {//A长
			if ((A.length() > B.length()) && (cnt != (A.length() - B.length()))) {
				//cout << "补位" << (A[i] - 48) << endl;
				if ((len - i) % 2 != 0) {
					//cout << "odd" << endl;
					cout << list[(A[i] - 48)];
					cnt += 1;
				}
				else {
					if ((A[i] - 48) != 0) {
						cout << list[10 - (A[i] - 48)];
					}
					else {
						cout << list[0];
					}
					cnt += 1;
				}

			}
			else {
				if ((len - i) % 2 != 0) {//奇数位
					int index = ((A[i] + B[i-(A.length() - B.length())]) - 96) % 13;
					//cout <<"index is" <<index << endl;
					cout << list[index];
					//cout << endl;
				}
				else {//偶数位
					if ((B[i- (A.length() - B.length())] - A[i]) < 0) {
						//cout << "even" << endl;
						/*cout << len << " " << i << " " << A.length() << endl;
						cout << "B in " << i << " A in " << (i + A.length() - len) << endl;*/
						cout << (B[i - (A.length() - B.length())] - A[i]) + 10;
						//cout << endl;
					}
					else {
						//cout << "B in " << i << " A in " << (i + A.length() - len) << endl;
						//cout << "even" << endl;
						cout << B[i - (A.length() - B.length())] - A[i];
						//cout << endl;
					}
				}
			}
		}
	}
	return 0;
}