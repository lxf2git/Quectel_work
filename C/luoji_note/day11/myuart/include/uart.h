
#ifndef _UART_H
#define  _UART_H

#define   GPIO_BASE     (0x11400000)
#define   UART_BASE     (0x13800000)
#define  GPA0CON       	 (*((unsigned long*)GPIO_BASE))
#define  ULCON0          (*((unsigned long*)UART_BASE))
#define  UCON0           (*((unsigned long*)(UART_BASE+0x0004)))
#define  UFCON0          (*((unsigned long*)(UART_BASE+0x0008)))
#define  UMCON0          (*((unsigned long*)(UART_BASE+0x000c)))

#define  UTXH0           (*((unsigned long*)(UART_BASE+0x0020)))    

#define  UBRDIV0    	(*((unsigned long*)(UART_BASE+0x0028)))    
#define  UFRACVAL0		(*((unsigned long*)(UART_BASE+0x002c)))
#define  UTRSTAT0       (*((unsigned long*)(UART_BASE+0x0010)))




#endif 
