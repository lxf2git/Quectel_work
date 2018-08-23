#include"div.h"
int div()
{

	int a,i,t=0,sum=0;
	printf("请输入100～500之间的整数：");
	scanf("%d",&a);
	for(i=2;i<a;i++)
	{	
		
		if(a%i==0)
		{
			sum+=i;
			t++;
			printf("%d ",i);
		}
		else
		{
			
		}


	}
			printf("\n");
			printf("约数的个数:%d \n",t);
			printf("约束和:%d \n",sum);
			return 0;


}
