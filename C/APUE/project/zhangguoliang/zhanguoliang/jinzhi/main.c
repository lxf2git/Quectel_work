#include"stack.h"


int main()
{
	sStack sta;
	int pop_data,data;
	int a;
	int mod;
	init_stack(&sta);
	printf("please input\n");
	scanf("%d",&data);
	printf("please input choose\n");
	scanf("%d",&a);
	switch(a)
	{
		case 2:
			while(data!=0)
			{
			mod=data%2;
			push(&sta,mod);
			data=data/2;
			}
			break;
		case 8:
			while(data!=0)
			{
			mod=data%8;
			push(&sta,mod);
			data=data/8;
			}
			break;
		case 16:
			while(data!=0)
			{
			mod=data%16;
			push(&sta,mod);
			data=data/16;
			}
			break;
		default :
			printf("error\n");
			break;

	}
	while((pop(&sta,&pop_data))!=EMPTY)
	{
		if(pop_data<10)
		{
		printf("%d ",pop_data);
		}
		if(pop_data>9&&pop_data<16)
		{
			switch(pop_data)
			{
				case 10:
					printf("A ");
					break;
				case 11:
					printf("B ");
					break;
				case 12:
					printf("C ");
					break;
				case 13:
					printf("D ");
					break;
				case 14:
					printf("E ");
					break;
				case 15:
					printf("F ");
					break;
			}
		}
	}
	printf("\n");
	return 0;
}

