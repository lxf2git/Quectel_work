#include"calculate.h"

int save_num(pStack1 psd,pStack2 psc,char data)
{
	int ret;
	push_ch(psc,data);
	return SUC;
}


int load_num(pStack1 psd,pStack2 psc,char data)
{
	int ret;
	int num;
	char pop_sign = '0';
	int i = 1;
	num = data - 48;
	do
	{
		num = (pop_sign-48)*i+num;
		i=i*10;
		ret = pop_ch(psc,&pop_sign);
	}while(pop_sign>='0' &&pop_sign<='9' );

//	printf("sign:%c\n",pop_sign);
//	printf("num:%d\n",num);
	push_ch(psc,pop_sign);

	push_int(psd,num);
	return SUC;
}

int deal_sign(pStack1 psd,pStack2 psc,char data)
{
//	printf("deal_s in\n");
	char pop_sign;
	int ret;
	ret = pop_ch(psc,&pop_sign);
//	printf("ret = %d\n",ret);
	if(pop_sign == '=')
	{
//		printf("deal1 \n");
		push_ch(psc,'=');
		push_ch(psc,data);
		return SUC;
	}
	else if(data=='+'||data=='-')
	{
		if(pop_sign == '+'||pop_sign == '-')
		{
			cal_num(psd,pop_sign);
			push_ch(psc,data);
			return SUC;
		}
		else if(pop_sign == '*'||pop_sign == '/')
		{
			cal_num(psd,pop_sign);
			deal_sign(psd,psc,data);
			return SUC;
		}
	}
	else if(data=='*'||data=='/')
	{
		if(pop_sign == '+'||pop_sign == '-')
		{
			push_ch(psc,pop_sign);
			push_ch(psc,data);
		}
		else if(pop_sign == '*'||pop_sign == '/')
		{
			cal_num(psd,pop_sign);
			push_ch(psc,data);
		}
	}
	else if(data == 10||data == '='||data == 0)
	{
		cal_num(psd,pop_sign);
		deal_sign(psd,psc,data);
		return OVER;
	}
	else
	{
		return ERR;
	}
}
int cal_num(pStack1 psd,char pop_sign)
{
	int a,b,sum;
	pop_int(psd,&b);
	pop_int(psd,&a);
	switch(pop_sign)
	{
		case '+':sum = a+b;break;
		case '-':sum = a-b;break;
		case '*':sum = a*b;break;
		case '/':
		{
			if(b==0)
			{
				printf("div error\n");
				exit(-1);
			}
			sum = a/b;break;
		}	 
		default:printf("error\n");exit(-1); 
	}
//	printf("sum:%d\n",sum);
	push_int(psd,sum);
	return SUC;
}
