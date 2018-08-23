#include"bit.h"
int bit()
{

	int a,i;
	printf("请输入一个正数：\n");
	scanf("%d",&a);
	for(i=0;;)
	{
		i++;
		
         	if(a/10==0)
		{	
			printf("是个%d位数！\n",i);
			return 0;
		}
		 else
		{
			//printf("%d\n",i);
		}
			a=a/10;
	}
		return 0;



}
