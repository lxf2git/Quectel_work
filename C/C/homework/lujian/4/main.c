/*********************************************************
 * 万年历演示：
 * 输入 年月 显示 日历
 * 输入“enter”；
 * 查看下一个月的日历
 * 输入“b”；
 * 退出
 * *******************************************************/
#include "main.h"

int main()
{	
		input_year_month();
		for (;;year++)
		{
				for(;month<=12;month++)
				{
						if(ch=='\n')
								count_xingqiji(year, month);
						ch=getchar();

						if(ch=='b')
							exit(0);
				}
				month=1;
		}
}

char input_year_month()
{
		printf("please input year, month\n");
		scanf("%d%d",&year,&month);
		ch=getchar();
		return ch;
}
