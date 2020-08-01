/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 20:09:06
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 20:21:55
 * @Description: 后台线程（守护线程）
 */

#include <thread>
#include <iostream>
// #include <chrono>

// 前台计数，后台计时

// 获取系统当前时间
std::string getCurrentSystemTime()
{
	auto tt = std::chrono::system_clock::to_time_t
		(std::chrono::system_clock::now());
	struct tm* ptm = localtime(&tt);
	char date[60] = { 0 };
	sprintf(date, "%d-%02d-%02d-%02d.%02d.%02d",
		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);
	return std::string(date);
}

void sleep(int k){
    for(int i =0; i<k;i++){
        for(int j =0;j<k;j++){
        }
    }
}

void timing(){
    // 隔一段时间进行一次输出
    while(1){
        std::cout<<getCurrentSystemTime()<<std::endl;
        sleep(10);
    }
}

void counting(){
    for(int i=0;i<100000;i++){
        std::cout<<i<<std::endl;
    }
}


int main(){
    
    std::thread t(timing);  //③
    t.detach();  //④

    std::thread c(counting);
    c.join();
    
    return 0;
}