#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

void create_memory(void ** str, int size)
{
	*str = malloc(size);
	if(NULL == *str)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void deal(char *pa, int len)
{
	int i,a=0,m,j;
	int count=0;//计算#的个数
	for(i=0;i<len;i++)
	{
		if(pa[i] == '#')
		{
			count++;
			if(count == 1)
			{
				a=i;
			}
			else
			{
				m = i-a;
				for(j=a;j<len;j++)
				{
					pa[j]=pa[j+m+1];
			
				}
				a--;
				i=a;
				count=0;
			}
		}
		else if((pa[i+1] == '\0')&&(count == 1))
		{
			pa[a] = '\0';
		}
	}
	puts(pa);
}

int main()
{
	char ch[N]={};
	char *ptr;
	int len;
	printf("please input your data:");
	scanf("%s",ch);
	len = strlen(ch);
	
	create_memory((void **)&ptr,len);
	ptr = ch;

	deal(ptr, len);

	return 0;

}
