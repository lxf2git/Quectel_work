#include<stdio.h>
#include<string.h>
int px(char ch[],int j);
int main()
{
	int i,j,p;
	char a;
	char ch[178];
	printf("请输入字符：");
	gets(ch);
	j=strlen(ch);
	px(ch,j);
}
int px(char ch[],int j)			
{
	int i,p;
	char t;
	for(p=0;p<j;p++)
	{
	for(i=0;i<j;i++)
	{	
		t=ch[i];
		if(t>ch[i+1])
		{
			ch[i]=ch[i+1];
			ch[i+1]=t;
		}
	}
	}
	for(i=0;i<j+1;i++)
	{
		printf("%c",ch[i]);
	}
	printf("\n");
	
	return 0;
	
}
