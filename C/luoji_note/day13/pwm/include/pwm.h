
#ifndef PWM_H
#define  PWM_H

#define  GPD0CON  (*((volatile unsigned long*)(0x11400000+ 0x00A0)))
#define  PWM_BASE	(0x139D0000)
#define  TCFG0   (*((volatile unsigned long*)(PWM_BASE)))
#define  TCFG1	 (*((volatile unsigned long*)(PWM_BASE + 0x0004)))

#define  TCNTB0  (*((volatile unsigned long*)(PWM_BASE +  0x000C)))
#define  TCMPB0  (*((volatile unsigned long*)(PWM_BASE + 0x0010)))
#define  TCON     (*((volatile unsigned long*)(PWM_BASE + 0x0008)))



#endif 
