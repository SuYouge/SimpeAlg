#include "iostream"
#include "cstdio"
using namespace std;

int main(){
    int list[1001] = {0};
    int pos_vain = 0;
    int vain = 0;
    int n;
    cin>>n; //用户数量
	//cout<<"user number "<<n<<endl;
    double thresh;
    cin>>thresh; //阈值
	//cout<<"thresh number "<<thresh<<endl;
    int supervise_thresh;
    cin>> supervise_thresh;//观察天数阈值
	//cout<<"supervise_thresh number "<<supervise_thresh<<endl;

    for(int i=0;i<n;i++){
        int days;
        cin>>days; //观察天数
		//cout<<"观察"<<days<<"天"<<endl;
        for(int j=0;j<days;j++){
            double temp;
			cin>>temp;
			//cout<<"用电量为"<<temp<<endl;
            if(temp<thresh){
				list[i]+=1;
				//cout<<"用电量少于阈值"<<endl;
        	}
        }
		//cin.sync();
		//getchar();
        if((days>supervise_thresh)&&(list[i]>0.5*(double)days)){
            //空置
            vain = vain+1;
        }
        if((days<=supervise_thresh)&&(list[i]>0.5*(double)days)){
            //空置
            pos_vain = pos_vain+1;
        }
    }
	//cout<<"可能空置"<<pos_vain<<endl;
	//cout<<"空置"<<vain<<endl;
    printf("%.1f%% %.1f%%",pos_vain/double(n)*100,vain/double(n)*100);
    return 0;
}
