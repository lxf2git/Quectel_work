#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

void input(char *p1,char *p2,int *pflag);
void print(char *p);
char *link(char *p1, char *p2, int *flag);
void creat_memory(void **p,int size);

int main()
{
		char *p1,*p2;
		int *pflag;
		creat_memory((void **)&p1,N*sizeof(char));
		creat_memory((void **)&p2,N*sizeof(char));
		creat_memory((void **)&pflag,sizeof(int));

		printf("input a,b,flag:\n");
		input(p1,p2,pflag);
		
		printf("%s\n",link(p1,p2,pflag));

		return 0;
}

char *link(char *p1, char *p2, int *flag)
{
		switch(*flag)
		{
				case 0:
						return strcat(p1,p2);
				case 1:
						return strcat(p2,p1);
				default:
						return "";
		}
}

void input(char *p1, char *p2, int *pflag)
{
		scanf("%s",p1);
		scanf("%s",p2);
		scanf("%d",pflag);
}

void creat_memory(void **p,int size)
{
		*p=malloc(size);
}
