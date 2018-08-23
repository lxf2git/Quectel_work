#include"yueshu.h"
void yueshu(int i)
{
	int j,t;
	t=0;
	if(i<501&&i>99)
		{
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{	
						printf("%d  ",j);
						t++;
				}
			}

		}
	else
	{
		printf("请输入100～500之间的正整数\n");
		main();
	}
	printf("有约数：%d\n",t);
}
