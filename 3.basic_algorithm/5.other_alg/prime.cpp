#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXN 20
int prime[MAXN];
int visit[MAXN];

// 1. 判断素数
bool is_prime(int x)
{
    if (x == 1 || x == 0 || x < 0)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
void test_prime(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (is_prime(i))
            cout << i << " is a prime" << endl;
        else
            cout << i << " is not a prime" << endl;
    }
}

// 2. 生成素数
void gen_prime()
{
    memset(prime, 0, MAXN);
    memset(visit, 0, MAXN);
    int cnt = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        cout<<"in "<<i<<" th loop"<<endl;
        if (!visit[i])
        {
            prime[cnt++] = i;
            cout<<i<<" is a prime"<<endl;
        }
        for (int j = 0; j < cnt && i * prime[j] <= MAXN; j++)
        {
            visit[i * prime[j]] = 1; // visit
            cout << "visit " << i * prime[j] << endl;
            if (i % prime[j] == 0){ // stop
                cout<<"break at "<< prime[j] <<endl;
                break;
            }
        }
    }
    // for(int i =0;i<MAXN;i++){
    //     if(prime[i]!=0){
    //         cout<<prime[i]<<endl;
    //     }
    // }
}
int main(int argc, char *argv[])
{
    // test_prime(10);
    gen_prime();
    return 0;
}