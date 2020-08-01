/*四则运算*/
//读取两个字符串 判断各自第一位是不是负号
//将其化为最简分数形式
#include "string"
#include "cstdio"
#include "iostream"
#include "sstream"
using namespace std;

struct num{
    long long zhengshu = 0;
    long long fenzi = -1;
    long long fenmu = -1;
    //bool min = 0;
};

/**求最大公约数，不处理负号*/
long long measure(long long x, long long y)
{	
	if((x!=0)){
	long long temp;
	if(x>=y) {x = x;y=y;}
	else{temp = x; x = y;y = temp;}
	long long z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;	
	}
	else return 1;
}

num simplify(long long zhengshu, long long fenzi, long long fenmu){	
	num result;
	/*化简*/
	if(fenmu!=0){
    if(fenzi/fenmu!=0){
       	zhengshu = zhengshu + fenzi/fenmu;
       	fenzi = fenzi%fenmu;
    }
	//printf("第一次化简后 %d %d %d \n",zhengshu,fenzi,fenmu);
	/*分子分母同时除以最大公约数*/
	int flag = 0;
	if(fenzi<0) {fenzi = fenzi*(-1); flag = 1;}
	long long div = measure(fenzi, fenmu);
	if(flag == 0) {fenzi = fenzi/div;}
	else{fenzi = (-1)*fenzi/div;}
	fenmu = fenmu/div;
	//printf("除以最大公约数 %d 后 %d %d %d \n",div,zhengshu,fenzi,fenmu);
	result.zhengshu = zhengshu;
	result.fenzi = fenzi;
	result.fenmu = fenmu;
	}
	else{
	result.zhengshu = 0;
	result.fenzi = 0;
	result.fenmu = 0;
	
	}
	return result;	
}

/*转化结果为字符串，输入应为化简的num*/
string to_string_output(num input){
	string temp;
	string result;
	if(input.fenmu!=0){
	if(input.fenmu<0){input.fenmu = (-1)*input.fenmu;input.fenzi = (-1)*input.fenzi;}
	/*整数为0 分子不为0*/
	/*2/3; -2/3*/
	if((input.zhengshu==0)&&(input.fenzi!=0)){
		/*long long 转字符串*/
		/*stringstream temp_fenzi;
		stringstream temp_fenmu;
		temp_fenzi<<input.fenzi;
		temp_fenmu<<input.fenmu;*/
		string result_fenzi = to_string(input.fenzi);
		string result_fenmu = to_string(input.fenmu);
		/**/

		temp = result_fenzi+"/"+ result_fenmu;		
	}
	/*整数不为0 分子为0*/
	/*-2; 2*/
	if((input.zhengshu!=0)&&(input.fenzi==0)){
		/*
		stringstream temp_zhengshu;
		temp_zhengshu<<input.zhengshu;*/
		string result_zhengshu = to_string(input.zhengshu);
		temp = result_zhengshu;
	}
	/*整数不为0 分子不为0*/
	/*-2 1/3; 2 1/3/*/
	if((input.zhengshu!=0)&&(input.fenzi!=0)){
		if(input.zhengshu<0) {input.fenzi = (-1)*input.fenzi;}
		/*
		stringstream temp_fenzi;
		stringstream temp_fenmu;
		stringstream temp_zhengshu;
		temp_fenzi<<input.fenzi;
		temp_fenmu<<input.fenmu;
		temp_zhengshu<<input.zhengshu;*/
		string result_fenzi = to_string(input.fenzi);
		string result_fenmu = to_string(input.fenmu);
		string result_zhengshu = to_string(input.zhengshu);
		temp = result_zhengshu+" "+result_fenzi+"/"+result_fenmu;
	}
	/*整数为0 分子为0*/
	if((input.zhengshu==0)&&(input.fenzi==0)){
		temp = "0";	
	}
	/*正负数判断*/
	if((input.fenzi<0)||(input.zhengshu<0)){result = "("+temp+")";}
	else{result = temp;}
	}
	else{result = "Inf";}
	//cout<<result<<endl;
	return result;
}

/*加法应该还原为分数形式*/
/*输出中整数为负数则分子必为负数或0*/
num add(num a, num b){
	num sum;

	a.fenzi = a.fenzi + a.zhengshu*a.fenmu; a.zhengshu = 0;
	b.fenzi = b.fenzi + b.zhengshu*b.fenmu; b.zhengshu = 0;

	sum.fenzi = b.fenmu*a.fenzi + a.fenmu*b.fenzi; //可能为负数
	sum.fenmu = a.fenmu*b.fenmu;
	/*对分数的和进行化简*/
	num result;
	result = simplify(0,sum.fenzi,sum.fenmu);//化简函数可以处理负数分子
	return result;
};
/*减法*/
num jianfa(num a, num b){
	num sum;
	b.zhengshu = (-1)*b.zhengshu;
	b.fenzi = (-1)*b.fenzi;
	a.fenzi = a.fenzi + a.zhengshu*a.fenmu; a.zhengshu = 0;
	b.fenzi = b.fenzi + b.zhengshu*b.fenmu; b.zhengshu = 0;

	sum.fenzi = b.fenmu*a.fenzi + a.fenmu*b.fenzi; //可能为负数
	sum.fenmu = a.fenmu*b.fenmu;
	/*对分数的和进行化简*/
	num result;
	result = simplify(0,sum.fenzi,sum.fenmu);//化简函数可以处理负数分子
	return result;
};


/*乘法*/
num chengfa(num a, num b){
	num sum;
	/*还原为分数形式*/
	a.fenzi = a.fenzi + a.zhengshu*a.fenmu; a.zhengshu = 0;
	b.fenzi = b.fenzi + b.zhengshu*b.fenmu; b.zhengshu = 0;

	sum.fenzi = a.fenzi*b.fenzi; //可能为负数
	sum.fenmu = a.fenmu*b.fenmu;
	/*对分数的和进行化简*/
	num result;
	result = simplify(0,sum.fenzi,sum.fenmu);//化简函数可以处理负数分子
	return result;
};

/*除法*/
num chufa(num a, num b){
	num sum;
	/*还原为分数形式*/
	a.fenzi = a.fenzi + a.zhengshu*a.fenmu; a.zhengshu = 0;
	b.fenzi = b.fenzi + b.zhengshu*b.fenmu; b.zhengshu = 0;
	/*交换分子和分母*/
	long long temp;
	temp = b.fenmu;
	b.fenmu = b.fenzi;
	b.fenzi = temp;
	//cout<<"分母现在为"<<b.fenmu<<endl;
	sum.fenzi = a.fenzi*b.fenzi; //可能为负数
	sum.fenmu = a.fenmu*b.fenmu;
	/*对分数的和进行化简*/
	num result;
	result = simplify(0,sum.fenzi,sum.fenmu);//化简函数可以处理负数分子
	return result;
};


int main(){
    num input[2];

    for(int i=0;i<2;i++){
		string temp;
        cin>>temp;
		/*处理读取中遇到的负号*/
        if(temp[0]=='-') {
            //input[i].min = 1;
            temp = temp.substr(1,temp.length()-1); //截取负号后的数字
			input[i].fenzi = stoll(temp.substr(0,temp.find("/"))); //stoll转化为数字 很关键
			input[i].fenzi = (-1)*input[i].fenzi; //分子乘上负号
        }
		else{
			input[i].fenzi = stoll(temp.substr(0,temp.find("/")));
		}
		//cout<<temp<<endl;
		//printf("input fenzi is %d\n",input[i].fenzi);
		/*处理分子*/
        input[i].fenmu = stoll(temp.substr(temp.find("/")+1,temp.length()-temp.find("/")-1));
		if(input[i].fenmu==0) input[i].fenmu = -1;
		//printf("input fenmu is %d in pos %d to %d \n",input[i].fenmu,int(temp.find("/")+1),int(temp.length()-temp.find("/")-1));
		/*读取处理结束*/
		input[i] = simplify(input[i].zhengshu,input[i].fenzi,input[i].fenmu);
 		//printf("%lld %lld %lld \n",input[i].zhengshu,input[i].fenzi,input[i].fenmu);
		//cout<<to_string(input[i])<<endl;
    }

	num sum;
	//cout<<"加法"<<endl;
	sum = add(input[0],input[1]);//
    //printf("加法 %d %d %d \n",sum.zhengshu,sum.fenzi,sum.fenmu);
	cout<<to_string_output(input[0])<<" + "<<to_string_output(input[1])<<" = "<<to_string_output(sum)<<endl;

	num minu;
	//cout<<"减法"<<endl;
	minu = jianfa(input[0],input[1]);//
	cout<<to_string_output(input[0])<<" - "<<to_string_output(input[1])<<" = "<<to_string_output(minu)<<endl;

	num mul;
	//cout<<"乘法"<<endl;
	mul = chengfa(input[0],input[1]);//
	cout<<to_string_output(input[0])<<" * "<<to_string_output(input[1])<<" = "<<to_string_output(mul)<<endl;

	num dev;
	//cout<<"除法"<<endl;
	dev = chufa(input[0],input[1]);//
	cout<<to_string_output(input[0])<<" / "<<to_string_output(input[1])<<" = "<<to_string_output(dev)<<endl;	

    return 0;
}
