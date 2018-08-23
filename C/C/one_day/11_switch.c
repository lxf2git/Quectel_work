#include<stdio.h>

int main()
{
	int a;
	printf("input int:\n");
	scanf("%d",&a);	
	switch(a)
	{
		case 1:
				printf("a=1\n");
				break;//跳出switch语句
		case 2:
				printf("a=2\n");
				break;
		case 3:
				printf("a=3\n");
				break;
		default:
				printf("a!=1~3\n");
				break;
	}
	return 0;
}
