#include<stdio.h>
int main()
{
	int i,x,n=0,j=0;
	char m,c,y;
	char a[100];
	printf("输入字符:\n");
	for(i=0;;i++)
	{	
		scanf("%c",&a[i]);
		j++;
		if(a[i]=='\n')
			break;
	}
	j=j-1;
	for(i=0;i<j;i++)
	{ 	
		for(n=i+1;n<j;n++)
		{
			if(a[i]>a[n])
			{	m=a[i];
				a[i]=a[n];
				a[n]=m;
			}	
		}
	}
	for(i=0;i<j;i++)
	{
		printf(" %c",a[i]);
	}
	printf("\n输入一个字符:\n");
	scanf("%c",&c);
	for(i=0;i<j;i++)
	{
		if(c>a[i]&&c<=a[i+1])
		{
			y=a[i+1];
			a[i+1]=c;
			x=i+1;
			for(n=j;n>x+1;n--)
			{
				a[n]=a[n-1];
			}
			for(i=0;i<j+1;i++)
			{
				a[x+1]=y;
				printf("%c",a[i]);
			}
		}
		if(c<a[0])
		{
			y=a[0];
			a[0]=c;
			x=1;
			for(n=j;n>x;n--)
			{
				a[n]=a[n-1];
			}
			for(i=0;i<j+1;i++)
			{
				a[1]=y;
				printf("%c",a[i]);
			}
		}
		if(c>a[j-1])
		{
			for(i=0;i<j+1;i++)
			{
				a[j]=c;
				printf("%c",a[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
