#include "iostream"
#include  "string"
#include "cstdio"
using namespace std;

int main(){

    string input;
    getline(cin,input);
	int total = 0;
    for(int i=0;i<input.length();i++){
        if((input[i]>='a')&&(input[i]<='z')){
            total = total + input[i]-'a'+1;
        }
        if((input[i]>='A')&&(input[i]<='Z')){
            total = total + input[i] - 'A' + 1;
        }
    }
	//cout<<total;
	int zero = 0;
	int one = 0;
    int temp_total = total;
	int temp;
    if(total==1) one += 1;	
	while((temp_total/2)!=0){
		//最后一轮total = 1
		temp = temp_total%2;
		if(temp==1) one += 1;
		if(temp==0) zero += 1;
		temp_total = (temp_total-temp)/2;
		if((temp_total/2)==1) one += 1;			
	}
	cout<<zero<<" "<<one;

    return 0;
}
