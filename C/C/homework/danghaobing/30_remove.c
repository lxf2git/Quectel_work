#include<stdio.h> 
#include<string.h>
void in(char x[100]);
void rm(char x[100]);
void mv(char x[100]);
int main() 
{
		char a[100]={},b[100]={};
		printf("请输入第一个字符串\n");
		in(a);
		printf("第一个字符串排序的结果\n");
		rm(a);//给第一个字符串排序
		printf("请输入第二个字符串\n");
		in(b);
		printf("第二个字符串排序结果\n");
		rm(b);//给第二个字符串排序
		strcat(a,b);//字符串拼接
		printf("字符拼接后的排序结果\n");
		rm(a);//字符串排序
		printf("结合后去掉重复字符的排序结果\n");
		mv(a);//移除相同的字符
}

void in(char x[100])
{
		gets(x);
}

void rm(char x[100])
{
		int i,j,m;
		for(i=0;i<100;i++)
		{
			for(j=i;j<100;j++)
			{
				if(x[i]>x[j]&&x[j]!='\0')
				{
					m=x[i];
					x[i]=x[j];
					x[j]=m;
				}
			}
		}
		puts(x);
}

void mv(char x[100])
{
		int i,j,w;
		for(i=0;i<100;i++)
		{
				if(x[i]=='\0')
						break;
				if(x[i]==x[i+1])//检测到相同的字母
				{
						w=i;//防止大循环失效；
						for(j=w+1;j<100;j++,w++)//将所有的数值向前推进一位，覆盖掉重复的一位
						{
							
								x[w]=x[j];
						}
					if(x[i]==x[i+1])//解决多余两个字母的重复问题
					i--;		
				}

		}
		puts(x);
}
