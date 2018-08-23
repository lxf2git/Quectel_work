#include<stdio.h> 
#include<stdlib.h>
void input(char x[100]);
void cop(char x[100],char y[100]);
int main() 
{
		char a[100]={},b[100]={};
		printf("输入第一个字符串\n");
		input(a);
		printf("输入第二个字符串\n");
		input(b);
		cop(a,b);//字符串的对比
}

void input(char x[100])
{
		gets(x);
}

void cop(char x[100],char y[100])
{
		int i,count=0,j,l=0,man=0,biao,wan,h;
		for(i=0;i<100;i++)
		{
			if(x[i]=='\0')
					break;
			for(j=0;j<100;j++)
			{
					if(y[j]=='\0')
							break;
					if(x[i]==y[j])
					{
							count++;
							man=i+1;
							wan=j+1;
							for(;;man++,wan++)
							{
									if(x[man]=='\0'||y[wan]=='\0')
											break;
									if(x[man]==y[wan])
											count++;
									if(x[man]!=y[wan])
											break;
							}
							if(l<count)
							{
									l=count;
									biao=j;
							}
					count=0;
					}
			}
		}
	//	printf("%d\n",biao);
		h=biao+l;
		for(;biao<h;biao++)
		{
		printf("%c",y[biao]);
		}
}
