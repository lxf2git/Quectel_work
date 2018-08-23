#include"stack.h"
void func(int in,int data,pStack sta)
{
	int pop_data=0;
	int mod;
	while(data != 0)
	{
		mod=data%in;
		data=data/in;
		push(sta,mod);
	}
	printf("result[%d进制]:",in);
	while((pop(sta,&pop_data)) != EMPTY)
	{
		if(pop_data>9)
		printf("%c",(pop_data+87));
		else
		printf("%d",pop_data);
	}
	printf("\n");

	
}
