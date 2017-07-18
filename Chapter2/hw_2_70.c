#include<stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1<=n<=w
 */
int fits_bits(int x,int n)
{
	//use long long to avoid overflow
	long long num=(long long)x;
	long long left=-(1LL<<(n-1));
	long long right=(1LL<<(n-1))-1;
	return (num>=left)&&(num<=right);
}

int main(void)
{
	printf("%d\n",fits_bits(1000000,30));
	return 0;
}
