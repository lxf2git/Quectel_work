#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
void shift(char *q)
{
	int m,n,i,j=0;
	char *a;
	char *b;
	m=strlen(q);
	printf("输入右移位数n:\n")	;
	scanf("%d",&n);
	a=(char *)malloc((m-n)*sizeof(char));
	b=(char *)malloc(m*sizeof(char));
	for(i=0;i<m-n;i++)
	{
		*(a+i)=*(q+i);
	}
	for(i=m-n;i<m;i++)
	{
		*(b+j)=*(q+i);
		j++;
	}
	strcat(b,a);
	printf("%s\n",b);
}


int main()
{
	char *p=NULL;
	p=(char *)malloc(N*sizeof(char));
	printf("输入字符串:\n");
	scanf("%s",p);
	shift(p);
	return 0;
}
