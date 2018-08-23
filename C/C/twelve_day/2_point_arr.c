#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3

void create_memory(char **p,int size)
{
		*p = (char *)malloc(size);
		if(NULL==*p)
		{
			printf("malloc error");
			exit(-1);
		}

}

void input(char **str)
{
	int i;
	for(i=0;i<N;i++)
	{
			printf("please input the string %d\n",i+1);
			scanf("%s",*(str+i));
	}
}
void fun(char *p[])//char **p char *p[3] p=ptr
{

	int i,size;
	for(i=0;i<N;i++)
	{
		printf("please input the size of string %d\n",i+1);
		scanf("%d",&size);	
		create_memory(&p[i],size);
	}	
	input(p);

}

void output(char **p)
{
	int i;	
	for(i=0;i<N;i++)
	{
		printf("%s\n",p[i]);
	}

}
int main()
{
	//int (*p)[3];
	int i;
	char *ptr[N];//指针数组是数组 
	fun(ptr);
	output(ptr);

	return 0;

}
