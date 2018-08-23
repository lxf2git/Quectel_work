
#ifndef _COMMON_H
#define  _COMMON_H

#define  printf(...)   (((int(*)(const char *format, ...))0x43e11a2c)(__VA_ARGS__))
#define  BITS(n, m)       		(~((~0)<<(m-n+1)))
#define  SET_BIT(x, n, m)   (x |=(BITS(n, m)<<n))
#define  CLEAR_BIT(x,n,m)	(x &=~(BITS(n, m)<<n))
#define  GET_BIT(x, n,m)    ((x&(BITS(n, m)<<n))>>n)

struct adc_st
{
	enum 
	{	
		END,
		PROCESS,
	}end_state;
	
};
#endif 
