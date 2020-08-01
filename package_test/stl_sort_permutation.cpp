#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;
int main(){
/*输入n个数字(不超过10)，将它们排列组合形成新的数字，输出最大者*/
/*保证输入n不为0*/
	int n;
	cin>>n;
	string num[11];
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		num[i] = temp;	
	}
	vector<long long> total;
	do{
		string result = num[0];
		for(int i =1;i<n;i++){
			result = result + num[i];			
		}
		total.push_back(stoll(result));		
	}while(next_permutation(num,num+n));
	sort(total.begin(),total.end(),greater<long long>());	
	cout<<total[0]<<endl;
	return 0;
}
