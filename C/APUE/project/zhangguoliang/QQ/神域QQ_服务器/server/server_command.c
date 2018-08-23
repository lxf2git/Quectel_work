#include "../include/apue.h"
void show_server_list();
void show_ip();
void show_qq();
void show_ip_qq();
void force_ip(char *);
void force_qq(int );
void set_vip(int,char);
void exit_ser();

void *server_command()
{
		char buf[MAX_SIZE]={0};
		/*show_chain();*/
		bzero(buf,sizeof(buf));
		read(STDIN_FILENO,buf,sizeof(buf));
		int flag=buf[0]-'0';
		switch(flag)
		{
				case SHUTDOWN:
					exit_ser();
						break;
				case SHOW1:
					show_ip();
						break;
				case SHOW2:
					show_qq();
						break;
				case SHOW12:
					show_ip_qq();
						break;
				case SHUTQQ:
					force_qq(atoi(buf+3));
						break;
				case SHUTCON:
					force_ip(buf+3);
						break;
				case SETVIP:
					buf[8]=0;
					set_vip(atoi(buf+3),buf[10]);
						break;
				default:
						show_server_list();
						break;
		}
		waitpid(0,NULL,WNOHANG);
//	write(STDOUT_FILENO,buf,strlen(buf)+1);

}

void show_server_list()
{

					printf("请输入相应功能前编号\n");
					printf("1 显示已连接的电脑及是否登录qq\n");
					printf("2 显示已登录的qq及其简单信息\n");
					printf("3 同时显示1和2的信息\n");
					printf("4->qq 强制将指定qq下线\n");
					printf("5->addr 强制关闭与指定电脑的连接\n");
					printf("6->qq->level 设置指定qq用户的vip等级\n");
					printf("0 退出服务器，并释放服务器空间\n");
}



void show_ip()
{
		pchain pnew=NULL;
		pnew=phead->next;
		while(pnew!=phead)
		{
				printf("IP:%s ",inet_ntoa(pnew->conaddr.sin_addr));
				if(pnew->if_log=='1')
				{
						printf("QQ已登录\n");
				}
				if(pnew->if_log=='0')
				{
						printf("没有QQ登录\n");
				}
				pnew=pnew->next;
		}
		if(phead->next==phead)
				printf("没有任何电脑连接\n");
}

void show_qq()
{
		pchain pnew=NULL;
		pnew=phead->next;
		if(phead->next==phead)
				printf("无任何qq号登录\n");
		else
		{
			printf("已登录如下账户:\n");
			while(pnew!=phead)
			{
					if(pnew->if_log=='1')
					{
							printf("QQ :%d, name :%s;\n",pnew->data->id,pnew->data->virtual_name);
					}
					pnew=pnew->next;
			}
		}
}

void show_ip_qq()
{
		pchain pnew=NULL;
		pnew=phead->next;
		if(phead->next==phead)
				printf("无任何连接信息\n");
		else
		while(pnew!=phead)
		{
				printf("IP :%s",inet_ntoa(pnew->conaddr.sin_addr));
				if(pnew->if_log=='1')
				{
						printf("已有QQ登录\n");
						printf("	QQ :%d, name :%s;\n",pnew->data->id,pnew->data->virtual_name);
				}
				if(pnew->if_log=='0')
				{
						printf("没有QQ登录\n");
				}

		}
}


void force_qq(int id)
{
		struct to_udp qq_udp;
		struct sockaddr_in nimei;

		pchain qq_ch;
		qq_ch =find_now(id);
		if(qq_ch!=NULL)
		{
				int udp_fd=socket(AF_INET,SOCK_DGRAM,0);
				if(udp_fd<0)
				{
						show_err("socket");
				}

				nimei.sin_family = AF_INET;
				nimei.sin_port = htons(PORT);
				nimei.sin_addr.s_addr = inet_addr(inet_ntoa(qq_ch->conaddr.sin_addr));
				qq_udp.flag = AEXIT;
				//qq_udp.id = qq_ch->data->id;
				//strcpy(qq_udp.virtual_name,qq_ch->data->virtual_name);

				sendto(udp_fd,&qq_udp,sizeof(qq_udp),0,(struct sockaddr*)&(qq_ch->conaddr),len);

				log_off(qq_ch->confd);
				printf("已强行使QQ :%d 下线\n",id);
		}
		else
				printf("该QQ已不在线\n");
}

void force_ip(char *ip)
{
		pchain pnew=NULL;
		pnew=phead;
		while(pnew->next!=phead)
		{
				if(strcmp(inet_ntoa(pnew->next->conaddr.sin_addr),ip)==0)
				{
						pchain pdel = pnew->next;
						close(pdel->confd);
						remove_node(pdel);
						printf("已断开与 %s 的链接\n",ip);
						return ;
				}
				pnew=pnew->next;
		}
		printf("未找到该ip\n");
}

void set_vip(int id,char vip)
{
	pchain vip_p = find_now(id);
	vip_p->data->vip = vip;
	addto_file(vip_p);
	printf("QQ :%d vip等级已升至 %c级\n",id,vip_p->data->vip);
}

void exit_ser()
{
		pchain pnew=NULL;
		pchain pdel;
		pnew=phead;
		while(pnew->next!=phead)
		{
			pdel=pnew->next;
			close(pnew->next->confd);
			remove_node(pdel);
			pnew=pnew->next;
		}
			free(phead);
		pool_destroy();

			printf("服务器已关闭\n");
			kill(getpgrp(),SIGKILL);
}
