#include"main.h"
void operation(char ch,pNum num);
int judge_priority(char ch1,char ch2);
int judge_ch(char ch);
int main()
{
		char data[SIZE];
		sNum num;
		sSig sig;
		init_stack(&num,&sig);
		printf("please input:\n");
		scanf("%s",data);
		calc(&num,&sig,data);
		while(num.top!=0)
		{
				int i;
				pop_num(&num,&i);
				printf("num:%d ",i);
		}
		printf("\n");
		while(sig.top!=0)
		{
				char j;
				pop_sig(&sig,&j);
				printf("sig:%c ",j);
		}
		printf("\n");
		return 0;
}

void operation(char ch,pNum num)
{
		int a,b,value;
		pop_num(num,&b);
		pop_num(num,&a);
		switch(ch)
		{
				case '+':
						value=add(a,b);
						break;
				case '-':
						value=sub(a,b);
						break;
				case '*':
						value=mul(a,b);
						break;
				case '/':
						value=div_(a,b);
						break;
		}
		printf("%d %c %d \n",a,ch,b);
		printf("value:%d \n",value);
		push_num(num,value);
}

int judge_ch(char ch)
{
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
		{
				return 0;
		}
		else
		{
				return -1;
		}
}

int judge_priority(char ch1,char ch2)
{
		if(ch1=='(')
		{
				return 0;
		}
		if(ch1==')')
		{
				return -2;
		}
		if(ch1=='\0')
		{
				return -1;
		}
		if((ch1=='*'||ch1=='/')&&(ch2=='-'||ch2=='+'))
		{
				return 0;
		}
		if((ch1=='*'||ch1=='/')&&(ch2=='*'||ch2=='/'))
		{
				return 1;
		}
		if((ch1=='+'||ch1=='-')&&(ch2=='-'||ch2=='+'))
		{
				return 1;
		}
		if((ch1=='+'||ch1=='-')&&(ch2=='*'||ch2=='/'))
		{
				return -1;
		}
}

int calc(pNum num, pSig sig, char data[SIZE])
{
		char ch;
		int result,temp=0;
		int i=0,j=0;
		while(1)
		{
				printf("a[i]:%c\n",data[i]);
				if(data[i]>='0'&&data[i]<='9')
				{
						temp=temp*10+(int)data[i]-48;
						j++;
				}
				else
				{
						if(data[i]!='('&&data[i-1]!=')')
						{
								push_num(num,temp);
								temp=0;
								j=0;
						}
						switch(judge_priority(data[i],sig->bottom[sig->top-1]))
						{
								case 0:
										push_sig(sig, data[i]);
										break;
								case 1:
										pop_sig(sig,&ch);
										operation(ch,num);
										push_sig(sig,data[i]);
										break;
								case -1:
										while(num->top!=1&&sig->bottom[sig->top-1]!='(')
										{
												pop_sig(sig,&ch);
										printf("num->bottom:%d ",num->bottom[num->top-1]);
												operation(ch,num);
										}
										push_sig(sig,data[i]);
										break;
								case -2:
										pop_sig(sig,&ch);
										printf("ch:%c\n",ch);
										while(ch!='(')
										{
												operation(ch,num);
												printf("num:%d\n",num->bottom[num->top-1]);
												pop_sig(sig,&ch);
										printf("ch:%c\n",ch);
										}
										break;
								default:
										push_sig(sig, data[i]);
										break;
						}
				}
				if(data[i]=='\0')
				{
						break;
				}
				printf("top:%d num->bottom:%d \n",num->top,num->bottom[num->top-1]);
				i++;
		}
		return result;
}
