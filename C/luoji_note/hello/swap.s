	.section .text
	.global _start 

_start:
	stmfd sp!, {r4, r5, lr}

	adr r4, printf
	ldr r5, [r4]
	adr r0, before

	adr r1, num1
	adr r2, num2
	ldr r1, [r1]
	ldr r2, [r2]
	blx r5

	@swp
	adr r1, num1
	adr r2, num2
	bl swap

	adr r4, printf
	ldr r5, [r4]
	adr r0, after
	adr r1, num1
	adr r2, num2
	ldr r1, [r1]
	ldr r2, [r2]
	blx r5

	ldmfd sp!, {r4, r5, pc}

printf:
	.word 0x43e11a2c 
before:
	.asciz "before num1, num2 %d, %d \n"
	.align 2
after:
	.asciz "after num1, num2 %d, %d  \n"
	.align 2
@ swap
	swap:
		ldr r3, [r1]
		ldr r6, [r2]
		str r3, [r2]
		str r6, [r1]
		mov pc, lr
num1:
	.word 123
	.align 2 
num2:
	.word 321
	.align 2
