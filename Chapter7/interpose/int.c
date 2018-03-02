#include<malloc.h>
void* mymalloc(size_t size);
int main(void)
{
	int *p = malloc(32);
	free(p);
	return 0;
}
