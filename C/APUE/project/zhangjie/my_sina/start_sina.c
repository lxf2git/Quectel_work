#include"main.h"

int start_sina()
{
	int ret;
	int fd = open("login.txt", O_RDONLY);
	pRed pnew = NULL;
	while(1)
	{
		init_red(&pnew);
		ret = read(fd, pnew, sizeof(sRed));
		if(ret == 0)
		{
			break;
		}
		printf("*\n");
		start_fun(pnew);
		insert_red(phead, pnew);
	}
	puts("开启成功");
	close(fd);
	return 0;
}

int start_fun(pRed pnew)
{
	int ret;
	chdir(pnew->usr_msg.usr_id);
	int fd_fans = open("fans.txt", O_RDONLY);
	init_fans(&pnew->fans_list);
	init_friend(&pnew->fri_list);
	init_web(&pnew->web_list);

	pnew->fans_list->next = pnew->fans_list;
	pnew->fans_list->prev = pnew->fans_list;
	pFan pfan = NULL;
	while(1)
	{
		init_fans(&pfan);
		ret = read(fd_fans, pfan, sizeof(sFan));
		if(ret == 0)
		{
			break;
		}
		puts("1");
		insert_fans(pnew->fans_list, pfan);
	}
	close(fd_fans);

	int fd_fri = open("friend.txt", O_RDONLY);
	pnew->fri_list->next = pnew->fri_list;
	pnew->fri_list->prev = pnew->fri_list;
	pFri pfri = NULL;	
	while(1)
	{
		init_friend(&pfri);
		ret = read(fd_fri, pfri, sizeof(sFri));
		if(ret == 0)
		{
			break;
		}
		puts("2");
		insert_friend(pnew->fri_list, pfri);
	}
	close(fd_fri);

	int fd_web = open("web.txt", O_RDONLY);
	pnew->web_list->next = pnew->web_list;
	pnew->web_list->prev = pnew->web_list;
	pWeb pweb = NULL;
	while(1)
	{
		init_web(&pweb);
		ret = read(fd_web, pweb, sizeof(sWeb));
		if(ret == 0)
		{
			break;
		}
		puts("3");
		insert_web(pnew->web_list, pweb);
	}
	close(fd_web);

	chdir("../");
}
