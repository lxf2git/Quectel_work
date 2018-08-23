#include"calculate.h"
int deal(pStack1 psd,pStack2 psc)
{
	poperate[0]=save_num;
	poperate[1]=load_num;
	poperate[2]=deal_sign;
	int pop_data;//test
	char pop_sign;
	int i;
	int oper;
	int move;
	char inc[SIZE]={};
	scanf("%s",inc);
	push_ch(psc,'=');
	for(i=0;i<SIZE-2;i++)
	{
		oper = judge(inc[i],inc[i+1]);
//		printf("oper:%d\n",oper);
		move = poperate[oper](psd,psc,inc[i]);
//		printf("move %d\n",move);
//			pop_int(psd,&pop_data);//test
//			printf("%d\n",pop_data);//test
//			pop_ch(psc,&pop_sign);//test
//			printf("%d\n",pop_sign);//test
		if(move == 1)
		{
			pop_int(psd,&pop_data);//test
//			printf("%d\n",pop_data);//test
			return pop_data;
		}
	}
}

int judge(char c1,char c2)
{
	if(c1>='0' && c2<='9')
	{
		if(c2>='0' && c2<='9')
		{
			return SAVE_NUM;
		}
		if(c2=='+'||c2=='-'||c2=='='||
			c2=='*'||c2=='/'||c2==10||c2==0)
		{
			return LOAD_NUM;
		}
	}
	else if(c1=='+'||c1=='-'||c2=='='||
			c1=='*'||c1=='/'||c1==10||c2==0)
	{
		
			return DEAL_SIGN;
		
	}
	
}
