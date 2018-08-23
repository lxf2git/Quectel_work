#include<stdio.h>
int main()
{	
	int a,c;
	char b;
	printf("输入你要计算的公式：\n");
	scanf("%d%c%d",&a,&b,&c);
	switch(b)
		{
		case '+': printf("%d+%d=%d",a,c,a+c);
			break;
		case '-': printf("%d-%d=%d",a,c,a-c);
			break;
		case '*': printf("%d*%d=%d",a,c,a*c);
			break;
		case '/': printf("%d/%d=%d",a,c,a/c);
			break;
		}
		
	return 0;

}
