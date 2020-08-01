#include <iostream>
using namespace std;

inline double area(double radius);

int main(){
    cout<<area(1)<<endl;
    return 0;
}

inline double area(double radius){
    return 3.14159265 * radius * radius;
}
