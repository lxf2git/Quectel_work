#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int main()
{
	char *a;
	int i,m,flag,n=0,j=0,max=0;
	printf("输入一个英文句子:\n");
	a=(char *)malloc(N*sizeof(char));
	for(i=0;;i++)
	{
		scanf("%c",(a+i));
		if(*(a+i)==' ')
		{
			n=0;
		}
		if(*(a+i)!=' '&&*(a+i)!='.')
		{
			n++;
			if(max<n)
			{
				max=n;
			}
		}
		if(*(a+i)=='.')
		{
			*(a+i)='\0';
			break;
		}
	}
	m=strlen(a);
	n=0;
	for(i=0;i<m;i++)	
	{
		if(*(a+i)==' ')
		{
			n=0;
		}
		if(*(a+i)!=' ')
		{
			n++;
			if(n==max)
			{
				flag=i;
				j=flag-max+1;
				for(;j<=flag;j++)
				{
					printf("%c",*(a+j));
				}
				printf("\n");
			}
		}
		if(*(a+i)=='\0')
		{
			break;
		}
	}
	

	return 0;
}
