#include<stdio.h> 
#include<stdlib.h>

void number(char *point,int nu)
{
	int max=0,num,ch=0,number=0;
	char max_ch[50]={};
	for(num=1;num<nu;num++)
	{
		if(*(point+num)==' '||*(point+num)=='.')
		{
			if(number>max)
			{
				max=number;
			}
			number=0;
		}
		else
			number++;
	}
	printf("最长单词为：%d个\n",max);
	number=0;
	for(num=1;num<nu;num++)
	{
		if(*(point+num)==' '||*(point+num)=='.')
		{
			if(number>=max)
			{
				printf("最大字符为：%s\n",max_ch);
			}	
				ch=0;
				number=0;
		}
		else
		{
			number++;
			max_ch[ch]=*(point+num);
			printf("max_ch:%s ",max_ch);
			printf("number:%d\n",number);
			ch++;
		}
	}
}
int main()
{
	int nu=0;
	char *point;
	printf("您想输入大约多少字的句子哪？请尽量将空间定的宽裕一点\n");
	scanf("%d",&nu);
	point=(char*)malloc(nu*sizeof(char));
	if(NULL==point)
		printf("malloc error");
	printf("请输入字符串。\n");
	for(nu=0;;nu++)
	{
		scanf("%c",point+nu);
		if(*(point+nu)=='.')
			break;
	}	
	number(point,nu);
} 
