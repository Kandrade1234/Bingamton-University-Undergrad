	.file	"powF.c"
	.text
	.globl	powF
	.type	powF, @function
powF:
.LFB0:
	.cfi_startproc
	pushq	%rbp		# push the frame pointer on to the stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	# set stack frame to current frame's address
	.cfi_def_cfa_register 6
	subq	$16, %rsp	# allocate space on the stack
	movl	%edi, -4(%rbp)  # move pow argument onto stack
	movl	%esi, -8(%rbp)	# move base argument onto stack
	cmpl	$0, -4(%rbp)	# compare pow to 0
	jne	.L2		# jump to L2 if the pow != 0
	movl	$1, %eax	# else, return 1
	jmp	.L3		# goto .L3
.L2:
	movl	-4(%rbp), %eax	# store pow in %eax
	leal	-1(%rax), %edx	# subtract 1 from pow and store it in %edx
	movl	-8(%rbp), %eax	# store base in %eax
	movl	%eax, %esi	# set base as argument 1
	movl	%edx, %edi	# set pow - 1 as argument 2
	call	powF		# call powF with defined arguments
	imull	-8(%rbp), %eax	# multiply value returned by powF by base
.L3:
	leave			# return from funtion
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	powF, .-powF
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
