#ifndef _EINT_H
#define _EINT_H

#define ICCICR_CPU0  	  (*(volatile unsigned long*)0x10480000) 
#define ICCPMR_CPU0	 	  (*(volatile unsigned long*)0x10480004) 
#define ICDDCR      	  (*(volatile unsigned long*)0x10490000)

#define ICDISER1	 	  (*(volatile unsigned long*)0x10490104)
#define ICDIPR15      	  (*(volatile unsigned long*)0x1049043c)
#define ICDIPTR15 	  	  (*(volatile unsigned long*)0x1049083c)
#define GPD1CON  	  	  (*(volatile unsigned long*)0x114000c0)
#define GPX1CON  	  	  (*(volatile unsigned long*)0x11000c20)
#define EXT_INT41CON      (*(volatile unsigned long*)0x11000e04)
#define EXT_INT41_MASK    (*(volatile unsigned long*)0x11000f04)
#define EXT_INT41_PEND    (*(volatile unsigned long*)0x11000f44)

#define ICCIAR_CPU0 (*(volatile unsigned long*)0x1048000c)
#define ICCEOIR_CPU0 (*(volatile unsigned long*)0x10480010)
#endif


