#include<stdio.h>
#include<string.h>
//找出两个字符串中的最大公共子串
int main()
{
	void gonggongzichuan(char *str1,char *str2,int m,int n);
	int m,n;						
	char str1[100],str2[100];
	printf("请输入a字符串：\n");
	gets(str1);
	printf("请输入b字符串：\n");
	gets(str2);
	m=strlen(str1);
	n=strlen(str2);
	if(m>=n)//使第一个字符串长度大于等于第二个
	gonggongzichuan(str1,str2,m,n);
	else
	gonggongzichuan(str2,str1,n,m);
	return 0;
}
void gonggongzichuan(char *str1,char *str2,int m,int n)
{
	int n1=0,n2,i,j,x,y;
	char	str[100];
	for(i=0;;i++)
	{
		for(j=0;j<n;j++)
		{
			if(str2[j]==str1[i])
			{		
				x=i;
				y=j;
				while(str2[y]==str1[x])
				{	
					x++;
					y++;	
				}
				if(x-i>n1)
				{
					n1=x-i;				//相同字符串的个数,如最大字串都含'\0',n1也包含'\0'
					n2=i;					//相同字符串的在str1下标
				}
			}
		}
		if(i==m)
		break;
	}
	printf("%d,%d\n",n2,n1);
	str1=str1+n2;					//将str1指向最大相同字符串的首地址
	for(i=0;i<n1;i++)
	{
		str[i]=*str1;
		str1++;
	}
	str[i]='\0';
	puts(str);
}
