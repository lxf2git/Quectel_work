#include<stdio.h>
#include"wei_shu.h"
int main()
{
	long nu;
	int wei=0;
	printf("请输入一个数");
	scanf("%d",&nu);
	do
	  {  /*     wei=wei_shu(nu);*/
	  	nu=nu/10;
		wei++;
	}while(nu!=0);
	printf("此数有%d位",wei);
}
