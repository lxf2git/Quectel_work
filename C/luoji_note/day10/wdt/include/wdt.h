#ifndef WDT_H
#define  WDT_H
	
#define   WTBASE   		       (0x10060000)
#define   WTCON              (*((unsigned long*)(WTBASE+0x0000)))
#define   WTDAT         	 (*((unsigned long*)(WTBASE+0x0004)))
#define   WTCNT              (*((unsigned long*)(WTBASE+0x0008)))
#define   WTCLRINT       	 (*((unsigned long*)(WTBASE+0x000C)))

#endif 
