#include<stdio.h>
typedef unsigned char *byte_pointer;
void show_byte(byte_pointer start,int offset)
{
    for(int i=0;i<offset;i++)
        printf("%.2x",start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_byte( (byte_pointer) &x,sizeof(int) );
}

void show_float(float x)
{
    show_byte( (byte_pointer) &x,sizeof(float) );
}

void show_pointer(void *x)
{
    show_byte( (byte_pointer) &x,sizeof(void*) );
}
