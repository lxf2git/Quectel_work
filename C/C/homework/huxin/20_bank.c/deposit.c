#include"main.h"
int deposit()
{ 
 	int a;
	extern int ba;
	printf("please input your money \n "); //请输入存款额
	scanf("%d",&a);
	printf("you deposit money is $%d\n",a); //你的存款额是
	ba=ba+a;
	return (a);
}
