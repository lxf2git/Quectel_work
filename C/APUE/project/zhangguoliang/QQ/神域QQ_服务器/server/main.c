#include "../include/apue.h"
int main()
{
	init_chain(&phead);//这个链用来存已登录的用户
	
	tcp_connect();//开启服务器，准备接收客户机请求
	//循环5个线程，不断处理多个个电脑发来的信息
	
	pool_init(MAX_THREAD);//初始化线程池
	
	epfd = epoll_create(MAX_MONT);//准备监听文件描述符
	
	epoll_body();//监听本体
}

