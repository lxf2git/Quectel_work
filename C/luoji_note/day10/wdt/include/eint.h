
#ifndef  EINT_H
#define  EINT_H

#define  ICCICR_CPU0         (*((volatile unsigned long*)0x10480000))
#define  ICCPMR_CPU0  	     (*((volatile unsigned long*)(0x10480000+0x0004)))
#define  ICDDCR		  	     (*((volatile unsigned long*)( 0x10490000)))
#define  ICDISER2 		     (*((volatile unsigned long*)(0x10490000+0x0108)))
#define  ICDIPR18	 	     (*((volatile unsigned long*)(0x10490000+0x0448)))
#define  ICDIPTR18 	   		 (*((volatile unsigned long*)(0x10490000+0x0848)))
#define  ICCIAR_CPU0         (*((volatile unsigned long*)(0x10480000+0x000C)))   
#define  ICCEOIR_CPU0         (*((volatile unsigned long*)(0x10480000+0x0010)))   

#endif 
