#ifndef _DELAY_H
#define  _DELAY_H
static void delay(const int ms)
{
	int i, j;
	for (i=0; i<1000*ms; i++)
	{
		for(j=0; j<1000; j++);
	}
}
#endif 
