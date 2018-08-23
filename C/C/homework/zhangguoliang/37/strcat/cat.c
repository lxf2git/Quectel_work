#include<stdio.h>
#include<string.h>
int main()
{
	
	char a[100];
	char b[100];
	printf("输入字符串:\n");
	scanf("%s",a);
	printf("在输入字符串:\n");
	scanf("%s",b);
	mystrcat(a,b);
	return 0;
}


int mystrcat(char *dest,char *src)
{
	int m,n,i=0;
	m=(int)strlen(dest);
	n=(int)strlen(src);
	while(i<n)
	{
		*(dest+m+i)=*(src+i);
			i++;
	}
	for(i=0;i<m+n;i++)
	{		
	printf("%c",*dest);
	dest++;
	}
	printf("\n");
	return 0;
}
