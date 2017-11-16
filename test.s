	.file	"test.c"
	.text
	.globl	useless
	.type	useless, @function
useless:
.LFB38:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE38:
	.size	useless, .-useless
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$268435456, %edi
	call	malloc@PLT
	movq	%rax, p1(%rip)
	movl	$256, %edi
	call	malloc@PLT
	movq	%rax, p2(%rip)
	movl	$268435456, %edi
	call	malloc@PLT
	movq	%rax, p3(%rip)
	movl	$256, %edi
	call	malloc@PLT
	movq	%rax, p4(%rip)
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	p4,8,8
	.comm	p3,8,8
	.comm	p2,8,8
	.comm	p1,8,8
	.comm	beyond,4,4
	.comm	huge_arrar,268435456,32
	.comm	bit_array,16777216,32
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
