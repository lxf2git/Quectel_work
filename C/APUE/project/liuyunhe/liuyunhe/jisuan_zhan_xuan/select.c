#include"main.h"

int jisuan(int data1,int data2,char fun)
{
			int data;
			if(fun=='+')
			{
					data=data2+data1;
			}
			if(fun=='-')
			{
					data=data2+data1;
			}
			if(fun=='*')
			{
					data=data2*data1;
			}
			if(fun=='/')
			{
						if(data2==0)
						{
								printf("分母为零\n");
								exit (-1);
						}
						data=data1/data2;
			}
			return data;

}
void char_select(pStack_in ps_in,pStack_ch ps_ch,char oper)
{
		char fun;
		int data,data1,data2;
		if(ps_ch->top==0)
		{
				push_ch(ps_ch,oper);
		}
		else
		{
				if(oper=='+'||oper=='-')
				{
						pop_ch(ps_ch,&fun);
						if(fun!='(')
						{
								pop_in(ps_in,&data2);
								pop_in(ps_in,&data1);
								data=jisuan(data1,data2,fun);
								push_in(ps_in,data);
								push_ch(ps_ch,oper);
						}
						else
						{
								push_ch(ps_ch,fun);
								push_ch(ps_ch,oper);
						}
				}
				if(oper=='*'||oper=='/')
				{
						pop_ch(ps_ch,&fun);
						if(fun=='*'||fun=='/')
						{
								pop_in(ps_in,&data2);
								pop_in(ps_in,&data1);
								data=jisuan(data1,data2,fun);
								push_in(ps_in,data);
								push_ch(ps_ch,oper);
						}
						if(fun=='('||fun=='+'||fun=='-')
						{
								push_ch(ps_ch,fun);
								push_ch(ps_ch,oper);
						}
				}
				
				if(oper=='(')
				{
								push_ch(ps_ch,oper);
				}
				if(oper==')')
				{
						pop_ch(ps_ch,&fun);
						while(fun!='(')
						{
								pop_in(ps_in,&data2);
								pop_in(ps_in,&data1);
								data=jisuan(data1,data2,fun);
								push_in(ps_in,data);
							
								pop_ch(ps_ch,&fun);
						}
				}
		}
}

void print(pStack_in ps_in,pStack_ch ps_ch)
{
		char fun;
		int data,data1,data2;
						while(ps_in->top>1)
						{
								pop_ch(ps_ch,&fun);

								pop_in(ps_in,&data2);
								pop_in(ps_in,&data1);
								data=jisuan(data1,data2,fun);
								push_in(ps_in,data);
							
						}

						pop_in(ps_in,&data);
						printf("=%d\n",data);
}
