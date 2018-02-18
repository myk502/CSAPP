#include<stdio.h>
#include<iso646.h>
#include<stdlib.h>
#include<string.h>
void trans_5(int M, int N)
{
	int ii, jj, i, j;
	bool test[M][N];
	memset(test, 0, sizeof(test));
	for(ii = 0; ii < N; ii += 8)
		for(jj = 0; jj < M; jj += 8)
		{
			for(i = ii; i < ii + 8; i++)
				for(j = jj; j < jj + 8; j++)
				{
					printf("i = %d, j = %d\n", i, j);
					test[i][j] = true;
				}
		}
	ii -= 8;
	jj -= 8;
	printf("ii = %d\n, jj = %d\n", ii, jj);
	for(i = ii; i < N; i++)
		for(j = 0; j < M; j++)
			test[i][j] = true;
	for(i = 0; i < ii; i++)
		for(j = jj; j < M; j++)
			test[i][j] = true;
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			if(!test[i][j])
				continue;
				//printf("(%d, %d)\n", i, j);
}

int main(int argc, char** argv)
{
	trans_5(61, 67);
	return 0;
}
