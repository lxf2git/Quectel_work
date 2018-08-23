#include"mystrcpy.h"

int mystrcpy(char *p,char *q)
{
	int m,n;
	m=(int)strlen(p);
	n=(int)strlen(q);
	if(m<n)
	{	printf("错了  段错误!\n");
		return 0;
	}
	if(m>=n)
	{
		while(n>0)
		{
			*p=*q;
			printf("%c",*p);
			q++;
			p++;
			n--;
		}
		printf("\n");
		return 0;
	}
}
