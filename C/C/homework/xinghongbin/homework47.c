#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 3
void create_memory(char **p);
void str_memory(char *p[]);
void str_input(char *p[]);
void str_drv(char *p[],char *a[]);
void str_rank(char *a[],char *p[]);
void str_exchange(char **p,char **q);
int main()
{
		char *p[N];
		char *a[N];
//		create_memory((char **)&p);
//		create_memory((char **)&a);
		str_memory(p);
		str_memory(a);
		str_input(p);
		str_drv(p,a);
		str_rank(a,p);

		return 0;
}

void create_memory(char **p)
{
		*p=(char *)malloc(20);
}
void str_memory(char **p)
{
		int i;
		for(i=0;i<N;i++)
				create_memory(&p[i]);
}
void str_input(char *p[])
{
		int i;
		for(i=0;i<N;i++)
				scanf("%s",p[i]);
}

void str_drv(char *p[],char *a[])
{
		int i,j,k;
		for(i=0;i<N;i++)
		{
				int length = strlen(p[i]);
				for(j = length-1 ,k = 0 ; j>=k;j--,k++)
						a[i][k]=p[i][j];
				a[i][k]='\0';
//				printf("%s\n",a[i]);
		}

}

void str_rank(char *a[],char *p[])
{
		int i,j;
		for(i=0;i<N;i++)
		{
						for(j=i;j<N;j++)
								if( strcmp(a[i],a[j]) >= 0 )
								{
									str_exchange(&a[i],&a[j]);
									str_exchange(&p[i],&p[j]);	
								}
		
		}
		for(i=0;i<N;i++)
				printf("%s\n",p[i]);
}
void str_exchange(char **p,char **q)
{
		char temp[100]={};

		strcpy(temp,*p);
		strcpy(*p,*q);
		strcpy(*q,temp);
}
