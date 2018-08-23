#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
void creat(void** p, int size);
int input(char* p);
char* deal_str(char*p1,char*p2,int flag);
#define  N (100)
int main()
{
	char *p1=NULL, *p2=NULL;
	int flag;
	creat((void**)&p1, N*sizeof(*p1));
	creat((void**)&p2, N*sizeof(*p2));
	
	input(p1);
	input(p2);

	printf("please input flag\n");
	scanf("%d",&flag); 

	deal_str(p1,p2,flag);
	
	free(p1);
	free(p2);

	return 0; 
}

void creat(void** p, int size)
{
	*p = malloc(size);
	if (NULL == *p)
	{
		printf("please input malloc error \n"); 
	}
}

int input(char* p)
{	
	printf("please input \n"); 
		
	gets(p);

	return 0; 
}

char* deal_str(char*p1,char*p2,int flag)
{
	if (0==flag)
	{
		strcat(p1,p2);
		puts(p1);
	}
	else if (1==flag)
	{
	
		strcat(p2,p1);
		puts(p2);
	}

	else
			return NULL; 

}






















