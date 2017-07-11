#include<stdio.h>
/*
 * Do rotating left shift. Assume 0<=n<w
 * Example when x=0x12345678 and w=32
 *  n=4->0x23456781    n=20->0x67812345
 */
unsigned rotate_left(unsigned x,int n)
{
    int w=sizeof(int)<<3;
    unsigned A=x>>(w-n-1)>>1;//avoid undefined behaviour
    unsigned B=x<<n;
    return A|B;
}

int main(void)
{
    printf("%#X\n%#X\n",rotate_left(0x12345678,4),rotate_left(0x12345678,20));
    return 0;
}
