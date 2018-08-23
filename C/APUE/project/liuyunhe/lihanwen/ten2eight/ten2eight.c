#include"stack.h"

int main()
{
	printf("please input 10 jin zhi shu\n");
	int data;
	scanf("%d",&data);

	sStack sta;
	int mod;
	int pop_data;
	init_memory(&sta);
	
	while(data!=0)
	{
		mod = data%8;
		push(&sta,mod);
		data = data/8;
	}

	while((pop(&sta,&pop_data))!=EMPTY)
	{
		printf("%d",pop_data);
	}
	printf("\n");
	return 0;
}
