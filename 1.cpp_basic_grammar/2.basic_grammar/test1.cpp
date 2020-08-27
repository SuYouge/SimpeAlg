#include <iostream>

using namespace std;

template <typename T>

void print(T t)

{

    cout<<"The value is "<<t<<endl;

}

template <>

void print<char *>(char* c)

{

    cout<<"The string is " << c <<endl;

}

int main()

{

    char str[] = "TrendMicro[char]";

    unsigned char ustr[] = "TrendMicro[unsigned char]";

    print(str);

    print(ustr);

    return 0;

}