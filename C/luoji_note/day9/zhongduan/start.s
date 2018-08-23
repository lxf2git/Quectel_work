.section .text 
.global  _start
.global  start
.global  end

_start:
	stmfd sp!, {lr}
	bl main
	ldmfd sp!, {pc}

irq:
	mov sp, #0x54000000
	sub lr, lr, #4
	stmfd sp!, {r0-r12,lr}
	mov lr, pc
	ldr pc, _deal_irq
	ldmfd sp!, {r0-r12,pc}^

_deal_irq:
		.word deal_irq
_end:

start:
	.word irq 
end:
	.word _end
