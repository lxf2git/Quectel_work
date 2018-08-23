#include"main.h"

int main()
{
		int mun;
		int data;
		int mod;
		sStack stack;
		init_stack(&stack);
		printf("请输入一个整数\n");
		scanf("%d",&mun);
		while(mun!=0)
		{
				mod = mun%16;
				mun=mun/16;
				push(&stack,mod);
		}

		while(pop(&stack,&data)!=EMPTY)
		{
				if(data<10)
				{
						printf("%4d",data);
				}
				else
				{
						printf("%4c",data+55);
				}
		}
		printf("\n");
		return 0;
}
