#include"sixteen.h"

void sixteen_jinzhi(pStack ps,int data,int mod,int *pop_data)
{
	char A,B,C,D,E,F;
	while(data != 0)
	{
		mod = data%16;
		push(mod,ps);
		data = data/16;	
	}
	while(pop(ps,pop_data) != EMPTY)
	{
		printf("%d\n",*pop_data);
	}
}
