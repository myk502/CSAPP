#include<stdio.h>
#include<iso646.h>
#include<stdlib.h>
#include<string.h>
void trans_5(int M, int N)
{
	int ii, jj, i, j;
	bool test[1000][1000];
	memset(test, 0, sizeof(test));
	for(ii = 0; (ii + 8) < M; ii += 8)
		for(jj = 0; (jj + 8) < N; jj += 8)
		{
			for(i = ii; (i < ii + 8); i++)
				for(j = jj; (j < jj + 8); j++)
				{
					test[i][j] = true;
				}
		}
	printf("ii = %d\n, jj = %d\n", ii, jj);
	for(i = ii; i < M; i++)
		for(j = 0; j < N; j++)
			test[i][j] = true;
	for(i = 0; i < ii; i++)
		for(j = jj; j < N; j++)
			test[i][j] = true;
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			if(!test[i][j])
				printf("(%d, %d)\n", i, j);
}

int main(int argc, char** argv)
{
	trans_5(61, 67);
	return 0;
}
