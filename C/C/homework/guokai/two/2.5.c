#include<stdio.h>
int main()
{
		int mai,zong,qian;
        /*
		printf("你有多少钱\n");
	    scanf("%d",&qian);
		zong=2*qian-1;						
		printf("最多可以买%d瓶汽水\n",zong); 
	*/
        zong=0;
		for(qian=1;qian<=20;qian++)
		{
				zong++;
				if(zong%2==0)
						zong++;
		}
printf("能喝%d瓶汽水\n",zong);
return 0;
}		
