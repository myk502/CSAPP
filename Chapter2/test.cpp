#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	double x = sqrt(-1.0);
	unsigned char* ptr = (unsigned char*)&x;
	for(int i = 0; i < 8;i++)
		printf("%2X ",*(ptr + i));
	return 0;
}
