#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

    float c[1001] = {0};

    int ka, kb , t;

    float coef;

    scanf("%d", &ka); // get K
    for(int i =0; i<ka;i++){
        scanf("%d%f", &t,&coef);
        c[t]+= coef;
    }

    scanf("%d", &kb);
    for(int i=0;i<kb;i++){
        scanf("%d%f", &t,&coef);
        c[t]+= coef;
    }
    int cnt = 0;
    for(int i=0; i<1001; i++){
        if(c[i]!=0) cnt++;
    }
    printf("%d",cnt);

    for(int i=1000; i>=0;i--){
        if(c[i]!= 0.0)
            printf(" %d %.1f", i,c[i]);
    }

    return 0;
}