#include<stdio.h>
#include<assert.h>
#include<limits.h>

unsigned srl(unsigned x,int k)
{
    /*Perform shift arithmatically*/
    unsigned xsra=(int)x >>k;
    //set the mask 0xffffffff
    unsigned mask=-1;
    //The low w-k bit of mask is 1 while the high k bit of mask is 0
    mask=mask>>k;
    return xsra&mask;
}

int sra(int x,int k)
{
    /*Perform shift logically*/
    int xsrl=(unsigned)x>>k;
    unsigned w=sizeof(int)<<3;
    int mask=1<<(w-k-1);
    return (xsrl^mask)-mask;
}

int main(void)
{
    printf("%#010X\n",sra(-1,5));
    return 0;
}
