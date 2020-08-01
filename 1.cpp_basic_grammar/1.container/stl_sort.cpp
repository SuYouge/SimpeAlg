#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

bool cmp1(int a,int b){
	return a>b;//a大于b从大到小
}


bool cmp2(int a,int b){
	return a<b;//a大于b从大到小
}

struct stu{
	string name; //总分和数学成绩都相同按名字排序
	int total; // 按总分排序
	int math; //总分相同按数学成绩排序
};
/*依次判断各级指标是否相同*/
bool cmp3(stu a, stu b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.math!=b.math) return a.math>b.math;
	else return a.name>b.name;
}

/*字符串比较*/
bool cmp4(string a,string b){
	if(a.length()!=b.length()) return a.length()>b.length();//如果长度不同按长度降序排列
	else return a<b; // 如果长度相同按字典序输出
}

int main(){
	/*1. 基本(int)类型的数组*/
	int list_int[4] = {52, 13 ,23, 43};
	int n = 4;
/******************************************/
	cout<<"Default ";
	sort(list_int,list_int+4);
	for(int i=0;i<n;i++){
		cout<<list_int[i]<<" ";
	}
	cout<<endl;
/******************************************/
	cout<<"a>b ";
	sort(list_int,list_int+4,cmp1);
	for(int i=0;i<n;i++){
		cout<<list_int[i]<<" ";
	}
	cout<<endl;
/******************************************/
	cout<<"a<b ";
	sort(list_int,list_int+4,cmp2);
	for(int i=0;i<n;i++){
		cout<<list_int[i]<<" ";
	}
	cout<<endl;
/******************************************/
	cout<<"greater<int>() ";
	sort(list_int,list_int+4,greater<int>());
	for(int i=0;i<n;i++){
		cout<<list_int[i]<<" ";
	}
	cout<<endl;
/******************************************/
	cout<<"less<int>() ";
	sort(list_int,list_int+4,less<int>());
	for(int i=0;i<n;i++){
		cout<<list_int[i]<<" ";
	}
	cout<<endl;
	/*2. 结构体数组排序*/
	stu list[4];
	list[0].total = 100;
	list[0].math = 20;
	list[0].name = "abcd";
	list[1].total = 100;
	list[1].math = 50;
	list[1].name = "abcd";
	list[2].total = 70;
	list[2].math = 20;
	list[2].name = "abcd";
	list[3].total = 100;
	list[3].math = 50;
	list[3].name = "bcd";
	sort(list,list+4,cmp3);
	for(int i = 0;i<4;i++){
		cout<<list[i].name<<" "<<list[i].total<<" "<<list[i].math<<" "<<endl;
	}
	/*2. 容器排序*/
	string list_string[4];
	list_string[0] = "abcde";
	list_string[1] = "de";
	list_string[2] = "dc";
	list_string[3] = "bcds";
	sort(list_string,list_string+4,cmp4);
	for(int i=0;i<4;i++){
		cout<<list_string[i]<<endl;
	}
	return 0;
}
