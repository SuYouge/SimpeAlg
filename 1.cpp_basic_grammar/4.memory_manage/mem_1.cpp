/*
静态常量区：
    静态变量和全局变量的存储区域是一起的，一旦静态区的内存被分配, 
    静态区的内存直到程序全部结束之后才会被释放
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    {
        // 内存分配自动对齐
        const bool b = true;
        const char c = 'c';
        const char16_t ch16 = 'c';
        const short sh = 1;
        const wchar_t wc = 'w';
        const int i = 5;
        const float f = 1.f;
        const long l = 12.0l;
        const long long ll = 13.0;
        const double d = 12.;
        const long double ld = 12.;
        const long double ld_end = 12.;
        printf("bool :          %p %04d\n", &b, sizeof(bool));
        printf("char :          %p %04d\n", &c, sizeof(char));
        printf("char16_t :      %p %04d\n", &ch16, sizeof(char16_t));
        printf("short :         %p %04d\n", &sh, sizeof(short));
        printf("wchar_t :       %p %04d\n", &wc, sizeof(wchar_t));
        printf("int :           %p %04d\n", &i, sizeof(int));
        printf("float :         %p %04d\n", &f, sizeof(float));
        printf("long :          %p %04d\n", &l, sizeof(long));
        printf("long long :     %p %04d\n", &ll, sizeof(long long));
        printf("double :        %p %04d\n", &d, sizeof(double));
        printf("long double :   %p %04d\n", &ld, sizeof(long double));
        printf("long double :   %p %04d\n", &ld_end, sizeof(long double));
    }

    return 0;
}