#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void malloc_(void **p, int length)
{
	*p = (void *)malloc(length);

}

void zhuan(char *parr[0],int length, int n)
{
	int a;
	for(a = n;a < length;a++)
	{
		*(parr[2] + a - n)= *(parr[0] + a);
	}


}

int main()
{
	char *parr[3];   //定义一个指针数组
	int length;
	int n;
	malloc_((void **)&parr[0],100);
	printf("请输入一个字符串");
	scanf("%s",parr[0]);
	length = strlen(parr[0]);//求字符串的长度
	malloc_((void **)&parr[1],length);
	malloc_((void **)&parr[2],length);
	printf("输入要转换的长度");
	do
	{
	scanf("%d",&n);
	}while((n < 0 || n > length) && printf("超出范围，请重新输入转换长度\n"));

	strcpy(parr[1],parr[0]);
	*(parr[1] + n) = '\0';
	zhuan(&parr[0],length,n);
	strcat(parr[2],parr[1]);
	printf("转换前     %s\n",parr[0]);
	printf("移动%d个字母%s\n",n,parr[2]);
}
