#include <stdio.h>
#include<pwm.h>
#define  N (sizeof(arrc)/sizeof(arrc[0]))
void delay(int ms);
void pwm_init(int tcnt, int tcmp);
int main()
{
		
		int i;
		int arrt[] = {100, 200, 300, 400, 500};
		int arrc[] ={ 50, 40, 30,20, 10};
		
		
		
		pwm_init(arrt[0], arrc[0]);
		delay(10);
		
		for (i=0; i<N; i++)
		{
			TCNTB0 = arrt[i];
			TCMPB0 = arrc[i];
			delay(10);
			if (i ==N-1)
			{
				i = 0;
			}
		}
		
	
	 	 return 0;

}

void pwm_init(int tcnt, int tcmp)
{
	GPD0CON |=2;  //TOUT_0 
	
	TCFG0  |=99;
	TCFG1  |=2;

	TCNTB0 = tcnt;
	TCMPB0 =tcmp;
	
	TCON  |=1|(1<<1)|(1<<3);	
	TCON  &=~(0x1<<1);

}

void delay(int ms)
{
	int i, j;
	for(i=0; i<ms*100; i++)
	{
		for (j=0; j<1000; j++)
		{
			;
		}
	}
}
