#include "../include/apue.h"
//pchain find_addr(int);
void *deal_command(void *p)
{
	int nowfd;
	nowfd = *((int*)p);
	creat_main_tran buf;
	bzero(&buf,sizeof(buf));
	read(nowfd,&buf,sizeof(buf));
	switch(buf.flag)
	{
			case QUIT_CON:
					quit_con(nowfd);
					break;
			case APPLY:
					qq_apply(nowfd,buf.apply_info);
					break;
			case LOGIN:
					qq_login(nowfd,buf.login_info);//主界面的三个功能
					break;
			case FDPWD:
					found_pwd(nowfd,buf.found_info);
					break;
			case SHOWF:
					friend_list(nowfd);
					break;
			case CHINFO:
					change_info(nowfd,buf.apply_info);
					break;
			case CHQQ:
					log_off(nowfd);
					break;
			case ADDFD:
					add_friend(nowfd,buf.login_info.id);
					break;
			case DELFD:
					delet_friend(nowfd,buf.login_info.id);
					break;
			case FTALK:
					talk_friend(nowfd,buf.login_info.id);
					break;
			case SHOWFT:
					fri_info(nowfd,buf.myinfo.id);
					break;
			case SENDFILE:
					send_file_on(nowfd,buf.myinfo.id);
					break;
			case LXSENDF:
					send_file_off(nowfd,buf.myinfo.id);
					break;
			case LXSENDM:
					send_message_off(nowfd,buf.myinfo.id);
					break;
			default:
					printf("收到了一个未知标记\n");
					break;
	}
}
pchain find_addr(int nowfd)
{
		pchain tmp = phead->next;
		while(tmp!=NULL)
		{
			if(tmp->confd==nowfd)
				return tmp;
			tmp=tmp->next;
		}
}
