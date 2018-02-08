long myfun(long *a, long *b,long n)
{
	long cnt = 0L;
	for(long i = 0L ; i < n; i++)
	{
		b[i] = a[i];
		if(a[i] > 0L)
			cnt++;
	}
	return cnt;
}
