#include<stdio.h>
#include<string.h>

int m,n,i;
char first();
char second();
char a[100];
char b[100];
int main()
{
	int x,y,j=0,k=0;
	m=first(m);
	n=second(n);
	printf("\n");
	m=m+n+1;
	strcat(a,b);
	for(i=0;i<m;i++)
	{
		for(x=i+1;x<m;x++)
		{
			if(a[i]>a[x])
			{
				y=a[i];
				a[i]=a[x];
				a[x]=y;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%c",a[i]);
	}
	for(i=0;i<m;i++)
	{
		if(a[i]=='\0')
			break;
		if(a[i]==a[i+1])
		{	
			for(j=i;j<m+1;j++)
			{
				a[j]=a[j+1];
			}
		if(a[i]==a[i+1])
			i--;
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}

char first()
{
	
	char y;
	int i,m=0,x=0;
	printf("输入第一个字符串:\n");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		m++;
		if(a[i]=='\n')
		break;
	}
	m=m-1;
	for(i=0;i<m;i++)
	{
		for(x=i+1;x<m;x++)
		{
			if(a[i]>a[x])
			{
				y=a[i];
				a[i]=a[x];
				a[x]=y;
			}
		}
	}
	printf("排序后第一个字符串:\n");
	for(i=0;i<m;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return m;
}

char second()
{
	char y;
	int i,n=0,x;
	printf("输入第二个字符串:\n");
	for(i=0;;i++)
	{
		scanf("%c",&b[i]);
			n++;
		if(b[i]=='\n')
		break;
	}
	n=n-1;
	for(i=0;i<n;i++)
	{
		for(x=i+1;x<n;x++)
		{
			if(b[i]>b[x])
			{
				y=b[i];
				b[i]=b[x];
				b[x]=y;
			}
		}
	}
	printf("排序后第二个字符串:\n");
	for(i=0;i<n;i++)
	{
		printf("%c",b[i]);
	}
	return n;
	printf("\n");
	
}

