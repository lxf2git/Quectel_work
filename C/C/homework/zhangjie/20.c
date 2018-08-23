#include"main.h"

int main()
{
	char i;
	printf("是否创建帐号?y/n\n");
	scanf("%c",&i);
	if(i==121)
	{
		creat();
		showMenu();
	}
	else
	{
		input();	
	}
	return 0;
}
