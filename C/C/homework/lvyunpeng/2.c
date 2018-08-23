#include<stdio.h>
int main()
{
	int a;
	printf("请从键盘输入1～7：\n");
	scanf("%d",&a);
	switch(a)
	{
		case 7:
		printf("星期天\n");
		break;
		 case 6:
                printf("星期六\n");
                break;
		 case 5:
                printf("星期五\n");
                break;
		 case 4:
                printf("星期4\n");
                break;
		 case 3:
                printf("星期三\n");
                break;
		 case 2:
                printf("星期二\n");
                break;
		 case 1:
                printf("星期一\n");
                break;
		default:
		printf("亲，瞪大眼睛看清楚在输入！\n");
		break;


	}
			return 0;
}
