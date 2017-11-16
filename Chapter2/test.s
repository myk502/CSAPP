	.file	"test.c"
	.text
	.globl	column
	.type	column, @function
column:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	call	__x86.get_pc_thunk.bp
	addl	$_GLOBAL_OFFSET_TABLE_, %ebp
	movl	$0, (%esp)
	jmp	.L2
.L4:
	leal	0(,%eax,4), %ecx
	leal	(%ecx,%eax), %ebx
	leal	(%ebx,%ebx), %edx
	addl	%edi, %edx
	movl	a@GOT(%ebp), %ebx
	movl	4(%esp), %esi
	imull	(%ebx,%edx,4), %esi
	movl	c@GOT(%ebp), %ebx
	addl	%eax, %ecx
	leal	(%ecx,%ecx), %edx
	addl	(%esp), %edx
	addl	%esi, (%ebx,%edx,4)
	addl	$1, %eax
.L3:
	cmpl	$9, %eax
	jle	.L4
	addl	$1, %edi
.L6:
	cmpl	$9, %edi
	jg	.L9
	leal	(%edi,%edi,4), %edx
	leal	(%edx,%edx), %eax
	addl	(%esp), %eax
	movl	b@GOT(%ebp), %edx
	movl	(%edx,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$0, %eax
	jmp	.L3
.L9:
	addl	$1, (%esp)
.L2:
	cmpl	$9, (%esp)
	jg	.L10
	movl	$0, %edi
	jmp	.L6
.L10:
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	column, .-column
	.comm	c,400,32
	.comm	b,400,32
	.comm	a,400,32
	.section	.text.__x86.get_pc_thunk.bp,"axG",@progbits,__x86.get_pc_thunk.bp,comdat
	.globl	__x86.get_pc_thunk.bp
	.hidden	__x86.get_pc_thunk.bp
	.type	__x86.get_pc_thunk.bp, @function
__x86.get_pc_thunk.bp:
.LFB1:
	.cfi_startproc
	movl	(%esp), %ebp
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
