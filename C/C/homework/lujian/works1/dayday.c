#include<stdio.h>

int main()
{
	int mode;
	printf("please input mode:form 1~7\n");
	scanf("%d",&mode);
	switch(mode)
	{
		case 1: printf("Monday\n");break;
		case 2: printf("Tuesday\n");break;
		case 3: printf("Wedesday\n");break;
		case 4: printf("Thursday\n");break;
		case 5: printf("Friday\n");break;
		case 6: printf("Saturday\n");break;
		case 7: printf("Sunday\n");break;
		default:printf("input error:please see tips\n");
	}
	return 0;
}
