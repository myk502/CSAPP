	.file	"test.c"
	.text
	.globl	trans_1
	.type	trans_1, @function
trans_1:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdx, %rbx
	movslq	%edi, %rdx
	movslq	%esi, %r11
	movl	$0, %ebp
	jmp	.L2
.L3:
	movslq	%esi, %rdi
	movq	%rdi, %rax
	imulq	%rdx, %rax
	leaq	(%rbx,%rax,4), %r8
	movslq	%r9d, %rax
	movl	(%r8,%rax,4), %r8d
	imulq	%r11, %rax
	leaq	(%rcx,%rax,4), %rax
	movl	%r8d, (%rax,%rdi,4)
	addl	$1, %esi
.L4:
	leal	8(%r10), %eax
	cmpl	%eax, %esi
	jl	.L3
	addl	$1, %r9d
.L5:
	leal	8(%rbp), %eax
	cmpl	%eax, %r9d
	jge	.L11
	movl	%r10d, %esi
	jmp	.L4
.L11:
	addl	$8, %r10d
.L6:
	cmpl	$31, %r10d
	jg	.L12
	movl	%ebp, %r9d
	jmp	.L5
.L12:
	addl	$8, %ebp
.L2:
	cmpl	$31, %ebp
	jg	.L13
	movl	$0, %r10d
	jmp	.L6
.L13:
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	trans_1, .-trans_1
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
