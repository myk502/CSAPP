#include<stdio.h>

/*This function determines whether int is 32bit on this machine
  Assume int is no less than 16 bit
  */
int int_size_is_32(void)
{
    unsigned x=-1;
    x>>=15;
    x>>=15;
    x>>=1;
    return (x==1);
}

int main(void)
{
    printf("%d\n",int_size_is_32());
    return 0;
}
