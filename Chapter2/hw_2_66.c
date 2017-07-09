#include<stdio.h>

/*Generate mask indicating leftmost 1 in x Assume w=32
 *For example,0xFF00->0x8000 , and 0x6600 -> 0x4000
 *if x=0,then return 0
 */
int leftmost_one(unsigned x)
{
    //First change x to the form[000...0111..1]
    x|=x>>1;
    x|=x>>2;
    x|=x>>4;
    x|=x>>8;
    x|=x>>16;
    //then return the answer
    return x^(x>>1);
}


int main(void)
{

    return 0;
}
