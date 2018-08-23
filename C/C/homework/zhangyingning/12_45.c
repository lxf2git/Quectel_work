#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

char *malloc_()
{
	char *p;
	p =(char *) malloc(N * sizeof(char));
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
	char *p1 = NULL;
	int a, b, c = 2, c1 = 0, a1 = 0;
	p1 = malloc_();
	a = strlen(p);
	for(b = 0;b < a;b++)
	{
		if(*(p + b) == '#')
		{
			c++;
			c1 = c % 2;
		}
		if(0 == c1)
		{
			if(*(p + b) == '#')
			{
					;
			}
			else
			{
				*(p1 + a1) = *(p + b);
				a1++;
//				printf("c1 =%da1=  %d ",c1,a1);
			}
		}
//		printf("%c",*(p +b));
	}
		*(p1 + a1) = '\0';
		printf("%s\n",p1);
}


int main()
{
	char *p = NULL;
	p = malloc_();
	*p = in_put(p);
	out_put(p);
	printf("%s",p);
}
