#include"bank.h"

	long _user_id[N]={0};	//存放用户id
	long _user_passwd[N]={0};	//存放密码
	float _user_money[N]={0};	//存放存款

int main()
{ 
//	long _user_id[N];	//存放用户id
//	long _user_passwd[N];	//存放密码
//	float _user_money[N];	//存放存款

//	_user_id[N] = {666666};	//用户id 初始化
//	_user_passwd[N] = {666666};	//密码初始化
//	_user_money[N] = {100};	//存款初始化

	_user_id[0]=1;
	_user_passwd[0]=1;
	_user_money[0]=1;	

	_user_id[1]=123456;
	_user_passwd[1]=123456;
	_user_money[1]=100;	

	while(1)
	{	
		_id=_user_menu();
		if(_id != 0)
		{
			_show_menu(_id);
		}
	}	
	return 0;
}
