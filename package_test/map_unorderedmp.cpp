#include "iostream"
#include "map"
#include "unordered_map"
#include "algorithm"
using namespace std;
int main(){

	map<string,int>mp1;
	unordered_map<string,int>mp2;

	mp1["c"]++;
	//mp2["c"]++;
	mp1["a"]++;
	mp1["abc"]++;
	//mp2["a"]++;
	mp1["b"]++;
	//mp2["b"]++;

	for(map<string,int>::iterator it = mp1.begin();it!=mp1.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
		//cout<<*it<<endl;
	}
	string str = "1234567";
	reverse(str.begin(),str.end());
	cout<<str<<endl;
	/*
	for(map<string,int>::iterator it = mp2.begin();it!=mp2.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}*/

	return 0;
}
