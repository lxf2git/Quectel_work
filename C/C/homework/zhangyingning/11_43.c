#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

char *malloc_()
{
	char *p =NULL;
	p = malloc(N * sizeof(char));
	if (NULL == p)
	{
		printf("错误");
		exit(-1);
	}
	return p;
}

char in_put(char *p)
{
	printf("请输入一个字符串");
	scanf("%s",p);
	return *p;
}
void out_put(char *p)
{
	int a, b, c = 1, d;
	a = strlen(p);		//求长度
	for(b = 0;b < a; b++)
	{
			printf("%c",*(p + b));
			if(a - b == 1)		//判断最后一个字母跳出循环
			{
				break;
			}
			for(d = 0;d < c;d++)//循环打#
			{
				printf("#");
			}
			c += 2;//对#下一次循环次数加2
	}
	printf("\n");
}

int main()
{
	char *p = NULL;
	p = malloc_();
	*p = in_put(p);
	out_put(p);
	if(NULL == p)
	{
		free(p);
		p = NULL;
	}
	
}
