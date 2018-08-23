#ifndef KEY_H
#define KEY_H
#define  GPX3CON         (*((volatile unsigned long*)(0x11000000 + 0x0C60)))
#define  EXT_INT43CON    (*((volatile unsigned long*)(0x11000000 + 0x0E0C)))
#define  EXT_INT43_MASK  (*((volatile unsigned long*)(0x11000000 + 0x0F0C)))
#define  EXT_INT43_PEND  (*((volatile unsigned long*)(0x11000000 + 0x0F4C)))
#endif 
