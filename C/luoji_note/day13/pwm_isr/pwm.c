#include<pwm_isr.h>
#include<stdio.h>
void set_duty(int tcnt, int tcmp);

void irq_pwm(int tcnt, int tcmp)
{

	ICDISER2 |=(0x1<<(69-64));
	ICDIPR17 &=~(0xff<<8);
	ICDIPTR17 |=(0x1<<8); 



//	GPD0CON |=2;  //TOUT_0 
	
	TCFG0  |=255;
	TCFG1  |=2;

	set_duty(tcnt, tcmp);         //注意先设置 set TCNTB0 TCMPB0 在设置TCON;注意顺序； 
	TCON  |=1|(1<<1)|(1<<3);    	
	TCON  &=~(0x1<<1);

	//
	TINT_CSTAT |=(1<<0);
}

void set_duty(int tcnt, int tcmp)
{

	TCNTB0 = tcnt;
	TCMPB0 =tcmp;
}
