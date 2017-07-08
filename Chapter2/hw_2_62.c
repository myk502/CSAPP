#include<stdio.h>

int int_shifts_are_arithmetic(void)
{
    int x=-1;
    x=(x>>1);
    unsigned w=sizeof(int);
    x=(x>>(w-1));
    x=x&0x1;
    return x;
}
//using  !(x^(x>>1)) could be better
int main(void)
{
    printf("%d\n",int_shifts_are_arithmetic());
    return 0;
}
