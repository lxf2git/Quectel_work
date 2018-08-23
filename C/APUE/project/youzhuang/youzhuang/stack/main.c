#include"stack.h"
int ten_to_two(pSta sta,int num);
int ten_to_sixteen(pSta sta,int num);
int ten_to_eight(pSta sta,int num);
int main()
{
		sSta sta;
		int num;
		init_stack(&sta);
		printf("please input number:\n");
		scanf("%d",&num);
		ten_to_two(&sta,num);
		printf("please input number:\n");
		scanf("%d",&num);
		ten_to_sixteen(&sta,num);
		printf("please input number:\n");
		scanf("%d",&num);
		ten_to_eight(&sta,num);
		return 0;
}

int ten_to_two(pSta sta,int num)
{
		int data;
		while(num!=0)
		{
				data=num%2;
				if(FULL==push(sta,data))
				{
						printf("stack full!\n");
						return -1;
				}
				num/=2;
		}
		while(EMPTY!=pop(sta,&data))
		{
				printf("%d ",data);
		}
		printf("\n");
		return 0;
}
int ten_to_sixteen(pSta sta,int num)
{
		int data;
		while(num!=0)
		{
				data=num%16;
				if(FULL==push(sta,data))
				{
						printf("stack full!\n");
						return -1;
				}
				num/=16;
		}
		while(EMPTY!=pop(sta,&data))
		{
				if(data>9)
				{
						printf("%c ",'A'+data-10);
				}
				else
				{	
						printf("%d ",data);
				}
		}
		printf("\n");
		return 0;
}
int ten_to_eight(pSta sta,int num)
{
		int data;
		while(num!=0)
		{
				data=num%8;
				if(FULL==push(sta,data))
				{
						printf("stack full!\n");
						return -1;
				}
				num/=8;
		}
		while(EMPTY!=pop(sta,&data))
		{
				printf("%d ",data);
		}
		printf("\n");
		return 0;
}
