#include<stdio.h>
int main()
{
	int i,j=0,n=0;
	char a[20];
	printf("输入字符:");
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
		if(a[i]=='c')
		{	
			n=i;
			for(n=i;n<j;n++)
			{
				a[n]=a[n+1];
			}
		}
	}
	for(i=0;i<j;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
