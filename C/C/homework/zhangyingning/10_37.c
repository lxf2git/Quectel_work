#include<stdio.h>
#include<string.h>
#define N 10


void *get_char(char *p)
{
	gets(p);
	return p;

}
# if 1
char *strcpy_(char *p,char *p1)
{
	int i, es;
	for(i = 0;i < N;i++)
	{
		if('\0' == *p1)
		{
			return p;
		}
		*p = *p1;
		p++;
		p1++;
	}

}
#endif
char *strcat_(char *p,char *p1)
{
	int i, j;
	for(i = 0;i < N;i++)
	{
		if('\0' == *p)
		{
			break;
		}
		p++;
	}
	for(j = 0;j < N;j++)
	{
		if('\0' == *p1)
		{
			return p;
		}
		*p = *p1;
		p++;
		p1++;
	}
}
char *strcmp_(char *p,char *p1)
{
	int i,j;
	for(i = 0;i < N;i++)
	{
		if(*p > *p1)
		{
			return 1;
		}
		if(*p < *p1)
		{
			return -1;
		}
		if('\0' == *p)
		{
			return 0;
		}
		p++;
		p1++;
	}
}

int main()
{
	char arr[N] = {'0'};
	char arr1[N] = {'0'};
	int i,j;
	char *p, *p1;
	p = arr;
	p1 = arr1;
	for(;;)
	{
		printf("请输入你要选择的功能\n");
		printf("1  strcpy  \n2  strcat\n3  strcmp\n0  quite\n");
		scanf("%d",&i);
		getchar();
		printf("请输入第一组字符串\n");
		get_char(p);
		printf("请输入第二组字符串\n");
		get_char(p1);
		if(1 == i)
		{
			strcpy_(p,p1);
			puts(arr);
		}
		if(2 == i)
		{
			strcat_(p,p1);
			puts(arr);
		}
		if(3 == i)
		{
			j = strcmp_(p,p1);
			printf("%d\n",j);
		}
		if(0 ==i )
		{
			break;
		}
	}
	return 0;
}
