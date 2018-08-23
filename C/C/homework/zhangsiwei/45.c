#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

void fun(char *p)
{
	int n,m,i,j;
	m=0;
	n = strlen(p);
	printf("n=%d\n",n);
	for(i=0;i<n;i++)
	{
	//	printf("this is for\n");
		if(*(p+i)=='#')
		{
			for(j=i;j<n;j++)
			{
				*(p+j)=*(p+j+1);
			}
			*(p+n-1)='\0';
			m++;
			printf("m=%d ",m);
		}
		if(m%2==1)
		{
			for(j=i;j<n;j++)
			{
				*(p+j)=*(p+j+1);
			}
			*(p+n-1)='\0';
			n--;
			i-=1;
		}
		
	}
	printf("%s\n",p);
}
void input(char *p)
{
	scanf("%s",p);
}
void create_memory(char **p)
{
	*p = (char *)malloc(N*sizeof(char));
	if(NULL==*p)
	{
		printf("momery error\n");
		exit(-1);
	}
}
int main()
{
	char *p;
	create_memory(&p);
	input(p);
	fun(p);
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}
	return 0;
}
