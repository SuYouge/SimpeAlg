#include "iostream"
#include "string"
#include "cstdio"
using namespace std;

int main(){
    char mode;
    cin>>mode;
    getchar();//消化cin抛弃的换行符
    string input;
    getline(cin,input);
    if(mode == 'C'){
        //char temp = input[0];
        //int list[1001] = {0};
		   int cnt = 0;
        for(int i=0;i<input.length();i++){
            char temp = input[i];
            cnt = 0;
            while(temp == input[i]){
                cnt+=1;
				if(temp == input[i+1]) i++;
				else break;
            }

            if(cnt!=1)cout<<cnt<<temp;
            else cout<<temp;
        }
    }
    if(mode == 'D'){
        int start = -1;
        int end = 0;
        for(int i=0;i<input.length();i++){
            if(isdigit(input[i])!=1) {
				//cout<<"input i = "<<input[i]<<endl;
                end = i;
                //start和end之间处理重复输出
				//cout<<"start is "<<start<<" end is "<<end<<endl;
				int times;
				if((end-start-1)!=0)
                {times = stoi(input.substr(start+1,end-start-1));}
				else times = 1;
				//cout<<"loop time"<<times<<endl;
                for(int k=0;k<times;k++){
                    cout<<input[end];
                }
                start = end;
            }
        }
    }
    return 0;
}
