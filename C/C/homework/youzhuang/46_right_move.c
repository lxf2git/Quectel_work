#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

void output(char *p);
int input(char *p);
void create_memory(void **p,int size);
void free_memory(void **p);
void right_move(char *p);
void move(char *p,int n);

int main()
{
		int n;
		char *p=NULL;
		create_memory((void **)&p,N*sizeof(char));
		n=input(p);
		move(p,n);
		output(p);
		free_memory((void **)&p);
		return 0;
}

void output(char *p)
{
		printf("after right move is:\n");
		printf("%s\n",p);
}

int input(char *p)
{
		int n;
		printf("please input string:\n");
		scanf("%s",p);
		printf("please input n:\n");
		scanf("%d",&n);
		return n;
}

void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}

void free_memory(void **p)
{
		free(*p);
		if(*p!=NULL)
		{
				*p=NULL;
		}
}

void right_move(char *p)
{
		int i=strlen(p)-1;
		char t;
		t=*(p+i);
		for(;i>0;i--)
		{
				*(p+i)=*(p+i-1);
		}
		*p=t;
}

void move(char *p,int n)
{
		while(n>0)
		{
				right_move(p);
				n--;
		}
}
