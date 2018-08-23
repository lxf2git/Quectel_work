#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define M 3

void create_memory(void **p);
void free_memory(void **p);
void input(char *p[M]);
void output(char *p[M]);
int ch_compare(char ch1,char ch2);
void compare(char *p[M]);

int main()
{
		char *p[M];
		int i;
		for(i=0;i<M;i++)
		{
				create_memory((void **)&p[i]);
		}
		
		input(p);
		compare(p);
		output(p);

		for(i=0;i<M;i++)
		{
				free_memory((void **)&p[i]);
		}
		return 0;
}

void create_memory(void **p)
{
		*p=malloc(N);
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

void input(char *p[M])
{
		int i;
		for(i=0;i<M;i++)
		{
				printf("please input string %d:\n",i+1);
				scanf("%s",p[i]);
		}
}

void output(char *p[M])
{
		int i;
		for(i=0;i<M;i++)
		{
				printf("%s\n",p[i]);
		}
}

void compare(char *p[M])
{
		char t[N];
		int a;//比较结果
		int i,j,k;
		for(i=0;i<M-1;i++)
		{
				for(j=i+1;j<M;j++)
				{
						k=1;

						while(k<=strlen(p[i])-strlen(p[i])/2 && k<=strlen(p[j])-strlen(p[j])/2)
						{
										a=ch_compare(p[i][strlen(p[i])-k],p[j][strlen(p[j])-k]);
										if(a>0)
										{
												strcpy(t,p[i]);
												strcpy(p[i],p[j]);
												strcpy(p[j],t);
												break;
										}
										if(a<0)
										{
												break;
										}
								k++;
						}
				}
		}
}

int ch_compare(char ch1,char ch2)
{
		return ch1-ch2;
}
