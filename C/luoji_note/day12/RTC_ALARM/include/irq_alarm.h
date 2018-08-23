#ifndef IRQ_ALARM_H
#define  IRQ_ALARM_H


#define  IRQ_BASE  (0x10490000)
#define  ICCICR_CPU0    (*((volatile unsigned long* )(0x10480000)))
#define  ICCPMR_CPU0 	(*((volatile unsigned long* )(0x10480004)))
#define  ICDDCR		    (*((volatile unsigned long* )( 0x10490000)))
#define  ICCIAR_CPU0    (*((volatile unsigned long* )( 0x1048000c))) 	 
#define  ICCEOIR_CPU0   (*((volatile unsigned long* )( 0x10480010))) 	 






#define  ICDISER2       (*((volatile unsigned long* )(IRQ_BASE + 0x0108)))
#define  ICDIPR19       (*((volatile unsigned long* )(IRQ_BASE + 0x044c)))
#define  ICDIPTR19      (*((volatile unsigned long* )(IRQ_BASE + 0x084c)))




#define  RTC_BASE  	(0x10070000)   
#define  INTP       (*((volatile unsigned long* )(RTC_BASE + 0x0030))) 
#define  RTCALM      (*((volatile unsigned long* )(RTC_BASE + 0x0050)))


//
#define  ALMHOUR    (*((volatile unsigned long* )(RTC_BASE + 0x005c)))
#define  ALMMIN     (*((volatile unsigned long* )(RTC_BASE + 0x0058)))
#define  ALMSEC     (*((volatile unsigned long* )(RTC_BASE + 0x0054)))

#endif 
