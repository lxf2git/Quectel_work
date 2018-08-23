#include<stdio.h>
int main()
{
int a;
printf("请输入数字:\n");
scanf("%d",&a);
switch(a)
    {
		case 1:printf("Monday\n");break;
		case 2:printf("Tuesday\n");break;
		case 3:printf("Wednesday\n");break;
		case 4:printf("Thursday\n");break;
		case 5:printf("Friday\n");break;
		case 6:printf("Saturday\n");break;
		case 7:printf("Sunday\n");break;
		default:printf("输入错误\n");break;

    }
return 0;
}
