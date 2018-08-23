#include"main.h"

void service(int sig)
{
	int ret;
	int fd = open("login.txt", O_WRONLY);
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		p->online = -1;
		write(fd, p, sizeof(sRed));
		ser_fun(p);
	}
	close(fd);
	puts("hehe");
	pool_destroy();
	printf("成功\n");
	exit(0);
}

void ser_fun(pRed p)
{
	int ret = 0;
	ret = chdir(p->usr_msg.usr_id);
	if(ret < 0)
	{
		mkdir(p->usr_msg.usr_id, 0777);
		chdir(p->usr_msg.usr_id);
	}

	int fd_fans = open("fans.txt", O_CREAT|O_WRONLY, 0777);
	pFan pfan = NULL;
	for(pfan = p->fans_list->next; pfan !=  p->fans_list; pfan = pfan->next)
	{
		write(fd_fans, pfan, sizeof(sFan));
	}
	close(fd_fans);

	int fd_fri = open("friend.txt", O_CREAT|O_WRONLY, 0777);
	pFri pfri = NULL;
	for(pfri = p->fri_list->next; pfri != p->fri_list; 
					pfri = pfri->next)
	{
		write(fd_fans, pfri, sizeof(sFri));
	}
	close(fd_fri);

	int fd_web = open("web.txt", O_CREAT|O_WRONLY, 0777);
	pWeb pweb = NULL;
	for(pweb = p->web_list->next; pweb != p->web_list; pweb = pweb->next)
	{
		write(fd_web, pweb, sizeof(sWeb));
	}
	close(fd_web);

	chdir("../");
}
