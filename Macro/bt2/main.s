	.file	"main.c"
	.text
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_sub
	.def	_sub;	.scl	2;	.type	32;	.endef
_sub:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_mul
	.def	_mul;	.scl	2;	.type	32;	.endef
_mul:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_div
	.def	_div;	.scl	2;	.type	32;	.endef
_div:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fdivs	12(%ebp)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Sum of 3 and 5 is %d\12\0"
LC2:
	.ascii "Difference  of 3 and 5 is %d\12\0"
LC3:
	.ascii "Product of 3 and 5 is %d\12\0"
LC6:
	.ascii "Quotient of 3 and 5 is %f\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$5, 4(%esp)
	movl	$3, (%esp)
	call	_add
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$3, (%esp)
	call	_sub
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$5, 4(%esp)
	movl	$3, (%esp)
	call	_mul
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	flds	LC4
	fstps	4(%esp)
	flds	LC5
	fstps	(%esp)
	call	_div
	fstpl	4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.section .rdata,"dr"
	.align 4
LC4:
	.long	1084227584
	.align 4
LC5:
	.long	1077936128
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
