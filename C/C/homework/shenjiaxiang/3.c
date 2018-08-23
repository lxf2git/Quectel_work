#include<stdio.h>

int main()
{
	int a;
	printf("input int:\n");
	scanf("%d",&a);	
	switch(a)
	{
		case 1:
				printf("monday\n");
				break;//跳出switch语句
		case 2:
				printf("tuesday\n");
				break;
		case 3:
				printf("wednesday\n");
				break;
		case 4:
                                printf("thursday\n");
                                break;
		case 5:
                                printf("friday\n");
                                break;
		case 6:
                                printf("saturday\n");
                                break;
		case 7:
                                printf("sunday\n");
                                break;
		default:
				printf("输入出错\n");
				break;
	}
	return 0;
}

