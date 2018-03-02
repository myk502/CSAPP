#ifdef COMPILETIME
#include<stdio.h>
#include<malloc.h>

void* mymalloc(size_t size)
{
	void* ptr = malloc(size);
	printf("malloc(%d)=%p\n", (int)size, ptr);
	return ptr;
}

void myfree(void* ptr)
{
	free(ptr);
	printf("free(%p)\n", ptr);
}
#endif
#ifdef LINKTIME	
#include<stdio.h>

void* __real_malloc(size_t size);
void __real_free(void* ptr);

void* __wrap_malloc(size_t size)
{
	void* ptr = __real_malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

void __wrap_free(void* ptr)
{
	__real_free(ptr);
	printf("free(%p)\n", ptr);
}
#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include<stdlib.h>
#include<dlfcn.h>
#include<stdio.h>
#include<string.h>
void* malloc(size_t size)
{
	static int cnt = 0;
	cnt++;
	void* (*mallocp)(size_t size);
	char* error;
	mallocp = dlsym(RTLD_NEXT, "malloc");
	if((error = dlerror()) != NULL)
	{
		printf("Error!%s\n", error);
		exit(1);
	}
	void* ptr = mallocp(size);
	if(cnt == 1)
		printf("malloc size = %d\n", (int)size);
	//printf("malloc(%d) = %p\n", (int)size, ptr);
	cnt--;
	return ptr;
}

void free(void* ptr)
{
	void (*freep)(void*) = NULL;
	char* error;
	if(!ptr)
		return;
	freep = dlsym(RTLD_NEXT, "free");
	if((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}
	freep(ptr);
	fprintf(stderr, "free(%p)\n", ptr);
}
#endif
