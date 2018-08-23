#ifndef _MY_H_
#define _MY_H_

#include<stdio.h>
#include<stdlib.h>

long id;//用户的ID
int password;//用户的密码

long creat();
long generatorId();   //得到用户唯一的ID号
void showMenu();      //显示菜单
void queryMenu();     //查询菜单
void moneyMenu();     //操作金额菜单
void saveMenu();      //保存菜单
void inputMoney();    //存款
void withrawMoney();  //取款
void saveMoney();     //显示余额

int judgeId(int id,int passwd);

typedef struct USER_STRU
	{
		int id;
		int username;    //用户名
		int passwd;      //密码
		int showmoney;   //显示余额
		int addmoney;    //存款
		int withdraw;    //取钱
	}user;

#endif
