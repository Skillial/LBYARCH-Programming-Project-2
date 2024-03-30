

section .data

section .text
bits 64
default rel

global slidingWindowx64

slidingWindowx64:
	push r12
	push r13
	push r14
	push rbx

	mov r12, 4
	IMUL r8, 4
	mov r13, 0
	xor r14, r14
	outerloop:
		movss xmm0, [rcx+r13]
		mov rbx, 4
		count:
			mov r14, rbx
			add r14, r13
			addss xmm0, [rcx + r14]
			add rbx, r12
			CMP rbx, 28
			JNZ count
		movss [rdx+r13], xmm0
		add r13, r12
		CMP r13, r8
		JNZ outerloop

	pop rbx
	pop r14
	pop r13
	pop r12
	ret