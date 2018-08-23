#include<stdio.h>
#define N 10
#include<string.h>
int fen(char a[N],int b);
int pan(char a[N],char b[N],int c);
int main()
{	
	int b;
	char str[N]={'\0'};
	printf("输入一段长度为%d的字符串：\n",N);
	gets(str);
	b=fen(str,strlen(str));
	if(b==1)
	{
		printf("是回文!\n");
	}
	else
	printf("不是回文！\n");
//	puts(str);
//	printf("%d",strlen(str));
	return 0;
}
int fen(char a[N],int b)
{
	int k=0,i,j,d=0;
	char str_1[N/2]={'\0'};
	char str_2[N/2]={'\0'};
//	printf("%d",b);
	for(i=0;i<b/2;i++)
	{
		str_1[i]=a[i];
	}
//	puts(str_1);
	for(j=b-1;j>=b/2;j--)
	{
		str_2[k]=a[j];
		k++;
	}
//	puts(str_1);
//	puts(str_2);     
	d=pan(str_1,str_2,b);
	return d;	
}
int pan(char a[N],char b[N],int c)
{	
	int i;
	for(i=0;i<c/2;i++)
	{
		if(a[i]!=b[i])
		return 0;
	}
	return 1;
}
