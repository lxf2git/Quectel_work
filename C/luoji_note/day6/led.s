	.section .text
	.global _start

_start:
	stmfd sp!, {lr}
	adr r0, GPM4CON
	ldr r1, [r0]
	ldr r2, =0x1111
   	str r2, [r1]	

	while:
	adr r0, GPM4DAT
	ldr r1, [r0]
	ldr r2, =0x0
	str r2, [r1]

	bl delay

	adr r0, GPM4DAT
	ldr r1, [r0]
	ldr r2, =0xf
	str r2, [r1]
	bl delay

	b while

	ldmfd sp!, {pc}

delay:
	stmfd sp!, {r4, lr}
	ldr r4, =1000*1000
	loop:
	nop
	subs r4, r4, #1
	bne loop
	ldmfd sp!, {r4, pc}

GPM4CON:
		.word 0x11000000+0x02e0

GPM4DAT:
		.word 0x110002e4

		.end
