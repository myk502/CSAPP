#include<stdio.h>
#include<assert.h>

int odd_ones(unsigned x)
/*return 1 when x contains an odd number of 1s,0 otherwise
Assume w=32
*/
{
    //by using xor,we use the first 16 bit as a whole number
    x^=x>>16;
    //and the same so on
    x^=x>>8;
    x^=x>>4;
    x^=x>>2;
    x^=x>>1;
    x&=0x1;
    return x;
}

int main(void)
{
    printf("%d\n%d\n",odd_ones(1),odd_ones(0));
    return 0;
}
