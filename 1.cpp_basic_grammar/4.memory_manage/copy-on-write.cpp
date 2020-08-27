#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main()
{
    string str1 = "hello world";
    string str2 {str1};
 
    printf ("Sharing the memory:\n");
    printf ("str1's address: %x\n", &str1);
    printf ("str2's address: %x\n", &str2);
    // printf ("str1's address: %x\n", str1.c_str());
    // printf ("str2's address: %x\n", str2.c_str());
 
    // str1[0]='q';
    // str2[0]='w';
 
    printf ("After Copy-On-Write:\n");
    // printf ("str1's address: %x\n",str1.c_str());
    // printf ("str2's address: %x\n",str2.c_str());
    printf ("str1's address: %x\n", &str1);
    printf ("str2's address: %x\n", &str2);
    printf("Hello world!");
    return 0;
}