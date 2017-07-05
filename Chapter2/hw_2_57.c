#include<stdio.h>
#include"show_byte.h"

void show_short(short x)
{
    show_byte((byte_pointer)&x,sizeof(short) );
}
void show_long(long x)
{
    show_byte((byte_pointer)&x,sizeof(long ));
}
void show_double(double x)
{
    show_byte((byte_pointer)&x,sizeof(double));
}

int main(void)
{
    show_short(23);
    show_long(1e15);
    show_double(2.3e24);
    return 0;
}
