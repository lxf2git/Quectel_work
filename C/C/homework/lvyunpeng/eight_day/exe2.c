#include<stdio.h>
#define swap(m) if(m>=97){m=m;} else{m=m+32;}
int main()
{
	char a,m;
	printf("输入一个大写字符:");
	scanf("%c",&a);
	swap(a);
	printf("%c\n",a);
	return 0;


}
