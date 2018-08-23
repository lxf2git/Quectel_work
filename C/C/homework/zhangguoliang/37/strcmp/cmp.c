#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	int j;
	printf("输入字符串:\n");
	scanf("%s",a);
	printf("在输入字符串:\n");
	scanf("%s",b);
	j=mystrcpy(a,b);
	printf("%d\n",j);
	if(j>0)
		printf("a>b\n");
	if(j<0)
		printf("a<b\n");
	if(j==0)
		printf("a==b\n");
	return 0;
}


int mystrcpy(char *dest,char *src)
{
	int m,n,i;
	m=(int)strlen(dest);
	n=(int)strlen(src);
	for(i=0;i<m&&i<n;i++)
	{
		if(*dest-*src!=0)
		{
			return *dest-*src;
		
		}
		dest++;
		src++;
	}
		if(*dest==*src&&m==n)
		{
			return 0;
		}
}
