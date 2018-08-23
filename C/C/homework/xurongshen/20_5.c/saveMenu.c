#include"my.h"

void saveMenu()
{
	printf("这是保存菜单界面\n");
	printf("是否退出菜单界面(1：退出  0：回到主菜单)\n");
	int i;
	scanf("%d",&i);
	switch(i)
	{
		case 1: {exit(0);break;}
		case 0:{showMenu();break;}
	}	
}
