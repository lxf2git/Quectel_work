#include"./weishu.h"


void weishu()
{
	int a;
	printf("输入最大位数：10位\n");
	int n=1;
	printf("请输入数字：\n");
	scanf("%d",&a);
    while(a!=0)
	{
		a=a/10;
		if(a!=0)
		{
		
			n+=1;
		}
				
	}
		printf("你输入的是%d位数\n",n);
	
		
}
