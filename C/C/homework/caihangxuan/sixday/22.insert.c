#include<stdio.h>
#include<string.h> 
int main()
{
	int i,n,size;
	char a[500]={" "};
	char charc;
	printf("请输入插入的字符");
	scanf("%c",&charc);
	printf("%c",charc);
	printf("请输入排序字符串");
	scanf("%s",a);
	size=(int)strlen(a);
	a[size]=charc;
	i=size;
	for(n=0;n<100;n++)
	{
		size=i;
		for(;size>=0;size--)
		{
			if(a[size]<a[size-1])
			{
				charc=a[size];
				a[size]=a[size-1];
				a[size-1]=charc; 
			}
		}
	}
	printf("%s\n",a);
}
