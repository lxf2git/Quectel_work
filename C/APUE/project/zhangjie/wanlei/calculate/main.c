#include"main.h"
#include"stack.h"
#include"fun.h"

void resolu(pNum pn,pChar pc,char *str);

int main()
{
	sNum sn;
	sChar sc;
	char str[N];
	printf("please input:\n");
	scanf("%s",str);
	init_num(&sn);
	init_ch(&sc);
	resolu(&sn,&sc,str);
	return 0;
}

void resolu(pNum pn,pChar pc,char *str)
{
	int i;
	int n=0,num=0;
	char ch;
	int pop_num1,pop_num2;
	char pop_ch;
	for(i=0;;i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='('||str[i]==')'||str[i]=='\0')
		{
			num=n;
			n=0;
			if(str[i]=='\0')
			{
				push_num(pn,num);
				break;
			}
			else if(str[i]=='(')
			{
				push_char(pc,str[i]);
				continue;
			}
			ch=str[i];
			if(i==1)
			{
				push_num(pn,num);
				push_char(pc,ch);
			}
			else
			{
				push_num(pn,num);
				pop_char(pc,&pop_ch);
				int jud=judge(pop_ch,ch);
				if(jud==EQUAL||jud==MORE)
				{
					pop_num(pn,&pop_num1);
					pop_num(pn,&pop_num2);
					printf("%d%c%d=%d",pop_num2,pop_ch,pop_num1,
									func(pop_ch,pop_num2,pop_num1));
					push_num(pn,func(pop_ch,pop_num2,pop_num1));
					push_char(pc,ch);
				}
				else if(jud==LESS)
				{
					push_char(pc,pop_ch);
					push_char(pc,ch);
				}
				else if(jud==LIFT)
				{
					push_char(pc,pop_ch);
					push_char(pc,ch);
				}
				else if(jud==RIGHT)
				{
					while(pop_ch!='(')
					{
						pop_num(pn,&pop_num1);
						pop_num(pn,&pop_num2);
						push_num(pn,func(pop_ch,pop_num2,pop_num1)); 
						pop_char(pc,&pop_ch);
					}
					i++;
					if(str[i]=='\0')
					{
						break;
					}
					else
					{
						push_char(pc,str[i]);
					}
				}
			}
		}
		else
		{
			n=n*10+str[i]-48;
		}
	}
#if 0
	while(pop_num(pn,&pop_num1)!=EMPTY)
	{
		printf(" %d ",pop_num1);
	}
	while(pop_char(pc,&pop_ch)!=EMPTY)
	{
		printf(" %c ",pop_ch);
	}
#endif
#if 1
	do
	{
		pop_num(pn,&pop_num1);
		pop_num(pn,&pop_num2);
		pop_char(pc,&pop_ch);
		push_num(pn,func(pop_ch,pop_num2,pop_num1)); 
	
	}while(pc->top!=0&&pn->top!=0);
	pop_num(pn,&pop_num1);
	printf("%d\n",pop_num1);
#endif
}
