#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void creat_memory(void **p,int size);
int deal_num(char *pn,int place);
void deal_argv(char *pc);
void deal_calculate(int *pt,char ch);
int pl_(int place);
void sub(int,int);
void add(int,int);
void mul(int,int);
void div_(int,int);
int main(int argc,char *argv[])
{
	if(argc<1)
	{
		printf("file_name argument\n");
		exit(-1);
	}
	deal_argv(argv[1]);
	return 0;
}
void deal_argv(char *pc)
{
	int l=strlen(pc);
	int i,place,j,k,n=0;
	int cal_num[2]={};
	char cal_op;
	char *number=NULL;
	for(i=0;i<l;i++)
	{
		if(*(pc+i)>='0'&&*(pc+i)<='9')
		{
			k=i;
			for(place=0;*(pc+i)>='0'&&*(pc+i)<='9';i++)
			{
				place++;
			}
			creat_memory((void **)&number,place*sizeof(char));
			for(j=0;j<place;j++)
			{
				*(number+j)=*(pc+k);
				k++;
			}
			cal_num[n] = deal_num(number,place);
			n++;
			free(number);
			i--;
		}
		else if(*(pc+i)=='/'||*(pc+i)=='-'||*(pc+i)=='+'||*(pc+i)=='*')
		{
			cal_op=*(pc+i);
		}
		else
		{
			continue;
		}
	}
	deal_calculate(cal_num,cal_op);
}
void deal_calculate(int *pt,char ch)
{
	int a=*pt;
	int b=*(pt+1);
	void (*pf[4])(int,int)={add,sub,mul,div_};
	switch(ch)
	{
		case '+':pf[0](a,b);break;
		case '-':pf[1](a,b);break;
		case '*':pf[2](a,b);break;
		case '/':pf[3](a,b);break;
		default:break;
	}
}
int deal_num(char *pn,int place)
{
	int i;
	int num=0;
	for(i=0;place!=0;i++)
	{	
		num=(pn[i]-48)*pl_(place)+num;
		place--;
	}
	return num;
}
int pl_(int place)
{
	int pl=1;
	while((--place)!=0)
	{
		pl=pl*10;
	}
	return pl;
}
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	bzero(*p,size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void sub(int a,int b)
{
	printf("%d\n",a-b);
}
void add(int a,int b)
{
	printf("%d\n",a+b);
}
void mul(int a,int b)
{
	printf("%d\n",a*b);
}
void div_(int a,int b)
{
	if(b==0)
	{
		printf("error\n");
	}
	else
	{
		printf("%f\n",(float)a/b);
	}
}
