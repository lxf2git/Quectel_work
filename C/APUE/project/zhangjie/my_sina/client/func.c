#include"client.h"

int search(int sockfd, sCts buf)
{
	int suc = -1;
	sRed msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		read(sockfd, &msg, sizeof(msg));
		printf("用户名：%s\n粉丝：%d 好友：%d 微博：%d\n",
		msg.usr_msg.usr_nam, msg.concern_num,
		msg.friend_num, msg.publish_num);
		return suc;
	}
	return suc;
}

int pub_web(int sockfd, sCts buf)
{
	int suc = -1;
	printf("请输入你要发表的内容\n");
	scanf("%s", buf.exe_fun.web_content);
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(suc));
	if(suc == 0)
	{
		printf("发表成功\n");
	}
	else
	{
		printf("发表失败\n");
	}
	return suc;
}

int concern(int sockfd, sCts buf)
{
	int suc = -1;
	printf("请输入你要关注的用户名\n");
	scanf("%s", buf.exe_fun.concern_usr_name);	
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(suc));
	if(suc == 0)
	{
		printf("关注成功\n");
	}
	else
	{
		printf("关注失败\n");
	}
	return suc;
}

int unconcern(int sockfd, sCts buf)
{
	int suc = -1;
	printf("请输入你要关注的用户名\n");
	scanf("%s", buf.exe_fun.concern_usr_name);	
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(suc));
	if(suc == 0)
	{
		printf("取消成功\n");
	}
	else
	{
		printf("取消失败\n");
	}
	return suc;
}

int friend_list(int sockfd, sCts buf)
{
	int suc = -1;
	sFri msg;
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	printf("朋友数%d\n", suc);
	if(suc != -1)
	{
		int i;
		for(i = 0; i < suc; i++)
		{
			bzero(&msg, sizeof(msg));
			int ret = read(sockfd, &msg, sizeof(msg));
			if(ret <= 0)
			{
				continue;
			}
			printf("%s\n", msg.usr_nam);
		}
	}
	return suc;
}

int fans_list(int sockfd, sCts buf)
{
	int suc = -1;
	sFan msg;
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	printf("粉丝数%d\n", suc);
	if(suc != -1)
	{
		int i;
		for(i = 0; i < suc; i++)
		{
			bzero(&msg, sizeof(msg));
			int ret = read(sockfd, &msg, sizeof(msg));
			if(ret <= 0)
			{
				continue;
			}
			printf("%s\n", msg.usr_nam);
		}
	}
	return suc;
}

int last(int sockfd, sCts buf)
{
	int suc = -1;
	sRed msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		read(sockfd, &msg, sizeof(msg));
		printf("用户名：%s\n粉丝：%d 好友：%d 微博：%d\n",
		msg.usr_msg.usr_nam, msg.concern_num,
		msg.friend_num, msg.publish_num);
	}
	return suc;
}

int quit_s(int sockfd, sCts buf)
{
	int suc = -1;
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		printf("成功退出\n");
	}
	return suc;
}

int view_web(int sockfd, sCts buf)
{
	int suc = -1, i;
	sWeb msg;
	char self_nam[30] = {'\0'};//记录自己是谁
	char fri_nam[30] = {'\0'};//记录是谁的用户界面，用于判断可以执行哪些操作
	strcpy(self_nam, buf.usr_nam);
	strcpy(fri_nam, buf.exe_fun.search_usr_name);
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == -1)
	{
		printf("查看错误\n");
		return suc;
	}
	
	read(sockfd, &msg, sizeof(msg));
	printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
	for(i = 0; i < msg.com_num; i++)
	{
		printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
	}
	int self = -1;//判断是不是自己的微博
	if(strcmp(buf.usr_nam, buf.exe_fun.search_usr_name) == 0)
	{
		self = 0;
	}
	sCts web_buf;
	while(1)
	{
		bzero(&web_buf, sizeof(web_buf));
		strcpy(web_buf.usr_nam, self_nam);
		strcpy(web_buf.exe_fun.search_usr_name, self_nam);
		printf("请选择功能：\n");
		if(self == -1)//不是本人微博
		{
			printf("9 ：转发\n");
			printf("10：评论\n");
			printf("11：加赞\n");
		}
		if(self == 0)//本人微博
		{
			printf("12：删除\n");
		}
		printf("13：下一页\n");
		printf("14：上一页\n");
		printf("15：退出浏览\n");
		scanf("%d", &web_buf.type);
		switch(web_buf.type)
		{
			case FORWARDING://转发
					forward(sockfd, web_buf);
					break;
			case COMMENT://评论
					comment(sockfd, web_buf);
					break;
			case PRAISE://加赞
					praise(sockfd, web_buf);
					break;
			case DELETE://删除
					delete_(sockfd, web_buf);
					break;
			case PAGEUP://上一页
					page(sockfd, web_buf);
					break;
			case PAGEDOWN://下一页
					page(sockfd, web_buf);
					break;
			case QUIT_V://返回到上一界面
					write(sockfd, &web_buf, sizeof(buf));
					return 0;
			default:
					break;
		}
	}
}
