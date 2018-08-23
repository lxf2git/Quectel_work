#include<stdio.h>
int main() 
{
	int d;
	printf("请输入1~7之间的数字");
	scanf("%d",&d);
	switch(d)
{	
		case 1:
               printf("Monday\n");
		break;
		case 2:
               printf("Tuesday\n");
		break;
		case 3:
               printf("Wednesday\n");
		break;
		case 4:
               printf("Thursday\n");
		break;
		case 5:
               printf("Friday\n");
		break;
		case 6:
               printf("Saturday\n");
		break;
		case 7:
               printf("Sunday\n");
		break;
		default:
		printf("输入错误\n");
}
		return 0;
}

		
