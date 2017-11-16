#define n 10
int a[n][n];
int b[n][n];
int c[n][n];

void column(void)
{
	int j, k, i;
	int r;
	for(j = 0; j < n; j++)
	{
		for(k = 0; k < n; k++)
		{
			r = b[k][j];
			for(i = 0; i < n; i++)
				c[i][j] += a[i][k] * r;
		}
	}
}
