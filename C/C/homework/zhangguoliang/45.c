#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int main()
{
	char *a;
	char b;
	int i,j=0,m;
	printf("输入字符串:\n");
	a=(char *)malloc(N*sizeof(char));
	scanf("%s",a);
	m=strlen(a);
	for(i=0;i<m;i++)
	{
		if(*(a+i)=='#')
		{
			j++;
		}
		if(j%2==0&&*(a+i)!='#')
		{
			b=*(a+i);
			printf("%c",b);
		}
	}
	printf("\n");
	return 0;
}
