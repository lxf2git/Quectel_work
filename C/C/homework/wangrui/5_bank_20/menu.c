#include"bank.h"

extern long _user_id[N]; 
extern long _user_passwd[N]; 
extern float _user_money[N]; 

void _show_menu(int _id)
{
	int _choose_menu;

	printf("\n请选择操作:\n");

	do
	{
		printf("存款 -----> 1\n");
		printf("取款 -----> 2\n");
		printf("查询 -----> 3\n");
		printf("退出 -----> 0\n");
		scanf("%d",&_choose_menu);
	}while((_choose_menu<0&&_choose_menu>3)&&printf("\n请重新选择:\n"));
	
	switch(_choose_menu)
	{
		case 1:_save_menu(_id);break;
		case 2:_withdraw_menu(_id);break;
		case 3:_query_menu(_id);break;
//		case 0:	   
	}
}

void _save_menu(int _id)
{
	int _continue_s;
	float _save_money;
	_continue_s=1;
	while(_continue_s == 1)
	{
		printf("\n请输入存储金额: ");
		scanf("%f",&_save_money);
		_user_money[_id]+=_save_money;
		printf("是否继续存款：\n");
		do
		{
			printf("否 -----> 0\n");
			printf("是 -----> 1\n");
			scanf("%d",&_continue_s);
		}while((_continue_s!=0&&_continue_s!=1)&&printf("出错,请重新输入\n"));
		if(_continue_s==0)
		{
			_show_menu(_id);
		}
	}	
}


void _withdraw_menu(int _id)
{
	int _continue_w;
	float _withdraw_money;
	_continue_w=1;
	while(_continue_w == 1)
	{
		printf("\n请输入取款金额: ");
		scanf("%f",&_withdraw_money);
		if(_withdraw_money<=(_user_money[_id]-10))
		{
			_user_money[_id]-=_withdraw_money;
			printf("是否继续取款：\n");
			do
			{
				printf("否 -----> 0\n");
				printf("是 -----> 1\n");
				scanf("%d",&_continue_w);
			}while((_continue_w!=0&&_continue_w!=1)&&printf("出错,请重新输入\n"));
			if(_continue_w==0)
			{
				_show_menu(_id);
			}
		}
		else
		{
			printf("您的余额不足!\n");
		}
	}	
}

void _query_menu(int _id)
{
	int _back;
	printf("\n您的ID:%d\n",_user_id[_id]);
	printf("您的余额:%f\n",_user_money[_id]);
	printf("退出 -----> 0\n");
	while(_back!=0)
	{
		scanf("%d",&_back);
		if(_back==0)
		{
			_show_menu(_id);
		}
		printf("出错,请重新输入\n");
	}
}

