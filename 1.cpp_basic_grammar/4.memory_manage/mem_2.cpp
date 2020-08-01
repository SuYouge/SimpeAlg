#include <cstdio>
#include <cstdint>
#include <memory.h>
#include <cstdlib>

struct StructSample
{
    uint32_t uValue;
    float fValue;
    char carr[4];
    short sarr[2];
};

union UnionSample {
    StructSample s;
    uint32_t uarr[4];
};

uint32_t sampleSum(UnionSample _un)
{
    UnionSample u = _un;
    uint32_t s = u.uarr[0] + u.uarr[1] + u.uarr[2] + u.uarr[3];
    return s;
}
void funB();
void funA()
{
    printf("进入funA\n");
    StructSample sSample;                       // sizeof( StructSample ) == 16
    uint32_t arrSample[4];                      // sizeoof(uint32_t) * 4 == 16
    UnionSample uSample;                        // 同样也是16字节大小
    UnionSample *samplePtr = new UnionSample(); // 同样效果的方法还有 malloc,calloc 等
    // memcpy dst, src
    memcpy(samplePtr, &sSample, sizeof(StructSample));
    uint32_t sum = sampleSum(*samplePtr);

    printf("%p %04d\n", &sSample, sizeof(sSample));
    printf("%p %04d\n", &arrSample, sizeof(arrSample));
    printf("%p %04d\n", &uSample, sizeof(uSample));
    printf("%p %04d\n", &samplePtr, sizeof(samplePtr));
    printf("%p %04d\n", &sum, sizeof(sum));
    funB();
}

void funB()
{
    printf("进入funB\n");
    StructSample sSample;                       // sizeof( StructSample ) == 16
    uint32_t arrSample[4];                      // sizeoof(uint32_t) * 4 == 16
    UnionSample uSample;                        // 同样也是16字节大小
    UnionSample *samplePtr = new UnionSample(); // 同样效果的方法还有 malloc,calloc 等
    // memcpy dst, src
    memcpy(samplePtr, &sSample, sizeof(StructSample));
    uint32_t sum = sampleSum(*samplePtr);

    printf("%p %04d\n", &sSample, sizeof(sSample));
    printf("%p %04d\n", &arrSample, sizeof(arrSample));
    printf("%p %04d\n", &uSample, sizeof(uSample));
    printf("%p %04d\n", &samplePtr, sizeof(samplePtr));
    printf("%p %04d\n", &sum, sizeof(sum));
}

int main(int _argc, char **_argv)
{

    StructSample sSample;                       // sizeof( StructSample ) == 16
    uint32_t arrSample[4];                      // sizeoof(uint32_t) * 4 == 16
    UnionSample uSample;                        // 同样也是16字节大小
    UnionSample *samplePtr = new UnionSample(); // 同样效果的方法还有 malloc,calloc 等
    // memcpy dst, src
    memcpy(samplePtr, &sSample, sizeof(StructSample));
    uint32_t sum = sampleSum(*samplePtr);

    printf("%p %04d\n", &sSample, sizeof(sSample));
    printf("%p %04d\n", &arrSample, sizeof(arrSample));
    printf("%p %04d\n", &uSample, sizeof(uSample));
    printf("%p %04d\n", &samplePtr, sizeof(samplePtr));
    printf("%p %04d\n", &sum, sizeof(sum));
    funA();
    // funB();
    return 0;
}