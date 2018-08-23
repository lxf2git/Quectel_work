#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void find(char *p);
int main()
{	
	char str[50];
	char *point;
	int i;
	point=str;
	printf("please input English sentence:\n");
	for(i=0;i<50;i++)
	{
		scanf("%c",point+i);
		if(*(point+i)=='.')
		{ break;}
	}
	find(point);
return 0;
}
void find(char *p)
{
	char *a[4];
	a[0]=(char *)malloc(10*sizeof(char));
	a[1]=(char *)malloc(10*sizeof(char));
	a[2]=(char *)malloc(10*sizeof(char));
	a[3]=(char *)malloc(10*sizeof(char));
	int i,j,n,max=0,l;
	int m=0;
while(*p!='\0')				//当指针指向‘\0’时结束。
{
	n=0;				// n是单词的字数。
	j=0;				// j是控制变量。
	while(*(p+j)!=32&&*(p+j)!='.')	
	{
	j++;				//控制 指针位置。
	n++; 				//计算单词的字数。
	if(n>max);			//如果单词的字数大于max；
	{
		*a='\0';			//把数组清空。
	for(i=0;i<n;i++)
		{a[0][i]=*(p+i);}	//给数组赋值。
	max=n;				//让最大单词数=n。
	m=1;				//M是存放最长单词数的数组行数。
	}
	if(n=max);			//如果单词的字数=max；
	{
	for(i=0;i<n;i++)		
		{a[m][i]=*(p+i);}	//给第M行赋值。
	m++;				//是M指向下一行。
	}
	if(n<max);			//n<max;
	continue;			//没有操作，执行下次循环。
	}
	p=p+n+1;			//使指针指向下一个单词。
}
/*	printf("%d",max);
	printf("%d",n);
	printf("%c",*p);
	printf("%d",m);*/
	for(i=0;i<m;i++)
	{
	//	for(j=0;j<n;j++)
		{printf("%s",*(a+i));} //输出字符串。

 	}
}
