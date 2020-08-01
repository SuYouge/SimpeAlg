#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//每次卖出单价最高的
//测试点3 所有库存总和不满足需求

// struct mooncake{
//     int storage; //剩余库存
//     int price;//单价
//     int total;//总价
// }

int main(){
    int type;
    cin>>type;
    double need;
    cin>>need;
    vector<double> storage;
    vector<double> price;
    for(int i=0;i<type;i++){
        double temp_sto;
        cin>>temp_sto;
        storage.push_back(temp_sto);
    }
    for(int i=0;i<type;i++){
        double temp_total;
        cin>>temp_total;
        price.push_back(temp_total/storage[i]);
    }
    double  profit = 0.0;
    while(need!=0){
        vector<double>::iterator maxit = max_element(price.begin(),price.end());
		if (*maxit==-1){
			break;
		}else{
        if(storage[distance(price.begin(),maxit)]>=need){//供大于求
            storage[distance(price.begin(),maxit)] = storage[distance(price.begin(),maxit)]-need;
			//cout<<"卖出第"<<distance(price.begin(),maxit)<<"种月饼"<<storage[distance(price.begin(),maxit)]<<endl;
			//cout<<"需求全部满足"<<endl;
            profit = profit + need*(*maxit);
			need = 0;
			//cout<<"总利润为"<<profit<<endl;
        }else{//满足一部分need
            need = need - storage[distance(price.begin(),maxit)];
			//cout<<"卖出第"<<distance(price.begin(),maxit)<<"种月饼"<<storage[distance(price.begin(),maxit)]<<endl;
            profit = profit + storage[distance(price.begin(),maxit)]*(*maxit);
			//cout<<"当前利润"<<profit<<endl;
            *maxit = -1;
        }
		}
    }
    printf("%.2lf",profit);

    return 0;
}
