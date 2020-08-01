#include <vector>
#include <iostream>
using namespace std;

namespace Matrix{

class matrix{

public:
    matrix(){}
    // rows, cols, value, identity?
    matrix(int m, int n, int value, bool flag){
        rows = m; cols = n;
        int num;
        if(flag) {num = value; value = 0;}
        vector<int> tmp(n,value);
        for(int i=0;i<m;i++){
            data.push_back(tmp);
        }
        if(flag){
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++){
                    if(i==j) data[i][j]=num;
                }
        }
    }

    matrix(vector<vector<int>>& m):data(m),rows(m.size()),cols(m[0].size()){}
    /*
        operator=重载
    */
    matrix& operator=(const matrix& input){
        this->data = input.data;
        this->rows = input.rows;
        this->cols = input.cols;
        return *this;
    }

    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
public:
    matrix mul(matrix a, matrix b){}
public:
    int rows; // ;
    int cols; // ;
    vector<vector<int>> data;
};

void print(matrix m){
        for(int i=0;i<m.rows;i++){
            for(int j=0;j<m.cols;j++){
                cout<<m.data[i][j]<<" ";
            }
            cout<<endl;
        }
}

matrix mul(matrix a, matrix b){
    matrix res(a.rows, b.cols, 0,false);
    for (int i = 0;i < a.rows;i++) {
        for (int j = 0;j < b.cols;j++) {
            for (int k = 0;k < b.rows;k++) {
                res.data[i][j] = res.data[i][j] + (a.data[i][k] * b.data[k][j]);
            }
        }
    }
    return res;
}

/*
    only for square matrix
*/

matrix pow(matrix a, int n){
    matrix res(a.rows, a.rows, 1,true);
    while(n){
        if(n&1) res = mul(res, a);
        a = mul(a,a);
        // cout<<"a = "<<endl; Matrix::print(a);
        n = n>>1;
    }
    return res;
}

}



int main(){
    
    vector<vector<int>> m = {{1,2,3,4},
                            {4,5,6,7},
                            {6,7,8,9},
                            {6,7,8,9}};
    vector<vector<int>> n = {{1,1,1,1},
                            {1,1,1,1},
                            {1,1,1,1},
                            {1,1,1,1}};
    // Matrix::matrix a(m);
    // cout<<"a = "<<endl; a.print();
    Matrix::matrix b(n);
    cout<<"b = "<<endl; Matrix::print(b);
    // auto res = Matrix::mul(a,b);
    // cout<<"res = "<<endl; Matrix::print(res);
    auto res = Matrix::pow(b,2);
    cout<<"res = "<<endl; Matrix::print(res);
    return 0;
}