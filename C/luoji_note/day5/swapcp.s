	.section .text
	.global _start 

_start:
	stmfd sp!, {lr}
	adr r0, before
	adr r1, num1
	adr r2, num2
	ldr r1, [r1]
	ldr r2, [r2]
	mov lr, pc
	ldr pc, printf
	@swp
	adr r1, num1
	adr r2, num2
	bl swap

	adr r0, after
	adr r1, num1
	adr r2, num2 
	ldr r1, [r1]
	ldr r2, [r2]
	mov lr, pc
	ldr pc, printf
	ldmfd sp!, {pc}

printf:
	.word 0x43e11a2c 
before:
	.asciz "before num1, num2 %d, %d \n"
	.align 2
after:
	.asciz "after num1, num2 %d, %d  \n"
	.align 2
@swap
	swap:
		stmfd sp!, {r4,r5,lr}
		ldr r4, [r1]
		ldr r5, [r2]
		str r4, [r2]
		str r5, [r1]
		ldmfd sp!, {r4,r5, pc}
num1:
	.word 123
	.align 2 
num2:
	.word 321
	.align 2
