	.section .text
	.global _start

_start:
	STMFD sp!,{lr}
	BL main
	LDMFD sp!,{pc}
