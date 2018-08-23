#ifndef RTC_H
#define RTC_H


#define  BASE_ADDR    	(0x10070000)
#define  BCDYEAR        (*((volatile unsigned long*)(BASE_ADDR + 0x0088)))
#define  BCDMON         (*((volatile unsigned long*)(BASE_ADDR + 0x0084)))
#define  BCDDAY         (*((volatile unsigned long*)(BASE_ADDR + 0x007c)))
#define  BCDDAYWEEK     (*((volatile unsigned long*)(BASE_ADDR + 0x0080)))
#define  BCDHOUR 		(*((volatile unsigned long*)(BASE_ADDR + 0x0078)))
#define  BCDMIN         (*((volatile unsigned long*)(BASE_ADDR + 0x0074)))
#define  BCDSEC         (*((volatile unsigned long*)(BASE_ADDR + 0x0070)))


#define  RTCCON        (*((volatile unsigned long*)(BASE_ADDR + 0x0040)))





#endif 
