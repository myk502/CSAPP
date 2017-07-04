#include<stdio.h>
#include<stdint.h>

int tmult_ok(int x,int y)
{
    int64_t xx=x,yy=y;
    int64_t product=xx*yy;
    return (product==(x*y) );
}

int main(void)
{
    printf("%d %d\n",tmult_ok(100,100),tmult_ok(1000000,1000000) );
    return 0;
}
