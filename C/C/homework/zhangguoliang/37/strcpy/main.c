#include"main.h"
int main()
{
	char a[100];
	char b[100];
	int m,n;
	printf("输入字符串:\n");
	scanf("%s",a);
	printf("输入字符串:\n");
	scanf("%s",b);

	mystrcpy(a,b);

	printf("结果为:\n");
	
	return 0;
}
