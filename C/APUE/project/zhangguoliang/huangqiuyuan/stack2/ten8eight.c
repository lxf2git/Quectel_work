#include"stack.h"
int main()
{
	sStack sta;
	int mod,a;
	int pop_data;
	init_stack(&sta);
	int data;
	printf("please input style 2 8 16?\n");
	scanf("%d",&a);
	if(a==2)
	{
		printf("please input number:\n");
		scanf("%d",&data);
		while(data!=0)
		{
			mod=data%2;
			push(&sta,mod);
			data=data/2;
		}
		while((pop(&sta,&pop_data))!=EMPTY)
		{
			printf("%d ",pop_data);
		}
                	printf("\n");
	}
	if(a==8)
	{
		printf("please input number:\n");
		scanf("%d",&data);
		while(data!=0)
		{
			mod=data%8;
			push(&sta,mod);
			data=data/8;
		}
		while((pop(&sta,&pop_data))!=EMPTY)
		{
			printf("%d ",pop_data);
		}
                	printf("\n");
	}
	if(a==16)
	{
		printf("please input number:\n");
		scanf("%d",&data);
		while(data!=0)
		{
			mod=data%16;
			push(&sta,mod);
			data=data/16;
		}
		while((pop(&sta,&pop_data))!=EMPTY)
		{	
			switch(pop_data)
			{
			case(10):
				printf("A ");
				break;
			case(11):
				printf("B ");
				break;
			case(12):
				printf("C ");
				break;
			case(13):
				printf("D ");
				break;
			case(14):
				printf("E ");
				break;
			case(15):
				printf("F ");
				break;
			default:
				printf("%d ",pop_data);
			}
		}
                	printf("\n");
	}
	


}
