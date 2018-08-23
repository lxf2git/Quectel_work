	.section .text
	.global _start

_start:
	stmfd sp!, {r4,r5,lr}	
	adr r0 , str1
	adr r1 , str2
	bl strcmp


	adr r4, printf
	ldr r5, [r4]
	adreq  r0, equal
	adrne r0, notequal
	blx r5

	ldmfd sp!, {r4, r5, pc} 


@  strcmp 函数
strcmp:
	loop:
	ldrb r6, [r0],#1
	ldrb r7, [r1],#1

	cmp  r6, #0
	beq  after

	cmp r6 ,r7
	beq loop

	after:
	cmp r6 ,r7
	mov pc, lr

str1: 
	.asciz "hello"
	.align 2 
str2: 
	.asciz "hello"
	.align 2 


@ printf 函数

printf:
	.word 0x43e11a2c
equal:
	.asciz "is equal\n"
	.align 2
notequal:
	.asciz "is not equal\n"
	.align 2
