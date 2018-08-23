#include<stdio.h>
#include<string.h>

void Exchange(int x,char ch[10],int m);
char toch(int n);
int length(int x);

int main()
{
		int x,m;
		char ch1[10]="-";
		char ch2[10];
		printf("请输入数字:\n");
		scanf("%d",&x);
		if(x<0)
		{
				m=length(-x);
				Exchange(-x,ch2,m);
				strcat(ch1,ch2);
		}
		else
		{
				m=length(x);
				Exchange(x,ch2,m);
				strcpy(ch1,ch2);
		}
		printf("String:%s\n",ch1);
		return 0;
}

int length(int x)
{
		int i,m=0;
		for(i=1;i<=x;i=i*10)
		{
				m++;
		}
		return m;
}

void Exchange(int x,char ch[10],int m)
{
		int k,n=1,i,j=0;
		for(k=0;k<m;k++)
		{
				n=n*10;
		}
		for(i=n;i>=1;i=i/10)
		{
				if(x/i!=0)
				{
						ch[j]=toch(x/i%10);
						j++;
				}
		}
		ch[m]='\0';
}

char toch(int n)
{
		char ch;
		ch=n+48;
		return ch;
}
