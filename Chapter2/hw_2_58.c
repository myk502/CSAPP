#include<stdio.h>

int is_little_endian(void)
{
    int x=1;
    unsigned char* ptr=(unsigned char*) &x;
    if(*ptr==0)
        return 0;
    else
        return 1;
}
int main(void)
{
    printf("%d\n",is_little_endian() );
    return 0;
}
