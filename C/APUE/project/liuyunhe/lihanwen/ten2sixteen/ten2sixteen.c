#include"stack.h"

int main()
{
	printf("请输入10进制数\n");
	int data;
	scanf("%d",&data);

	sStack sta;
	int mod;
	int pop_data;
	init_memory(&sta);

	while(data!=0)
	{
		mod = data%16;
		push(&sta,mod);
		data = data/16;
	}

	char p_data;
	while((pop(&sta,&pop_data))!=EMPTY)
	{
		if(pop_data>=10)
		{
			p_data=pop_data+55;
			printf("%c",p_data);
		}
		else
		{		
			printf("%d",pop_data);
		}
	}
	printf("\n");
	return 0;
}
