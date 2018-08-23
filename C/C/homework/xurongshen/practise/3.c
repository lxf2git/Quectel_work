#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 100
void change(int  num);
int main()
{
	char ch;
	int m,n;
	/***************************
	printf("请输入字符:");
	scanf("%c",&ch);
	printf("请打印的行数:");
	scanf("%d",&m);
	*************************/
	printf("请输入:");
	scanf("%d",&n);

	change(n);
	return 0;
}

void change( int  num)
{
	int i,j;
	int arr[N];
	printf("num:%d\n",num);
	for(i=0;i<N;i++)
	{
		if(num>0)
		{
				/************8
		for(j=0;j<low;j++)
		{
			printf("%c",ch);
		}
		printf("\n");
		***************************/
			arr[i] = num%2;
//			printf("arr[%d]:%d\n",i,arr[i]);
			num = num/2;
//	printf("num:%d\n",num);
		}
			if((num == 0)&&(num%2 == 0))
			{
				arr[i+1]='\0';
				break;
			}
	}
//	j=strlen(arr);
//	/*

	for(;i>=0;i--)
	{
//		if(arr[i] == 3)
//			break;
		printf("%d",arr[i]);
	}
	printf("\n");
}
