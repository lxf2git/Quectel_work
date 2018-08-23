
#ifndef  EINT_H
#define  EINT_H

#define  ICCICR_CPU0         (*((volatile unsigned long*)0x10480000))
#define  ICCPMR_CPU0  	     (*((volatile unsigned long*)(0x10480000+0x0004)))
#define  ICDDCR		  	     (*((volatile unsigned long*)( 0x10490000)))
#define  ICDISER2 		   	(*((volatile unsigned long*)(0x10490000+0x0108)))

#define  ICDIPR16			 (*((volatile unsigned long*)(0x10490000+0x0440)))
#define  ICDIPTR16           (*((volatile unsigned long*)(0x10490000+0x0840)))

#define  ICDIPR18	 	     (*((volatile unsigned long*)(0x10490000+0x0448)))
#define  ICDIPTR18 	   		 (*((volatile unsigned long*)(0x10490000+0x0848)))
#define  ICCIAR_CPU0         (*((volatile unsigned long*)(0x10480000+0x000C)))   
#define  ICCEOIR_CPU0         (*((volatile unsigned long*)(0x10480000+0x0010)))   
#define  EXT_INT43_PEND        (*((volatile unsigned long*)(0x11000000 + 0x0F4C)))

#endif 
