#include <iostream>
using namespace std;
#define MAX 2147483647
#define MIN -2147483648
class Solution{    
    public :
        //const int MAX = (1<<31)-1, MIN = (-1<<31);
        int reverse(int x){
            if (x/10==0) return x;

            long y =0;
            while(x){
                    y*=10;
                    if (y>MAX||y<MIN)
                        return 0;
                    y+=x%10;
                    x/=10;
                }
            return y; 
        }
};

int main()
{
    int a = 12389;
    Solution solution;
    int y = 0;
    y = solution.reverse(a);
    cout<<y<<endl;
    return 0;
}
