#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

void create_momery(void **p,int size)
{
	*p = malloc(size);
	if(NULL==*p)
	{
		printf("momery error\n");
		exit(-1);
	}
}

void input(char *p)
{
	int i;
	printf("please input char:\n");
	for(i=0;i<N;i++)
	{
		scanf("%c",p+i);
		if(*(p+i)=='\n')
		{
			*(p+i)='\0';
			break;
		}
	}
	printf("p=%s\n",p);
	
}

void fun(char *p,char **pp)
{
	int n,i,j;
	j=1;	
	n=strlen(p);
	printf("n=%d\n",n);
	for(i=0;i<n;i++)
	{
			if(*(p+i)==' ')
					j++;
	}
	printf("j=%d",j);
	create_momery((void **)&pp,j*sizeof(char*));
	printf("第一空间已经开启\n");
	for(i=0;i<j;i++)
	{
		create_momery((void **)pp+i,N*sizeof(char));
	}
	printf("第二空间已经开启\n");
	
}
int main()
{
	char *p;char **pp;
	int i,k,n,m;
	create_momery((void **)&p,N*sizeof(char));
	input(p);
	fun(p,pp);
	n=strlen(p);
	printf("nn=%d\n",n);


	m=0;k=0;
	printf("m=%d\n",m);
	for(i=0;i<n;i++)
	{
		printf("i=%d  ",i);
		printf("%c\n",*(p+i));
		if(*(p+i)!=32)
		{
				printf("++++\n");
			*(*(pp+m)+k) = *(p+i);
			
		//	k++;
		}
		else
		{
				printf("-----\n");
	//		m++;k=0;
		}   
	}
	printf("k=%d\n",k);
	for(i=0;i<m+1;i++)
	{
			printf("pp%s\n",*(pp+i));
	}
	return 0;
}
