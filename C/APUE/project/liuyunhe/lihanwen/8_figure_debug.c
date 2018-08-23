#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

typedef struct stack
{
	int top;
	char *sign;
	int *num;
}sSt,*pSt;

void creat_memory_int(int **p)
{
	*p=(int *)malloc(SIZE*sizeof(int));
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void creat_memory_char(char **p)
{
	*p=(char *)malloc(SIZE*sizeof(char));
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_memory(pSt p_sta)
{
	creat_memory_char(&p_sta->sign);
	creat_memory_int(&p_sta->num);
	p_sta->top=0;
}

void insert_num(pSt p_num,char *str,int i,int j)
{
	for(i=i-1;j>0;j--,i--)
	{
		p_num->num[p_num->top]=(p_num->num[p_num->top]+str[i]-48)*10;
	}
	p_num->num[p_num->top]=p_num->num[p_num->top]/10;
	p_num->top++;
}

void insert_sign(pSt p_sign,char *str,int i)
{
	p_sign->sign[p_sign->top]=str[i];		
	p_sign->top++;
}

void insert_specific(pSt p_num,pSt p_sign)
{
	int n,s;
	n=p_num->top-1;
	s=p_sign->top;
	
	if(p_sign->sign[s]=='*')
	{
		p_num->num[n-1]=p_num->num[n-1]*p_num->num[n];
		p_num->top=n;
	}else if(p_sign->sign[s]=='/')
	{
		p_num->num[n-1]=p_num->num[n-1]/p_num->num[n];
		p_num->top=n;	
	}
	p_sign->top=s;
}

void figure(pSt p_num,pSt p_sign,int n,int s)
{
	if(p_sign->sign[s]=='+')
	{
		p_num->num[n-1]=p_num->num[n-1]+p_num->num[n];
	}
	else if(p_sign->sign[s]=='-')
	{
		p_num->num[n-1]=p_num->num[n-1]-p_num->num[n];
	}	
	else if(p_sign->sign[s]=='*')
	{
		p_num->num[n-1]=p_num->num[n-1]*p_num->num[n];
	}
	else if(p_sign->sign[s]=='/')
	{
		p_num->num[n-1]=p_num->num[n-1]/p_num->num[n];
	}

	p_num->top=n;
	p_sign->top=s;
}

void figure_specific(pSt p_num,pSt p_sign)
{
	int n,s;
	n=p_num->top;
	s=p_num->top;

	while(p_num->sign[s]!='#')
	{
		figure(p_num,p_sign,n,s);
		n=p_num->top;
		if(p_num->sign[s]!='#')
		{
			s--;
		}
	}
}

int main()
{
	printf("请输入计算式:\n");
	char str[SIZE];
	gets(str);
	int n;
	n=strlen(str);

	/**提取计算式中的数字与符号**/
	sSt s_sign;
	sSt s_num;
	init_memory(&s_sign);
	init_memory(&s_num);

	int i,j=0;
	for(i=0;i<=n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			j++;
		}else if(str[i]=='*'||str[i]=='/')
		{
			insert_num(&s_num,&str[0],i,j);
			j=0;
			insert_sign(&s_sign,&str[0],i);
			if(s_sign.sign[s_sign.top-1]=='*'||s_sign.sign[s_sign.top-1]=='/')
			{
				insert_specific(&s_num,&s_sign);
			}
		}else if(str[i]=='+'||str[i]=='-')
		{
			insert_num(&s_num,&str[0],i,j);
			printf("%d:%d\n",s_num.top-1,s_num.num[s_num.top-1]);
			j=0;
			insert_sign(&s_sign,&str[0],i);
			printf("%d:%c\n",s_sign.top-1,s_sign.sign[s_sign.top-1]);
			if(s_sign.sign[s_sign.top-2]=='*'||s_sign.sign[s_sign.top-2]=='/')
			{
				insert_specific(&s_num,&s_sign);
			}
		}else if(str[i]=='(')
		{
			s_sign.sign[s_sign.top]='#';
			s_sign.top++;
		}else if(str[i]==')')
		{
			figure_specific(&s_num,&s_sign);
		}else if(str[i]=='\0'||str[i]=='\n')
		{
			if(j>0)
			{
			  insert_num(&s_num,&str[0],i,j);
				j=0;
			}
		}
	}

	//s_num.top--;
	//s_sign.top--;
	while(s_sign.top >= 0)
	{
		printf("%d %d",s_num.top,s_num.top);
		figure(&s_num,&s_sign,s_num.top,s_sign.top);
		printf("s_num[%d]=%d\n",s_num.top,s_num.num[s_num.top]);
	  s_num.top--;
	  s_sign.top--;
	}

	printf("计算结果:%d\n",s_num.num[s_num.top]);
}

