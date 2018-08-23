#ifndef _BANK_H_
#define _BANK_H_
#define N 50
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int _id;
//long _user_id[N];	//存放用户id
//long _user_passwd[N];	//存放密码
//float _user_money[N];	//存放存款

int _user_menu();
int _user_log_in();
int _user_create();

void _show_menu(int);
void _save_menu(int);
void _withdraw_menu(int);
void _query_menu(int);

#endif
