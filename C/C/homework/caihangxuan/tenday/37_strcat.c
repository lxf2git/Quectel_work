#include<stdio.h> 
#include<string.h> 
char *_strcat(char dest[],char src[])
{
	int size_d,size_s,nu;
	size_d=strlen(dest);
	size_s=strlen(src);
	for(nu=0;nu<size_s;nu++)//把源字符串粘到目标字符串结束位置
	{
		dest[size_d++]=src[nu];
	}
	char *test=dest;
//	printf("%s\n",dest);
	return test;
}
int main()
{	
	char *point;
	char a[100]={0},b[100]={0};
	printf("请输入第一个字符串:");
	scanf("%s",a);
	printf("请输入第二个字符串:");
	scanf("%s",b);
	point=_strcat(a,b);
	printf("%s\n",point);
}
