#include<stdio.h>
#include<assert.h>

int fun(int x)//The required funciton for 2.61
{
    int condition1,condition2,condition3,condition4;
    //The four conditions
    condition1=!(x+1);
    //x equals to -1
	//The answer shows that !~x is a better answer
    condition2=!x;
    //x equals to 0  
    condition3=!((x&0xff)-0xff);
    //LSB in x equals to 1
	//!~(x|~0xff) is better
    unsigned w=sizeof(int)<<3;
    //w is the length of int(bit representation);
    int y=(x>>(w-8))&0xff;
    //y is the MSB of x
    condition4=!y;
    return condition1||condition2||condition3||condition4; 
}

int main(void)
{
    assert(fun(-1));
    assert(fun(-2323));
    return 0;
}
