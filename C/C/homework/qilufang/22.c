#include<stdio.h>
#include<string.h>

int main()
{
	char string[100]={'\0'};
	char input,b;
	int i,j,a=0,c=0;
	printf("输入一串排好续的字符串：\n");
	gets(string);
	printf("输入要插入的字符：\n");
	scanf("%c",&input);
	for(i=0;i<100;i++)				//找出此时字符的下标
	{
		if(input<string[i])
		{
			break;
		}
		a++;

	}
			printf("%d\n",a);
	for(j=98;j>0;j--)				//字符串统一后移，字符插入
	{
		if(j>=a)
		{
		//	c=string[j+1];
			string[j+1]=string[j];
		//	string[j]=c;
		//	printf("string[j+1]=%c\n",string[j+1]);
		}
	}
	string[a]=input;
	puts(string);					//排序输出

	return 0;
}
