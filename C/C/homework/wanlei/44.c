#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1024

int open(int x);
void input(char *p);
void change(char *p, char *q);

int main()
{
	char str_old[N];
	char *str_new=NULL;
	int s;
	s=open(N);
	str_new = (char *)malloc(s*sizeof(char));
	if(str_new==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	input(str_old);
	change(str_old,str_new);
	if(str_new!=NULL)
	{
		free(str_new);
		str_new=NULL;
	}
	return 0;
}

int open(int x)
{
	int a;
	if(x%3==0)
	{
		a=x/3+x-1;
	}
	else
	{
		a=x/3+x;
	}
	return x;	
}

void input(char *p)
{
	printf("请输入一个字符串\n");
	scanf("%s",p);
}

void change(char *p, char *q)
{
	//int s,t;
	//s=strlen(p);
	//t=open(s);
	int i=0;
	char *q_start=q;
	while(*p!='\0')
	{
		i++;
		if(i%4!=0)
		{
			*q=*p;
			p++;
			q++;	
		}
		else
		{
			*q=' ';
			q++;
		}
	}
	puts(q_start);
}
