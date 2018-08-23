#ifndef _UART_H
#define _UART_H

#define GPA0CON   (*(volatile unsigned long*)0x11400000)
#define ULCON0    (*(volatile unsigned long*)0x13800000)
#define UCON0    (*(volatile unsigned long*)0x13800004)
#define UFCON0    (*(volatile unsigned long*)0x13800008)
#define UMCON0    (*(volatile unsigned long*)0x1380000c)

#define  UBRDIV0   (*(volatile unsigned long*)0x13800028)
#define UFRACVAL0  (*(volatile unsigned long*)0x1380002c)
#define UTXH0      (*(volatile unsigned long*)0x13800020)
#define  UTRSTAT0  (*(volatile unsigned long*)0x13800010)

void uart_init(void);
void uart_send(char);


#endif
