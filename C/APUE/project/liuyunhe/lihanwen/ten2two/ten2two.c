#include"stack.h"	

int main()
{
	printf("please input /%/d num\n");
	int data;
	scanf("%d",&data);
	
	sStack sta;
	int mod;
	int pop_data;
	init_memory(&sta);
	while(data!=0)
	{
		mod = data%2;
		push(&sta,mod);
		data = data/2;
	}
	
	while((pop(&sta,&pop_data))!=EMPTY)
	{
		printf("%d",pop_data);
	}
	printf("\n");
	return 0;

}
