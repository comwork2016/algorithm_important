#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

int hammingDistance(uint32_t lhs, uint32_t rhs)
{
    unsigned short cnt = 0;
    lhs ^= rhs;
    while(lhs)
    {
        lhs &= lhs - 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    uint32_t lhs;
    uint32_t rhs;
    printf("input two number to calculate hamming distance(ctrl+c to quit)\n");
    while(scanf("%d %d",&lhs,&rhs)!=EOF)
    {
        int hd = hammingDistance(lhs,rhs);
        printf("hamming distance between %d and %d is %d\n",lhs,rhs,hd);
    }
    return 0;
}
