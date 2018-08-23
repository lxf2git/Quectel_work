#include<stdio.h>
#include<string.h>

void input(char a[]);
void change(int x,char a[]);
void del(int x,char a[]);

int main()
{
	int i,m,n,o;
	char a[250],b[100];
	input(a);
	input(b);
	m=strlen(a);
	n=strlen(b);
	change(m,a);
	change(n,b);
	//puts(a);
	//puts(b);
#if 1
	strcat(a,b);
	//puts(a);
	o=strlen(a);
	change(o,a);
	del(o,a);
#endif
	//printf("%d %d",m,n);
	return 0;
}

void input(char a[])
{
	gets(a);
}

void change(int x,char a[])
{
	int i,j,t;
	for(i=0;i<x;i++)
	{
		for(j=0;j<i;j++)
		if(a[i]<a[j])
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
}

void del(int x,char a[])
{
	int i,j,k;
	//int n=x;
	for(j=0;j<x;j++)
	{
		for(i=0;i<x;i++)
		{
			if(a[i]==a[i+1])
			{
				for(k=i;k<x;k++)
				{
					a[k]=a[k+1];
				}
			}
		}
	}
	printf("最后的结果为：");
	puts(a);
}
