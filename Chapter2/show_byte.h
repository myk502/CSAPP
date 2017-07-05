//This is the header file of functions in show_byte.h
#ifndef _SHOW_BYTE_H
#define SHOW_BYTE_H
#include<stddef.h>
typedef unsigned char* byte_pointer;
void show_byte(byte_pointer start,size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void* x);
#endif
