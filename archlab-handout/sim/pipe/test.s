	.file	"test.c"
	.text
	.p2align 4,,15
	.globl	myfun
	.type	myfun, @function
myfun:
.LFB0:
	.cfi_startproc
	testq	%rdx, %rdx
	jle	.L5
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movq	(%rdi,%rcx,8), %r8
	movq	%r8, (%rsi,%rcx,8)
	cmpq	$0, (%rdi,%rcx,8)
	jle	.L3
	addq	$1, %rax
.L3:
	addq	$1, %rcx
	cmpq	%rcx, %rdx
	jne	.L4
	rep ret
	.p2align 4,,10
	.p2align 3
.L5:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	myfun, .-myfun
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
