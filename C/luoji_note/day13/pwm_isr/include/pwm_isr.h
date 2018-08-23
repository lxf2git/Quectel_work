
#ifndef PWM_H
#define  PWM_H

#define  GPD0CON  (*((volatile unsigned long*)(0x11400000+ 0x00A0)))
#define  EXT_INT6CON (*((volatile unsigned long*)(0x11400000+0x0714)))

#define  PWM_BASE	(0x139D0000)
#define  TCFG0   (*((volatile unsigned long*)(PWM_BASE)))
#define  TCFG1	 (*((volatile unsigned long*)(PWM_BASE + 0x0004)))


#define  TCNTB0   (*((volatile unsigned long*)(PWM_BASE + 0x000C)))
#define  TCMPB0   (*((volatile unsigned long*)(PWM_BASE + 0x0010)))
#define  TCON     (*((volatile unsigned long*)(PWM_BASE + 0x0008)))
#define  TINT_CSTAT (*((volatile unsigned long*)(PWM_BASE +0x0044)))

#define   ICCICR_CPU0  (*((volatile unsigned long*)0x10480000))
#define   ICCPMR_CPU0  (*((volatile unsigned long*)0x10480004))
#define   ICCIAR_CPU0   (*((volatile unsigned long*)0x1048000c))
#define   ICCEOIR_CPU0 (*((volatile unsigned long*)0x10480010))

#define  IRQ_BASE    (0x10490000)
#define   ICDDCR    (*((volatile unsigned long*)IRQ_BASE))

#define  ICDISER2  (*((volatile unsigned long*)(IRQ_BASE+0x0108)))
#define  ICDIPR17  (*((volatile unsigned long*)(IRQ_BASE+0x0444)))
#define  ICDIPTR17 (*((volatile unsigned long*)(IRQ_BASE+0x0844)))


#endif 
