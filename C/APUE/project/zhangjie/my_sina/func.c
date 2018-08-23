#include"main.h"

int func(int confd, sCts buf, int line)
{
	int err;
	switch(buf.type)
	{
		case REGISTER://注册
	//		printf("dsa\n");
			err = reg_fun(confd, buf);
			if(err == 0)
			{
				int yes;
				read(confd, &yes, sizeof(int));
				if(yes == 0)
				{
					printf("直接登录\n");
					line = log_fun(confd, buf);
					printf("line:%d\n", line);
				}
				else
				{
					yes = -1;
					write(confd, &yes, sizeof(int));
				}
			}
			break;
		case LOGIN://登录
			log_fun(confd, buf);
			break;
		case SEARCH://搜查
			search(confd, buf);
			break;
		case CONCERN://关注
			concern(confd, buf);
			break;
		case NOT_CONCERN://取消关注
			unconcern(confd, buf);
			break;
		case PUBLISH://发表
			pub_web(confd, buf);
			break;
		case VIEW_BLOG://查看微波
			view_web(confd, buf);
			break;
		case VIEW_FRI://查看朋友
			view_friend(confd, buf);
			break;
		case VIEW_FAN://查看粉丝
			view_fans(confd, buf);
			break;
		case QUIT_V:
			if(strcmp(buf.usr_nam, buf.exe_fun.search_usr_name) != 0)
			{
				printf("haha\n");
				last(confd, buf);
			}
			break;
		case QUIT_S://退出微博
			quit(confd, buf);
			break;
		default:
			err = 10;
			write(confd, &err, sizeof(int));
			break;
	}
	return 0;
}

void init_red(pRed *p)
{
	creat_memory((void **)p, sizeof(sRed));
	(*p)->online = -1;
	(*p)->concern_num = 0;
	(*p)->friend_num = 0;
	(*p)->publish_num = 0;
	init_fans(&(*p)->fans_list);
	init_friend(&(*p)->fri_list);
	init_web(&(*p)->web_list);
	(*p)->prev = *p;
	(*p)->next = *p;
}

void init_fans(pFan *p)
{
		creat_memory((void **)p, sizeof(sFan));
		(*p)->prev = *p;
		(*p)->next = *p;
}

void init_friend(pFri *p)
{
		creat_memory((void **)p, sizeof(sFri));
		(*p)->prev = *p;
		(*p)->next = *p;
}

void init_web(pWeb *p)
{
		creat_memory((void **)p, sizeof(sWeb));
		(*p)->praise = 0;
		(*p)->com_num =0;
		(*p)->prev = *p;
		(*p)->next = *p;
}

