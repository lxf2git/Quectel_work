#include<stdio.h>
#include<string.h>

int main()
{
	char m;
	int n,i,j,k,a,b,c,d;
	char string[50]={'0'};
	for(i=0;;i++)
	{
		scanf("%c",&string[i]);
		if(string[i]==10)
		{
			break;
		}
	}
	n=strlen(string);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i;j++)
		{
			a=string[j];
			b=string[j+1];
			if(a>b)
			{
				k=string[j];
				string[j]=string[j+1];
				string[j+1]=k;
			}
		}
	for(i=0;i<n+1;i++)
	printf("%c",string[i]);
	printf("\n");
	printf("请输入一个字符\n");
	scanf("%c",&m);
	for(i=0;i<n+1;i++)
	{
		a=m;
		b=string[i];
		c=string[i+1];
		d=string[n];	
		if(a>d)
		{
			string[n+1]=m;
			break;
		}
		else if(a>=b&&a<=c)
		{
			for(j=i+1;j<n+2;j++)
			{
				k=string[j];
				string[j]=m;
				m=k;
			}
			break;
		}
	}
	for(i=0;i<n+2;i++)
	printf("%c",string[i]);
	printf("\n");
	return 0;
}
