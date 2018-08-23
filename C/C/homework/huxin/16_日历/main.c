#include"main.h"
int main()
{
	int year,month,space,day;
	printf("please input year month :\n");//输入年月
	scanf("%d/%d",&year,&month);
	day=judge_mon(year,month);        //判断这月多少天
	space=judge_space(year,month);    //判断这月第一天星期几  
	display(space,day);                //显示
    printf("\n");
	return 0;
}
