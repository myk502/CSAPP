#include<stdio.h>
//The first edition
//pay attention to i overflow and underflow
//8*i should be represented in bit shift form
unsigned replace_byte(unsigned x,int i,unsigned char b)
{
    if(i<0)
    {
        printf("Error! i should not be negative!\n");
        return x;
    }
    if(i>=sizeof(-1))
    {
        printf("i is too big!\n");
        return x;
    }

    unsigned mask1=0xffffffff-( (0xff)<<(i<<3) );

    return (x&mask1)|(b<< (i<<3) );
}

int main(void)
{
    printf("%#8X\n%#8X\n",replace_byte(0x12345678,2,0xAB),replace_byte(0x12345678,0,0xAB) );
    return 0;
}
