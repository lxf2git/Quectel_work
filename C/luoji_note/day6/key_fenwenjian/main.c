#include<stdio.h>
#include<key_test.h>
#include<led_driver.h>

static void delay(unsigned int ms);
static void init_key_led();

int main() 
{
	//led key 初始化
	init_key_led();
	while(1)
	{
		if (key_test(GPX3DAT,K1) == 0) //检测K1按键
		{
			printf("k1 is down\n");
			led_driver(EN, LED1);  //点亮led1
			delay(2);
		}
		else
		{
			led_driver(DEN,LED1); //熄灭led1
		}
		
		if (key_test(GPX3DAT,K2) == 0)
		{
			printf("k2 is down\n");
			led_driver(EN, LED2);
			delay(2);
		}
		else
		{
			led_driver(DEN,LED2);
		}

		if (key_test(GPX3DAT,K3) == 0)
		{
			printf("k3 is down\n");
			led_driver(EN, LED3);
			delay(2);
		}
		else
		{
			led_driver(DEN,LED3);
		}
			
		if (key_test(GPX3DAT,K4) == 0)
		{
			printf("k4 is down\n");
			led_driver(EN, LED4);
			delay(2);
		}
		else
		{
			led_driver(DEN,LED4);
		}
	}

}

void init_key_led()
{
		//按键引脚输出 
		GPX3CON &=~(0xffff<<8); 
		//小灯引脚输出 
		GPM4CON =0x1111; 
}

//延时
void delay(unsigned int ms)
{
	int i, j;
	for (i=0; i<1000*ms; i++)
	{
		for (j=0; j<1000; j++)
		{
			;
		}
	}
}

