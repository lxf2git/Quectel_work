#include"client.h"

int forward(int sockfd, sCts buf)
{
	int suc = -1, i;
	sWeb msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		printf("转发成功\n");
		read(sockfd, &msg, sizeof(msg));
		printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
		for(i = 0; i < msg.com_num; i++)
		{   
			printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
		}   

	}
	else
	{
		printf("转发失败\n");
	}
	return suc;
}

int comment(int sockfd, sCts buf)
{
	int suc = -1, i;
	printf("请输入评论内容\n");
	sWeb msg;
	bzero(&msg, sizeof(msg));
	scanf("%s", buf.exe_fun.comment_content);
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		printf("评论成功\n");
		read(sockfd, &msg, sizeof(msg));
		printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
		for(i = 0; i < msg.com_num; i++)
		{   
			printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
		}   
	}
	else
	{
		puts("评论失败\n");
	}
	return suc;
}

int delete_(int sockfd, sCts buf)
{
	int num = 0, i;
	sWeb msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &num, sizeof(int));
	printf("%d\n", num);
	printf("删除成功\n");
	if(num >= 2)
	{
		read(sockfd, &msg, sizeof(msg));
		printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
		for(i = 0; i < msg.com_num; i++)
		{   
			printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
		}   
	}
	if(num == 1)
	{
		printf("没有微博了\n");
	}
	return 0;
}


int praise(int sockfd, sCts buf)
{
	int i;
	sWeb msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &msg, sizeof(msg));
	printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
	for(i = 0; i < msg.com_num; i++)
	{
		printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
	}  
   	return 0;	
}

int page(int sockfd, sCts buf)
{
	int suc = -1, i;
	sWeb msg;
	bzero(&msg, sizeof(msg));
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	if(suc == 0)
	{
		read(sockfd, &msg, sizeof(msg));
		printf("%s:%s\n获得%d个赞\n", buf.usr_nam, msg.content, msg.praise);
		for(i = 0; i < msg.com_num; i++)
		{
			printf("%s:%s\n", msg.com[i].com_nam, msg.com[i].com);
		}
	}
	return suc;
}
