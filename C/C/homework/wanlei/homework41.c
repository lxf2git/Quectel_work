#include<stdio.h>
#include<stdlib.h>

void creat_memory(void **p, int size);
void input(char *p);
void menu(char *p, char *q, int x, int y);
void my_strcat(char *p, char *q, int x, int y);

int main()
{
	char *p=NULL,*q=NULL;
	int m, n;
	printf("请输入要分别输入多少个字符\n");
	scanf("%d%d",&m,&n);
	creat_memory((void **)&p,m*sizeof(char));
	creat_memory((void **)&q,n*sizeof(char));
	input(p);
	input(q);
	//puts(p);
	//puts(q);
	menu(p,q,m,n);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
	if(q!=NULL)
	{
		free(q);
		q=NULL;
	}
	return 0;
}

void creat_memory(void **p, int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void input(char *p)
{
	printf("请输入字符串\n");
	scanf("%s",p);
}

void menu(char *p, char *q, int x, int y)
{
	int flag;
	printf("请选择使用的功能\n");
	printf("0:a+b\n");
	printf("1:b+a\n");
	scanf("%d",&flag);
	switch(flag)
	{
		case 0:
			my_strcat(p,q,x,y);
			break;
		case 1:
			my_strcat(q,p,y,x);
			break;
		default:
			p=NULL;
			printf("%p\n",p);
			break;
	}
}

void my_strcat(char *p, char *q, int x, int y)
{
	char *point=NULL;
	char *p_start=NULL;
	creat_memory((void **)&point,(x+y)*sizeof(char));
	p_start=point;
	puts(p);
	puts(q);
	while(*p!='\0')
	{
		*point=*p;
		point++;
		p++;
	}
	while(*q!='\0')
	{
		*point=*q;
		point++;
		q++;
	}
	//:*(point+1)='\0';
	puts(p_start);
}
