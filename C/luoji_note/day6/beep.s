	.section .text
	.global _start

_start:
	stmfd sp!, {lr}
	adr r0, GPD0CON
	ldr r1, [r0]
	ldr r2, =0x1111
	str r2, [r1]

	adr r0, GPD0DAT
	ldr r1, [r0]
	ldr r2, =0xf
	str r2, [r1]
	ldmfd sp!, {pc}

GPD0CON:
		.word 0x11400000+0x00A0

GPD0DAT:
		.word 0x11400000+0x00A4


