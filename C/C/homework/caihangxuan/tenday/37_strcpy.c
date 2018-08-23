#include<stdio.h> 
char _strcpy(char dest[],char src[])
{
	char *point=src;
	dest=point;
	printf("%s\n",dest);
}
int main()
{	
	char a[100]={0},b[100]={0};
	printf("请输入第一个字符串:");
	scanf("%s",a);
	printf("请输入第二个字符串:");
	scanf("%s",b);
	_strcpy(a,b);
}
