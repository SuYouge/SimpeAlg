#include <iostream>
#include <memory>
using namespace std;

#define SIZE 5

class A
{
public:
    A(int a, int b) : a_(a), b_(b) {}
    int a_;
    int b_;
};

int main()
{
    // C风格
    printf("C风格内存分配\n");
    int *arr = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i;
        printf("%02d  %p\n", arr[i], &arr[i]);
    }
    free(arr); // 还要注意将指针指向NULL
    // arr = nullptr

    int *arr_n = (int *)malloc(sizeof(int));
    *arr_n = 9;
    printf("\n");
    printf("内存释放后再分配，起点相同\n");
    printf("%02d  %p\n", *arr_n, arr_n);
    free(arr_n);
    printf("\n");

    printf("内存释放后再访问指针指向的地址可能得到无意义的值\n");
    for (int i = 0; i < SIZE; i++)
    {
        // 释放后的指针指向的内存值可能随机
        printf("%02d  %p\n", arr[i], &arr[i]);
    }
    printf("\n");

    /// C++风格
    printf("C++风格内存分配\n");
    int *pint = new int;
    *pint = 5;
    printf("内存释放后再分配，起点相同\n");
    printf("%02d  %p\n", *pint, pint);
    delete pint;
    printf("内存释放后再访问指针指向的地址可能得到无意义的值\n");
    printf("%02d  %p\n", *pint, pint); // 随机值

    printf("\n");
    int *arr_p = new int[SIZE];
    printf("内存释放后再分配，起点相同\n");
    for (int i = 0; i < SIZE; i++)
    {
        arr_p[i] = i;
        printf("%02d  %p\n", arr_p[i], &arr_p[i]); // 随机值
    }
    delete[] arr_p;
    printf("\n");
    printf("内存释放后再访问指针指向的地址可能得到无意义的值\n");
    for (int i = 0; i < SIZE; i++)
    {
        // arr_p[i] = i;
        printf("%02d  %p\n", arr_p[i], &arr_p[i]); // 随机值
    }

    printf("连续分配两个位置\n");
    int *p1 = new int;
    int *p2 = (int *)malloc(sizeof(int));
    *p1 = 1;
    *p2 = 2;
    printf("%02d  %p\n", *p1, p1); //
    printf("%02d  %p\n", *p2, p2); //
    delete p1;                     // 注意指针仍然有效
    printf("释放p1 分配给p3\n");
    int *p3 = new int;
    *p3 = 3;
    printf("%02d  %p\n", *p3, p3); // 哪里有空位就补哪里
    free(p2);
    delete p3; // 注意指针仍然有效
    printf("释放p3\n");
    A *a = new A(1,2);
    printf("%02d %02d %p\n", a->a_,a->b_, a); // 哪里有空位就补哪里
    int* ni = new int;
    *ni = 8;
    printf("%02d  %p\n", *ni, ni); // 哪里有空位就补哪里
    delete a;
    delete ni;
    
    return 0;
}