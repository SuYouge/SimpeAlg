#include "string"
#include "map"
#include "iostream"
using namespace std;
int main(){
    map<string,int> list;
    int n,s,first;
    int flag = 0;
    int cnt = 0;
	cin>>n;
	cin>>s;
	cin>>first;
	int next = 0;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        cnt += 1;
		//cout<<"counting in "<<cnt<<endl;
		//cout<<"Input is "<<temp<<endl;
        if((cnt==first)&&(flag!=1)){
            //开始发奖
            cout<<temp<<endl;
            list[temp]++;
            cnt = 0;
            flag = 1;
			//cout<<"oop "<<temp<<endl;
        }
        else if((flag==1)&&(list[temp]==0)&&(cnt==s)){
			//cout<<"counting in "<<cnt<<endl;
            cout<<temp<<endl;
            list[temp]++;
            cnt = 0;
			//cout<<"oop "<<temp<<endl;
        }else if((flag==1)&&(list[temp]>=1)&&(cnt==s)){
			next = 1;
		}else if((flag==1)&&(next==1)){
			if(list[temp]==0){
            	cout<<temp<<endl;
            	list[temp]++;
            	cnt = 0;				
				next = 0;			
			}
		}       
    }
    if(n<first) cout<<"Keep going...";//日
    return 0;
}
