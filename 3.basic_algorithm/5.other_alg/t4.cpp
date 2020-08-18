#include <iostream>
#include <string>
#include <vector>
using namespace std;


// class Solution {
// public:
//     int minDays(int n) {
//         int cnt  = 1;
//         while(n!=1){
//             if(n%2==0){
//                 n = n/2;
//                 cnt+=1;
//                 cout<<"case 1"<<endl;
//             }else if((n-1)%2==0){
//                 if(n%3==0){
//                     if(minDays(n/3)+1>minDays((n-1)/2)){
//                         n = (n-1)/2;
//                         cnt+=2;
//                         cout<<"case 2"<<endl;
//                     }else{
//                         n = n/3;
//                         cnt+=1;
//                         cout<<"case 3"<<endl;
//                     }
//                 }else{
//                     n = (n-1)/2;
//                     cnt+=2;
//                     cout<<"case 4"<<endl;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int minDays(int n) {
        int cnt  = 1;
        while(n!=1){
            if(n%3==0){
                cnt+=1;
                n = n/3;
            }else if((n-1)%3==0){
                if((n-1)%2==0){
                    cnt+=2;
                    n = (n-1)/2;
                }else{
                    int x = (n-1)/3;
                    int y = n/2;
                    if(minDays(x)+1 > minDays(y)){
                        n = n/2;
                        cnt+=1;
                    }else{
                        n = (n-1)/3;
                        cnt+=2;
                    }
                }
            }else if((n-2)%3==0){
                if(n%2==0){
                    int x = (n-2)/3;
                    int y = (n/2);
                    if(minDays(x)+2>minDays(y)){
                        n = n/2;
                        cnt+=1;
                    }else{
                        n = (n-1)/3;
                        cnt+=2;
                    }
                }else
                {   
                    int x = (n-2)/3;
                    int y = ((n-1)/2);
                    if(minDays(x)+2>minDays(y)+1){
                        n = (n-1)/2;
                        cnt+=2;
                    }else{
                        n = (n-2)/3;
                        cnt+=3;
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){

    int n = 6;
    Solution so;
    cout<<so.minDays(n)<<endl;

    return 0;
}