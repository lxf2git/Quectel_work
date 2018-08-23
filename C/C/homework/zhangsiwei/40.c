#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
	int flag,i;
	char *a,*b,*c=NULL;
	printf("please input a:\n");
	a = malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%c",a+i);
		if(*(a+i)=='\n')
		{
			*(a+i)='\0';	
			break;
		}
	}
	printf("please input b:\n");
	b = malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%c",b+i);
		if(*(b+i)=='\n')
		{	
			*(b+i)='\0';	
			break;
		}
	}
	printf("please input flag:");
	scanf("%d",&flag);
	switch(flag)
	{
		case 0:
			printf("%s",strcat(a,b));
			break;
		case 1:
			printf("%s",strcat(b,a));
			break;
		default:
			printf("%s",*c);
			break;
	}
	if(a!=NULL)
	{
		free(a);
		a = NULL;
	}
	if(b!=NULL)
	{
		free(b);
		b = NULL;
	}
	return 0;
}
