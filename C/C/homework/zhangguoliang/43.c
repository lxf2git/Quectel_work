#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int main()
{
	char *a;
	int i,m,n;
	printf("输入字符串:\n");
	a=(char *)malloc(N*sizeof(char));
	scanf("%s",a);
	m=strlen(a);
	if(m==1)
	{
		printf("%s\n",a);
	}
	if(m>1)
	{
		for(i=0;i<m;i++)
		{
			printf("%c",*(a+i));
			if(*(a+i+1)=='\0')
					break;
			for(n=0;n<2*i+1;n++)
			{
				printf("#");
			}
		}
	}
	printf("\n");
	if(a!=NULL)
	{
		free(a);
		a=NULL;
	}
	return 0;
}
