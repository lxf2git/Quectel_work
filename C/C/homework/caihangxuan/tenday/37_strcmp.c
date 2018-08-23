#include<stdio.h> 
#include<string.h> 

int _strcmp(char dest[],char src[])
{
	int bit,size_d,size_s,test;
	size_d=strlen(dest);
	size_s=strlen(src);
	if(size_s<size_d)
		size_d=size_s;
	printf("长度：%d\n",size_d);
	for(bit=0;bit<size_d;bit++)
	{
		if(dest[bit]==src[bit])
		     	test=0;
		if(dest[bit]<src[bit])
		{
		     	test=-1;
			break;
		}
		if(dest[bit]>src[bit])
		{
		     	test=1;
			break;
		}
	}
	return test;
}
int main()
{	
	int returntr;
	char a[100]={0},b[100]={0};
	printf("请输入第一个字符串:");
	scanf("%s",a);
	printf("请输入第二个字符串:");
	scanf("%s",b);
	returntr=_strcmp(a,b);
	printf("%d\n",returntr);
}
