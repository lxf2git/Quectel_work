#include<stdio.h>
int main()
{ 
		int hour,minute,second;
		float	a=0;
		printf("请输入小时 分钟 秒\n");
		scanf("%d%d%d",&hour,&minute,&second);
		if(hour>24||hour<0)
		{
				printf("小时错误");
		}
		else if(minute>60||minute<0)
				{
						printf("分钟错误") ;
				}
	    else if(second>60||second<0)
		        {
						printf("秒错误");
				}	
		else
		{
		a=(hour*60)+minute+(second/60.0);
		printf("%f",a);
		}

		return 0;

}
