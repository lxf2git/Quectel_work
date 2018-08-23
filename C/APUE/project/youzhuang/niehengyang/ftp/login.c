#include "main.h"



int login()
{
	char username[50];
	char passwd[50];
	printf("请输入用户名\n");
	scanf("%s",username);
	printf("请输入密码\n");
	scanf("%s",&passwd);
	printf("username:%s passwd:%s",username,passwd);
	//judge_login(username,passwd);
	
}
