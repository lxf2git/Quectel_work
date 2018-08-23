#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

char *deal2(char *p3,char *p4);
void create_memory(void **p,int size);
void input(char **p);
void compare(char **p);
int deal(char *p1, char *p2);
void free1(void **p);

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	bzero(*p,size);
}

void input(char **p)
{
	int i;
	int size;
	for(i=0;i<N;i++)
	{
		printf("input str%d size:",i+1);
 		scanf("%d",&size);
   		create_memory((void **)p+i,size);
 		printf("input str%d :",i+1);
		scanf("%s",*(p+i));		
	}
}

void compare(char **p)
{
	int i,j,k;
	char *pch;
	for(i=0;i<N-1;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
		{
			if(-1 == deal(p[j],p[k]))
			{
				k=j;
			}
		}
		if(k != i)
		{
			pch = *(p+i);
			*(p+i) = *(p+k);
			*(p+k) = pch;
		}
	}
}

int deal(char *p1, char *p2)
{
	char *pa;
	char *pb;
	int a;
	create_memory((void **)&pa,strlen(p1)/2+strlen(p1)%2);
	create_memory((void **)&pb,strlen(p2)/2+strlen(p2)%2);

	pa = deal2(pa,p1);
	pb = deal2(pb,p2);

	a = strcmp(pa,pb);
	free(pa);
	free(pb);

	return a;
}

char *deal2(char *p3,char *p4)
{
	int i,len,n;
	len = strlen(p4);
	n = len/2+len%2;
	for(i=0;i<n;i++)
	{
		p3[i] = p4[len-1-i];
	}
	p3[n]=0;
	
//	printf("p3:%s\n",p3);
	return p3;
}

int main()
{
	int i;
	char *ptr[N];
	input(ptr);

	compare(ptr);
	for(i=0;i<N;i++)
	{
		printf("%s\n",ptr[i]);
	}
	return 0;
}
