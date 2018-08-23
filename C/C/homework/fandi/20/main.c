#include"main.h"



int main()
{	
	long id;
	int i,ch,password=0,fp=0,fi=0;
	long id_1=555555;
	long id_2=666666;
	long id_3=777777;
	int password_1=111111;
	int password_2=222222;
	int password_3=333333;
	int money1=10,money2=10,money3=10;
	printf("input id:\n");
	for(;;)
	{
			scanf("%d",&id);
	if((id!=id_1)&&(id!=id_2)&&(id!=id_3))
	{
		printf("ID输入有误\n");
		fi+=1;
	}
		else
				break;
		if(fi==3)
		{
				printf("您今天ID错误次数已达上限\n");
				return 0;
		}
	}
	for(;;)
	{
			printf("input password:\n");
			scanf("%d",&password);
	if((password!=password_1)&&(password!=password_2)&&(password!=password_3))
	{
		printf("PASSWORD输入有误\n");
		fp+=1;
	}
		if(id==id_1&&password==password_1||id==id_2&&password==password_2||id==id_3&&password==password_3)
		{
				break;
		}
		else
		{
				printf("PASSWORD输入有误\n");
				fp+=1;
		}
		if(fp==3)
		{
				printf("您今天密码输入错误次数已达上限\n");
				return 0;
		}
	}
	printf("1-------------创建账户\n");
	printf("2-------------存款\n");
	printf("3-------------取钱\n");
	printf("4-------------查询\n");
	printf("5-------------退出\n");
	printf("请选择功能:\n");
	scanf("%d",&ch);
	switch(ch)
	{
			//case 1:
			//	creatMenu();
			//	break;
			case 2:
				if(id==id_1)
				money1=saveMenu(money1);
				if(id==id_2)
				money2=saveMenu(money2);
				if(id==id_3)
				money3=saveMenu(money3);
				break;
			case 3:
				if(id==id_1)
				money1=withdrawMenu(money1);
				if(id==id_2)
				money2=withdrawMenu(money2);
				if(id==id_3)
				money3=withdrawMenu(money3);
				break;
			case 4:
				if(id==id_1)
				queryMenu(money1);
				if(id==id_2)
				queryMenu(money2);
				if(id==id_3)
				queryMenu(money3);
				break;
			case 5:
				return 0;
	}
	return 0;
}
