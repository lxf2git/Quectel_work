#include<stdio.h>
#include<string.h>
#define N 100

void search(int x,int y,char a[],char b[]);
//void judge(int x,int a[],int b[]);

int main()
{
	int m,n;
	char a[N];
	char b[N];
	printf("请输入字符串一\n");
	gets(a);
	printf("请输入字符串二\n");
	gets(b);
	m=strlen(a);
	n=strlen(b);
	search(m,n,a,b);
	return 0;
}

void search(int x,int y,char a[],char b[])
{
	int i,j,k;
	int m,n,o;
	int max=0;
	int sta,end;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(a[i]==b[j])
			{
				n=1;
				m=j;
				for(k=1;k<(x-i)&&k<(y-j);k++)
				{
					if(a[i+k]==b[j+k])
					{
						n++;
						o=j+k;
					}
					else 
						break;
				}
			}
			if(max<n)
			{
				max=n;
				sta=m;
				end=o;
				n=0;
			}
		}
	} 
	printf("最大公共子串为：\n");
	for(j=sta;j<end+1;j++)
		printf("%c",b[j]);
	printf("\n");
}


