
#include<stdio.h>

int main()
{	
		int  money,waters=0,bottle=0,total=0;
		printf("please you have money:(unit yuan)\n");	
		scanf("%d",&money);
		if(money<0)
		{
				printf("sorry!you are poor\n ");
				return(-1);
		}

       	money=money*10;
		while(money>=10)
		{
				waters=money/10;
				if(money%10==5)
					waters++;
				bottle=waters;
				money=bottle*5;	
				total+=bottle;
		}
		//printf("you drink total :%5.3f\n",total);
		printf("you drink total :%d\n",total);
		return 0;
}



