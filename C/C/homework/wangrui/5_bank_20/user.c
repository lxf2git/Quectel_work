#include"bank.h"

extern long _user_id[N]; 
extern long _user_passwd[N]; 
extern float _user_money[N]; 
int _user_menu()
{	
	int a_user;

	printf("\n请选择:\n");

	do
	{
		printf("登录用户 -----> 0\n");
		printf("创建用户 -----> 1\n");
		scanf("%d",&a_user);
	}while((a_user!=0&&a_user!=1)&&printf("\n请重新输入:\n"));

	switch(a_user)
	{
		case 0:_id=_user_log_in();break;
		case 1:_id=_user_create();break;
		default :printf("error!0\n");exit(0);			
	}

	return _id;
}

int _user_log_in()
{
	long _input_id;
	long _input_passwd;
	int i;
	int _wor;

		printf("\n请输入用户ID:\n");	
		//核对id
		scanf("%d",&_input_id);
		for(i = 0 ; i < N ; i++)		
		{
			if(_input_id == _user_id[i])
			{
				printf("请输入密码:\n");
				scanf("%d",&_input_passwd);
				for(_wor=0;_wor<3;_wor++)
				{
					if(_input_passwd == _user_passwd[i])
					{
						_id = i;
						printf("密码正确!\n");
						return _id;
					}
					printf("密码错误！\n请重新输入:\n");
					scanf("%d",&_input_passwd);
				}
				printf("错误次数过多！\n");
				_id=0;	
				return _id;		
			}
		}
		printf("没有找到用户\n");
		_id=0;
		return _id;	
}

int _user_create()
{	
	int i,j;
	int _judge;
	long _new_id;
	long _ft_passwd,_sd_passwd;
	for(i=0;_user_id[i]!=0;i++);
	_id = i;


	printf("\n请输入新用户ID:\n");
	scanf("%d",&_new_id);
	for(j = 0; j < _id; j++)
	{
		if(_user_id[j]==_new_id)
		{
			printf("用户名重复,请重新输入:\n");
			scanf("%d",&_new_id);
			j=0;
		}
	}
	_user_id[_id]=_new_id;
	
	_judge=0;
	while(_judge==0)
	{
		printf("请设置密码:\n");
		scanf("%d",&_ft_passwd);
		printf("请确认密码:\n");
		scanf("%d",&_sd_passwd);
		if(_ft_passwd==_sd_passwd)
		{
			_judge=1;
			_user_passwd[_id]=_ft_passwd;
		}
		else
		{
			_judge=0;
		}
	}
	return _id;
}
