#include<stdio.h>

unsigned int fun(unsigned int x,unsigned int y)
{
    return (x&0x000000ff)+(y&0xffffff00);
}
//Actually,we could simply this formula to (x & 0XFF) | (y & ~0XFF)
//the addition and or are the same
int main(void)
{
    int x=0x89abcdef;
    int y=0x76543210;
    printf("%#8X\n",fun(x,y));
    return 0;
}
