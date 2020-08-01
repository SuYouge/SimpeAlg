#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "string"
using namespace std;

int main() {
	int n;
	cin >> n;
	double list[10000];
	int max = 0;
	int min = 9999;
	int maxloc = 0;
	int minloc = 0;
	for (int i = 0; i < n; i++) {
		int temp_x, temp_y, ID;
		//string ID;
		scanf("%04d %d %d", &ID, &temp_x, &temp_y);
		list[ID] = sqrt(temp_x * temp_x + temp_y * temp_y);
		//printf("%04d %d %d %f \n", temp_x, temp_y, ID,list[ID]);
		if (list[ID] > max) {
			max = list[ID];
			maxloc = ID;
		}
		if (list[ID] < min) {
			min = list[ID];
			minloc = ID;
		}
	}
	printf("%04d %04d", minloc, maxloc);
	return 0;
}