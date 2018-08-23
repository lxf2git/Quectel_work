#include<stdio.h>

int main()
{	
		float money,waters=0,bottle=0,total=0;
		printf("please you have money:(unit yuan)\n");	
		scanf("%f",&money);
		if(money<0)
		{
				printf("sorry!you are poor\n ");
				return(-1);
		}


		while(money>=0.025)
		{
				waters=money;
				bottle=waters;
				money=bottle*0.5;	
				total+=bottle;
		}
		//printf("you drink total :%5.3f\n",total);
		printf("you drink total :%d\n",(int)total);
		return 0;
}



