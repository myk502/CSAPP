void good_incr(int* ptr)
{
	asm(
		"leaq(%%rbx, %%rbx, 4), %0"
		: "=r" (x)
		: "0" (x)
	   );

}
