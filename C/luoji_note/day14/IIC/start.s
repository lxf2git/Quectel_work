	.section .text
	.global _start
	.global  start
	.global end

_start:
	b ret
	b wang
	b li
	b zhang
	b zhao
	b haha
	b irq
ret:
	STMFD sp!,{lr}
	BL main
	LDMFD sp!,{pc}
wang:
li:
zhang:
zhao:
haha:
irq:
	mov  sp,#0x54000000
		sub lr,lr,#4
	stmfd sp!,{r0-r12,lr}
		 mov lr,pc
		ldr pc,_do_irq
	ldmfd sp!,{r0-r12,pc}^

_do_irq:
	 .word  do_irq
_end:
start:
	.word _start
end:
	.word  _end

