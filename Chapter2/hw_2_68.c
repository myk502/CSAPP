#include<stdio.h>

/*
  *Mask with least significant n bits set to 1
  *Examples:n=6->0x3F;n=17->0x1FFFF
  *Assume 1<=n<=w
  */

int lower_one_mask(int n)
{
    int w=sizeof(int);
    unsigned x=-1;
    return x>>(w-n);
}
int main(void)
{
    printf("%#010X\n%#010X\n",lower_one_mask(6),lower_one_mask(17));
    return 0;
}
