#include"stack.h"
void compare(pStack p_data,pStack p_oper,int i,int *ctmp)
{
		if(p_oper->top == 0)
		{
				push(p_oper,i);
				*ctmp = i; 
		}
		else
		{
				printf("ctmp:%d\n",*ctmp);
				if(i==5)
				{
						record = *ctmp;
						printf("record1: %d\n",record);
						*ctmp = 0;
						return ;
				}
				if(*ctmp==6)
				{
						*ctmp = record;
						printf("record2:%d\n",*ctmp);
				}
				if(*ctmp>=i)
				{

						deal(p_data,p_oper);
						if(p_oper->top!=0)
						{
							*ctmp  = p_oper->bottom[(p_oper->top)-1];
							printf("::::::%d\n",*ctmp);
						}
						else
						{
								printf("*********\n");
								*ctmp = 0;
						}
				}
				if(*ctmp<i)
				{
						push(p_oper,i);
						*ctmp = i;
				}
		}
}
void init(pStack p_data,pStack p_oper,char *p)
{
		int len,i=0;
		int count = 0;
		int ctmp = 0;
		len = strlen(p);
		for(i=0;i<len;i++)
		{
				if(p[i]>='0'&&p[i]<='9')
				{
						count = count*10 + p[i]-48; 
				}
				else
				{
						if(count!=0)
						{
								push(p_data,count);
						}
						count = 0;
						switch(p[i])
						{
								case '+':compare(p_data,p_oper,1,&ctmp);break;
								case '-':compare(p_data,p_oper,2,&ctmp);break;
								case '*':compare(p_data,p_oper,3,&ctmp);break;
								case '/':compare(p_data,p_oper,4,&ctmp);break;
								case '(':compare(p_data,p_oper,5,&ctmp);break;
								case ')':compare(p_data,p_oper,6,&ctmp);break;
								default:printf("结果:");break;
						}

				}
		}
		
}
