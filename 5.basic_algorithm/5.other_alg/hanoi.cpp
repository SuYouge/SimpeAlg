#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void move(vector<int>& A, vector<int>& B){
        B.push_back(A.back());
        A.pop_back();
    }
    void hanoi(int n, vector<int>& A, vector<int>& B, vector<int>& C){
        if(n==1)
            move(A,C);
        else{
            hanoi(n-1, A,C,B);
            move(A,C);
            hanoi(n-1, B,A,C);
        }
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        hanoi(A.size(),A,B,C);
    }
};

void move(char A, char B);
void hanoi(int n,char A, char B, char C);
int main(int argc, char const *argv[])
{
    cout<<"输入盘子的数目：";
    int disks;
    cin>>disks;
    hanoi(disks,'A','B','C');
    return 0;
}


void move(char A, char B)
{
    cout<<A<<"->"<<B<<endl;
}

void hanoi(int n, char A, char B, char C)
{
    if (n==1)
    {
        move(A,C);
    }
    else
    {
        hanoi(n-1,A,C,B);
        move(A,C);
        hanoi(n-1,B,A,C);
    }
}