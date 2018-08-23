	.section .text
	.global _start 

_start:
	stmfd sp!, {r4, r5, lr}
	adr r4, printf
	ldr r5, [r4]
	adr r0, hello
	blx r5
	ldmfd sp!, {r4, r5, pc}
printf:
	.word 0x43e11a2c 
hello:
	.asciz "hello, world!\n"
	.align 2
	
