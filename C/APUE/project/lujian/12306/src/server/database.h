//非集中式数据库
//采用读写锁实现并行
//用户名，密码，订单信息
//用户名，密码，下一个用户的文件偏移量
//索引文件 用户名:密码:文件偏移量\n (数据文件)
//数据文件 结构体 包含车次和下一个元素的文件偏移量，默认0
//车次文件 车次:始发站-终点站:余票数

//#ifndef _DATA_H_
//#define _DATA_H_

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct db_user{
	char name[30];
	char passwd[20];
	unsigned long index;
};

struct db_user_info{
	char train[100];
};

typedef struct db_fd{
	FILE *db_train_po;
	int db_index_fd;
	int db_data_fd;
	pthread_rwlock_t rwlock;
}DB;

extern DB db_12306;

//打开一个数据库
int db_open();

//获取用户密码 成功返回0 未找到返回-1
int db_user_passwd(char username[30], char *passwd);

//获取车次 结尾返回0 没有返回-1
int db_train_info(char place[50], char *);

//添加用户信息 成功返回0 已存在返回-1
int db_add_user(char username[30], char passwd[20]);

//获取此用户的订单信息 成功返回1 结束返回0  没有信息返回-1
int db_user_info(char username[30], char data[1024]);

//添加订票信息
int db_add_ticket(char username[30], char train[10]);

//删除用户的订单信息 未找到返回-1
int db_del_ticket(char username[30], char train[10]);

//修改余票信息
int db_change_train(char train[10], char flag);

//获取此车次剩余车票
int db_ticket_num(char train[10]);

//获取此车次的目的地
int db_ticket_place(char train[10], char *data);

//关闭一个数据库
int db_close();

//获取此车次的目的地
int db_ticket_place(char train[10], char *data);

//#endif
