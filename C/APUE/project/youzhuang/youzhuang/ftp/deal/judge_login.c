/*编译时需要添加库函数 -lcrypt*/
#define _XOPEN_SOURCE
#include"ftp.h"
#include<string.h>
#include<shadow.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
void get_salt(char *salt,char *passwd)
{
		int i,j;
		for(i=0,j=0;passwd[i]!='\0',j<3;i++)
		{
				if(passwd[i]=='$')
						j++;
		}
		strncpy(salt,passwd,i);
}	
int judge_login(char *user,char *passwd)
{
		/*
		接受输入的用户帐号
		if(receive_course(user)!=0)
		{
			printf("传输用户帐号失败!\n");
			return fail;
		}
		接受输入的用户密码
		if(receive_course(passwd)!=0)
		{
		printf("传输用户密码失败!\n");
		return fail;
		}*/

		//定义结构体，获取用户加密密码
		struct spwd *shp;
		if((shp=getspnam(user))==NULL)
		{
				printf("用户帐号验证失败!\n");
				return FAIL;
		}
		//获取加密密码salt
		char salt[13];
		memset(salt,0,sizeof(salt));
		get_salt(salt,shp->sp_pwdp);
		//验证输入密码是否正确
		if(strcmp(shp->sp_pwdp,crypt(passwd,salt))!=0)
		{
				printf("密码错误!\n");
				return FAIL;
		}
		printf("密码正确!\n");
		return SUC;
}
