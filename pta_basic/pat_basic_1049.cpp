#include "iostream"
using namespace std;

int main()
{
	int n;
	cin >> n;
	double sum = 0;
	double temp;
	double count;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf", &temp);
		sum += (i + 1) * temp * (n - i);
	}
	printf("%.2lf", sum);
	return 0;
}

//#include "iostream"
//using namespace std;
//int main() {
//	double list[100005];
//	int n;
//	cin >> n;
//	double total = 0.0;
//	for (int i = 0; i < n; i++) {
//		double temp;
//		cin >> temp;
//		cout << temp << endl;
//		if (i == 0) {
//			list[i] = 0 + double(i + 1) * temp;
//		}
//		else {
//			list[i] = list[i - 1] + double(i + 1) * temp;
//		}
//		total = total + list[i];
//	}
//	printf("%.2lf\n", total);
//
//	return 0;
//}