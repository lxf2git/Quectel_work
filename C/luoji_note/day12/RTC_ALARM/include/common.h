

#ifndef COMMON_H
#define COMMON_H
#define  printf(...)       (((int (*)(const char* format, ...))0x43e11a2c) (__VA_ARGS__))

struct time_st
{
		int year;
		int month;
		int day;
		int week;   
		int hour;
		int min;
		int sec;

};
#endif 
