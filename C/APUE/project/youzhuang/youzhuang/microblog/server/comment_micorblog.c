#include "../apue.h"
#include "../microblog.h"
#include "init.h"
void *Comment_micorblog(int confd,struct comment *comment, PUser_info s_data,PMicroblog blog)//comment 查看的微波评论头节点  s_data 查找的用户
{
		printf("微博评论\n");
		int ret;
		PComment s_node = comment ->next;
		while(s_node!=comment)
		{
				int len;
				len = strlen(s_node->s_text)+1;
				write(confd,&len,sizeof(int));
				write(confd,s_node->s_text,len);//发送微博评论
				printf("%s\n",s_node->s_text);
				write(confd,s_node->s_nick_name,20);//发送用户名
				printf("%s\n",s_node->s_nick_name);
				s_node = s_node->next;
		}
		ret = 0;
		write(confd,&ret,sizeof(ret));//发完通知
		read(confd,&ret,sizeof(int));
		switch(ret)
		{
				case 1:
						send_com(confd, s_data, comment);
						break;
				case 2:
						Forwar_microblog(confd, blog);
						break;
				case 3:
						Add_praise(confd, &blog->s_praise);
						break;
				case 4:
						Del_comment(confd, s_data, blog);
						break;;

		}


}

void *send_com(int confd, PUser_info s_data, PComment comment)
{
		char user_name[20];
		int ret;
		PComment com=NULL;
		com = (PComment)malloc(sizeof(SComment));
		if(NULL == com)
		{
				printf("com err!");
				return;
		}
		com->next = com;
		com->prev = com;

		int len;
		printf("评论微博\n");
		read(confd, com->s_nick_name, 20);
		printf("name:%s\n",com->s_nick_name);
		read(confd,&len,sizeof(int));
		printf("评论长度:%d\n",len);
		com->s_text = (char *)malloc(len);

		read(confd,com->s_text,len);

		printf("评论内容:%s\n",com->s_text);
		ret = add_back_comm(comment,com);
		write(confd, &ret, sizeof(int));
}
