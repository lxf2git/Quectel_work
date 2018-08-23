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
				mod = mun%8;
				mun=mun/8;
				push(&stack,mod);
		}

		while(pop(&stack,&data)!=EMPTY)
		{
				printf("%4d",data);
		}
		printf("\n");
		return 0;
}
