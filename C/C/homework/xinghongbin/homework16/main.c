#include"main.h"
int main()
{
		int a,b,c,space;
		printf("_________________input year mon____________________\n");
		scanf("%d%d",&a,&b);
//		day=deal_day(a,b);
		space=deal_week(a,b);                           //确定1号是周几
//		printf("                    ");
		display(space,deal_day(a,b));                   //显示函数
//		printf("%d",deal_day(a,b));
//		printf("%d",deal_week(a,b));
		printf("\n");                                   //最后行空格 
		return 0;
}
