#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void creat_memory(void **p,int size);
void change(char *p,int n);

int main()
{
	char *p;
	int n,i;
	printf("请输入最多输入多少个字符\n");
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(char));
	change(p,n);
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void change(char *p,int n)
{
	int i;
	char ch;
	printf("请输入字符串\n");
	scanf("%s",p);
	for(i=0;i<strlen(p)/2;i++)
	{
		ch=p[i];
		p[i]=p[strlen(p)-1-i];
		p[strlen(p)-1-i]=ch;
	}
	puts(p);
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
}
