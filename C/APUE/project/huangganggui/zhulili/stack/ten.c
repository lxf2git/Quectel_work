#include"ten.h"

void ten_jinzhi(pStack ps,int data,int mod,int *pop_data)
{
	while(data != 0)
	{
		mod = data%8;
		push(mod,ps);
		data = data/8;	
	}
	while(pop(ps,pop_data) != EMPTY)
	{
		printf("%d ",*pop_data);
	}
	printf("\n");
}
