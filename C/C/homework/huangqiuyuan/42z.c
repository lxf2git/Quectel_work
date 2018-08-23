#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
	int i,m,j,count=0,w=0,n,max=0,flag;
	char *a;
	printf("输入一句英文");
	a=(char*)malloc(N*sizeof(char));
         for(i=0;;i++)
	{
		scanf("%c",(a+i));
		if(*(a+i)==' ')
		{
			count=0;
		}
		if(*(a+i)!=' '&&*(a+i)!='.')
		{
			count++;
			if(max<count)
				max=count;
		}
			if(*(a+i)=='.')
				break;
	}
		m=strlen(a);
		
	for(i=0;i<m;i++)
	{
		if(*(a+i)==' ')
			count=0;
			if(*(a+i)!=' ')
			{
				count++;
				if(count==max)
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
			if(*(a+i)=='.')
				break;
	}
	return 0;
}
