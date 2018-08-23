#include "../include/apue.h"	
void login_send(int,int,char *);
void login_send_message(int,int,char*);
void quit_con(int nowfd)
{
		pchain pdel = NULL;
		pdel = find_addr(nowfd);
		printf("%s:已关闭客户端！\n",inet_ntoa(pdel->conaddr.sin_addr));
		remove_node(pdel);
}
void qq_apply(int nowfd,struct client_apply apply_info)
{
		int get_qq = open(GET_QQ,O_RDWR|O_CREAT,FIL_PER);//分配qq号
		int qq=0;
		if(read(get_qq,&qq,sizeof(qq))>0) qq++;
		else qq=MIN_QQ;
		printf("新申请的qq号:%d\n",qq);
		int *p;
		ftruncate(get_qq,4);//这个如果没有的话，修改文件中结构体会出问题（后面数据清零）
		p=(int *)mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,get_qq,0);
		p[0]=qq;
		munmap(p,4);
		close(get_qq);
		int all_data = open(DATA_FILE,O_RDWR|O_APPEND|O_CREAT,FIL_PER);//记录申请qq信息
		creat_data tmp;
		bzero(&tmp,sizeof(tmp));
		tmp.id = qq;
		tmp.age = apply_info.age;
		printf("年龄：%d\n",tmp.age);
		strcpy(tmp.virtual_name,apply_info.virtual_name);
		printf("昵称：%s\n",tmp.virtual_name);
		strcpy(tmp.real_name,apply_info.real_name);
		printf("真实姓名：%s\n",tmp.real_name);
		strcpy(tmp.passwd,apply_info.passwd);
		printf("密码：%s\n",tmp.passwd);
		strcpy(tmp.telephone_num,apply_info.telephone);
		printf("电话：%s\n",tmp.telephone_num);
		strcpy(tmp.birthday,apply_info.birthday);
		printf("生日：%s\n",tmp.birthday);
		strcpy(tmp.gender,apply_info.gender);
		printf("性别：%s\n",tmp.gender);
		tmp.for_passwd = apply_info.for_passwd;
		printf("找回码：%d\n",tmp.for_passwd);
		tmp.vip='0';
		write(all_data,&tmp,sizeof(tmp));
		close(all_data);
		write(nowfd,&tmp,sizeof(tmp));
}
void find_off_info(int nowfd)
{
		printf("进入上线离线传送模块\n");
		pchain on_p = find_addr(nowfd);
		int fd = open("offsend",O_RDWR|O_CREAT,0666);
		off_t offset=0;
		offset=lseek(fd,0,SEEK_END);
		printf("offset:%d\n",offset);
		if(offset!=0)
		{
		ftruncate(fd,offset);//这个如果没有的话，修改文件中结构体会出问题（后面数据清零）
		struct off_send *p=NULL;
		int i;
		p=(struct off_send*)mmap(0,offset,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
		for(i=0;p[i].flag!=0;i++)
		{
				printf("offsend文件不为空\n");
			if(p[i].to_id==on_p->data->id)
			{
			
				if(p[i].flag==1)
				{
					printf("有离线文件\n");
					login_send(nowfd,p[i].id,p[i].file_name);
					p[i].flag=-1;
					printf("离线文件传输完毕\n");
				}
				if(p[i].flag==2)
				{
					printf("有离线信息\n");
					login_send_message(nowfd,p[i].id,p[i].message);
					p[i].flag=-1;
					printf("离线信息传送完毕\n");
				}
			}
		}
		printf("退出离线传输\n");
		munmap(p,offset);
		}
		close(fd);
}

void qq_login(int nowfd,struct client_login login_info)
{
		creat_data *tmp = NULL;
		pchain ptmp = NULL;
		pchain wtmp = NULL;
		tmp = (creat_data *)malloc(sizeof(creat_data));
		if(tmp==NULL)
		{
				printf("malloc err!\n");
				return ;
		}
		bzero(tmp,sizeof(*tmp));
		int all_data = open("qqdata",O_RDONLY);
		struct client_myinfo hisinfo;
		while(read(all_data,tmp,sizeof(*tmp))>0)
		{
			if(login_info.id==tmp->id)
			{
					printf(" %d 正在尝试登录\n",tmp->id);
					if((wtmp=find_now(tmp->id))!=NULL)
					{
							if(wtmp->data!=NULL)
							{
								printf("该id已经登录\n");
								break;
							}
					}
					if(!strcmp(login_info.passwd,tmp->passwd))
					{
						write(nowfd,RET_SUC,sizeof(RET_SUC));
						hisinfo.id=tmp->id;
						strcpy(hisinfo.virtual_name,tmp->virtual_name);
						strcpy(hisinfo.birthday,tmp->birthday);
						strcpy(hisinfo.telephone_num,tmp->telephone_num);
						strcpy(hisinfo.gender,tmp->gender);
						hisinfo.vip=tmp->vip;
						strcpy(hisinfo.real_name,tmp->real_name);
						hisinfo.age=tmp->age;
						write(nowfd,&hisinfo,sizeof(hisinfo));//登录成功
						ptmp = find_addr(nowfd);
						ptmp->if_log='1';
						ptmp->data=tmp;
						printf("登录成功\n");
						printf("查看是否有离线文件\n");
						find_off_info(nowfd);
						close(all_data);
						return ;
					}
					printf("登录失败!\n");
					break;
			}
		}
		close(all_data);
		write(nowfd,RET_ERR,sizeof(RET_ERR));
}

void found_pwd(int nowfd,struct client_found found)//找密
{
	if(found.id==0)
			return ;
		printf("有人运行找回密码模块\n");
	int i=0;
	creat_data f_chain;
	bzero(&f_chain,sizeof(f_chain));
	int fd;
	if((fd=open("qqdata",O_RDONLY))==-1)
	{
			printf("打开qqdata错误\n");
			goto ERR;
	}
	while(read(fd,&f_chain,sizeof(f_chain))>0)
	{
			if(found.id==f_chain.id)
					break;
	}
	if(f_chain.id==0)
			goto ERR;
	printf("id:%d\n",found.id);
	printf("开始匹配找回信息\n");
	printf("真实姓名%s\n",found.real_name);
	printf("文件内真实姓名%s\n",f_chain.real_name);
	if(!strcmp(found.real_name,f_chain.real_name))
	{
		printf("姓名相同\n");
		i++;
	}
	printf("%d\n",found.for_passwd);
	printf("%d\n",f_chain.for_passwd);
	if(found.for_passwd==f_chain.for_passwd)
	{
		printf("口令相同\n");
		i++;
	}
	printf("%s\n",found.telephone);
	printf("%s\n",f_chain.telephone_num);
	if(!strcmp(found.telephone,f_chain.telephone_num))
	{
		printf("电话相同\n");
		i++;
	}

	if(i==3)//全部相同
	{
		write(nowfd,RET_SUC,sizeof(RET_SUC));
		struct client_login back_login;
		back_login.id=f_chain.id;
		strcpy(back_login.passwd,f_chain.passwd);
		printf("返回的密码:%s\n",back_login.passwd);
		write(nowfd,&back_login,sizeof(back_login));
	}
	else
	{
ERR:
			printf("找回密码失败\n");
		write(nowfd,RET_ERR,sizeof(RET_ERR));
	}
}

pchain find_now(int fd_id)
{
		pchain ptmp=NULL;
		for(ptmp=phead->next;ptmp!=phead;ptmp=ptmp->next)
		{
				if((ptmp->data!=NULL)&&(fd_id==ptmp->data->id))
						return ptmp;
		}
		return NULL;
}
void friend_list(int nowfd)//好友列表
{
	pchain fnd =  find_addr(nowfd);
	int i,fd,no_on[PARTNER_SIZE]={0},num=0,null_p=0;
	struct list_friend l_fri;
	pchain ptmp=NULL;
	for( i=0;i<PARTNER_SIZE;i++,ptmp=NULL )
	{
		if(fnd->data->partner[i]==-1) null_p++;
		if(fnd->data->partner[i]==0)
		{
			break;
		}
		bzero(&l_fri,sizeof(l_fri));
		if((ptmp=find_now(fnd->data->partner[i]))!=NULL)
		{
			l_fri.is_on='1';
			l_fri.id=fnd->data->partner[i];
			strcpy(l_fri.virtual_name,ptmp->data->virtual_name);
			printf("在线好友:%d ID:%s\n",l_fri.id,l_fri.virtual_name);
			write(nowfd,&l_fri,sizeof(l_fri));
		}
		else
		{
			if(fnd->data->partner[i]!=-1)
			{
				no_on[num]=fnd->data->partner[i];
				num++;
			}
		}
	}
	printf(" 共%d个好友 %d个离线好友\n",i-null_p,num--);
	creat_data fri;
	set_err(fd=open("qqdata",O_RDONLY),"open");
	for(num=0;(num<PARTNER_SIZE)&&(no_on[num]!=0);num++)
	{
		printf("离线好友 %d ID:%d\n",num+1,no_on[num]);
		lseek(fd,0,SEEK_SET);
		while(read(fd,&fri,sizeof(fri))>0)
		{
			if(no_on[num]==fri.id)
			{
			l_fri.is_on='0';
			l_fri.id=no_on[num];
			strcpy(l_fri.virtual_name,fri.virtual_name);
			printf("不在线ID:%d 昵称:%s\n",l_fri.id,l_fri.virtual_name);
			write(nowfd,&l_fri,sizeof(l_fri));
			break;
			}
		}
	}
	bzero(&l_fri,sizeof(l_fri));
	l_fri.is_on=0;
	write(nowfd,&l_fri,sizeof(l_fri));
	close(fd);
	printf("好友列表发送完毕\n");
}
int addto_file(pchain c)
{
	int fd,i;
	set_err((fd=open("qqdata",O_RDWR)),"open");
	off_t offset=0;
	offset=lseek(fd,0,SEEK_END);
	ftruncate(fd,offset);//这个如果没有的话，修改文件中结构体会出问题（后面数据清零）
	creat_data *p=NULL;
	p=(creat_data *)mmap(0,offset,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	for(i=0;i<MAX_SIZE;i++)
	{
		if((p[i].id)==(c->data->id))
		{
				p[i]=*(c->data);
				munmap(p,offset);//解除映射
				close(fd);
				return 1; 
		}
			
	}
	munmap(p,offset);//解除映射
	close(fd);
	return 0;
	
}
void change_info(int nowfd,struct client_apply s_info)//映射
{
	printf("进入了修改信息页面\n");
	pchain c=find_addr(nowfd);
	if(NULL!=s_info.virtual_name)
	{
		strcpy(c->data->virtual_name,s_info.virtual_name);
		printf("修改昵称为：%s\n",c->data->virtual_name);
	}
	if(NULL!=s_info.real_name)
	{
		strcpy(c->data->real_name,s_info.real_name);
		printf("修改名字为:%s\n",c->data->real_name);
	}
	if(NULL!=s_info.telephone)
	{
		strcpy(c->data->telephone_num,s_info.telephone);
		printf("修改电话为:%s\n",c->data->telephone_num);
	}
	if(NULL!=s_info.birthday)
	{
		strcpy(c->data->birthday,s_info.birthday);
		printf("修改生日为:%s\n",c->data->birthday);
	}
	if(NULL!=s_info.passwd)
	{
		strcpy(c->data->passwd,s_info.passwd);
		printf("修改密码为:%s\n",c->data->passwd);
	}
	if(NULL!=s_info.gender)
	{
		strcpy(c->data->gender,s_info.gender);
		printf("修改性别为:%s\n",c->data->gender);
	}
	if(0!=s_info.age)
	{
		c->data->age=s_info.age;
		printf("修改年龄为:%d\n",c->data->age);
	}
	if(0!=s_info.for_passwd)
	{
		c->data->for_passwd=s_info.for_passwd;
		printf("修改找回码:%d\n",c->data->for_passwd);
	}
	if(addto_file(c))
	{
			printf("修改完成!\n");
			write(nowfd,RET_SUC,sizeof(RET_SUC));
	}
	else
	{
		printf("未找到该帐号!\n");
		write(nowfd,RET_ERR,sizeof(RET_ERR));
	}
	
}

void log_off(int nowfd)//注销
{
			printf("进入注销模式\n");
			pchain l_off = find_addr(nowfd);
			l_off->if_log='0';
			bzero(l_off->data,sizeof(creat_data));
			free(l_off->data);
			l_off->data=NULL;
			printf("注销成功\n");
}


//通过udp实现的相关功能


void add_friend(int nowfd,int add_id)//加好友
{
		printf("有人进入加好友模块\n");
		int udp_fd;
		struct to_udp t_udp;
		struct sockaddr_in tmpaddr;
		char ret[2]={0};
		pchain ptmp=NULL;
		pchain udp_s = find_addr(nowfd);//我的信息
		int i;
		for(i=0;udp_s->data->partner[i]!=0;i++)
		{
			if(udp_s->data->partner[i]==add_id)
			{
				printf("好友已存在\n");
				t_udp.flag=KOFD;
				strcpy(t_udp.virtual_name,ptmp->data->virtual_name);
				t_udp.id=ptmp->data->id;
				sendto(udp_fd,&t_udp,sizeof(t_udp),0,(struct sockaddr*)&(udp_s->conaddr),len);
				goto BAG;
			}
		}
		
		if((ptmp=find_now(add_id))==NULL)
		{
				printf("该id不在线或无此id\n");
				t_udp.flag=NKOFD;
				sendto(udp_fd,&t_udp,sizeof(t_udp),0,(struct sockaddr*)&(udp_s->conaddr),len);
				goto BAG;
		}

		set_err(udp_fd=socket(AF_INET,SOCK_DGRAM,0),"socket");
		socklen_t len = sizeof(struct sockaddr_in);
		t_udp.conaddr.sin_family=AF_INET;
		t_udp.conaddr.sin_port=htons(8888);
		t_udp.conaddr.sin_addr.s_addr = udp_s->conaddr.sin_addr.s_addr;
		printf("+ip:%s\n",inet_ntoa(t_udp.conaddr.sin_addr));
		t_udp.id=udp_s->data->id;
		strcpy(t_udp.virtual_name,udp_s->data->virtual_name);
		t_udp.flag=OKFD;
		
		selfaddr.sin_family=AF_INET;
		selfaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		selfaddr.sin_port=htons(PORT);

	 	bind(udp_fd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));

		printf("发送添加好友的信息\n");
		sendto(udp_fd,&t_udp,sizeof(t_udp),0,(struct sockaddr*)&(ptmp->conaddr),len);
		printf("给ip：%s发送请求\n",inet_ntoa(ptmp->conaddr.sin_addr));
		
		recvfrom(udp_fd,ret,2,0,(struct sockaddr*)&tmpaddr,&len);
		printf("已接收到回复:%s\n",ret);
		if(ret[0]=='0')
		{
				printf("不同意加好友\n");
				t_udp.flag=NKOFD;
				sendto(udp_fd,&t_udp,sizeof(t_udp),0,(struct sockaddr*)&(udp_s->conaddr),len);
		}
		else
		{
				printf("同意加好友\n");
				int i;
				t_udp.flag=KOFD;
				strcpy(t_udp.virtual_name,ptmp->data->virtual_name);
				t_udp.id=ptmp->data->id;
				sendto(udp_fd,&t_udp,sizeof(t_udp),0,(struct sockaddr*)&(udp_s->conaddr),len);
				for(i=0;(ptmp->data->partner[i]!=0)&&(ptmp->data->partner[i]!=-1);i++);
				printf("它的第%d个好友:",i+1);
				ptmp->data->partner[i]=udp_s->data->id;
				printf("%d\n",ptmp->data->partner[i]);
				addto_file(ptmp);
				for(i=0;(udp_s->data->partner[i]!=0)&&(udp_s->data->partner[i]!=-1);i++);
				printf("它的第%d个好友:",i+1);
				udp_s->data->partner[i]=add_id;
				printf("%d\n",ptmp->data->partner[i]);
				addto_file(udp_s);
		}
	BAG:
		close(udp_fd);
}

void talk_friend(int nowfd, int id)//好友id
{
		if(!fork())
		{
				printf("进入好友聊天模块\n");
				char ret[2]={0};
				int talkfd = socket(AF_INET,SOCK_DGRAM,0);
		selfaddr.sin_family=AF_INET;
		selfaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		selfaddr.sin_port=htons(PORT);

	 	bind(talkfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
				struct to_udp talk_udp;//back_udp 是判断时 1 0 条件下发送的
				talk_udp.flag = S_TALK;
				pchain my_p = find_addr(nowfd);
				talk_udp.id = my_p->data->id;
				strcpy(talk_udp.virtual_name,my_p->data->virtual_name);

				talk_udp.conaddr.sin_family=AF_INET;//我的内容传给他
				talk_udp.conaddr.sin_port=htons(8888);
				talk_udp.conaddr.sin_addr.s_addr=my_p->conaddr.sin_addr.s_addr;		

				pchain fri_p = find_now(id);
				fri_p->conaddr.sin_port=htons(PORT);
				fri_p->conaddr.sin_family=AF_INET;
				sendto(talkfd,&talk_udp,sizeof(talk_udp),0,
								(struct sockaddr*)&(fri_p->conaddr),len);
				printf("已发送S_TALK给%d\n",fri_p->data->id);
				recvfrom(talkfd,ret,2,0,NULL,NULL);
				
				//		printf("客户机异常退出\n");
				printf("客户机已回复\n");
				if(ret[0]=='1')
				{
						printf("同意连接请求\n");
						talk_udp.id = fri_p->data->id;
						strcpy(talk_udp.virtual_name,fri_p->data->virtual_name);
						talk_udp.conaddr.sin_addr.s_addr=fri_p->conaddr.sin_addr.s_addr;	
						talk_udp.flag = M_TALK;
						sendto(talkfd,&talk_udp,sizeof(talk_udp),0,(struct sockaddr*)&(my_p->conaddr),len);
						goto TAG;
				}
				if(ret[0]=='2')
				{
						printf("拒绝连接请求\n");
						talk_udp.flag = N_TALK;
						sendto(talkfd,&talk_udp,sizeof(talk_udp),0,(struct sockaddr*)&(my_p->conaddr),len);
						goto TAG;
				}
				printf("连接失败！\n");
TAG:
				close(talkfd);
				exit(0);
		}
}


void fri_info(int nowfd,int id)
{
		printf("进入显示详细好友模块\n");
		struct client_myinfo f_info;
		bzero(&f_info,sizeof(f_info));
		pchain fri_p = find_now(id);
		if(NULL!=fri_p)
		{
				printf("该好友为在线好友\n");
				f_info.id = fri_p->data->id;
				f_info.age = fri_p->data->age;
				strcpy(f_info.virtual_name,fri_p->data->virtual_name);
				strcpy(f_info.real_name,fri_p->data->real_name);
				strcpy(f_info.telephone_num,fri_p->data->telephone_num);
				strcpy(f_info.birthday,fri_p->data->birthday);
				strcpy(f_info.gender,fri_p->data->gender);
				f_info.vip=fri_p->data->vip;
		}
		else
		{
				printf("该好友为离线好友\n");

				int fd;
			   	set_err(fd=open("qqdata",O_RDONLY),"open");
				creat_data frid_info;
				while(read(fd,&frid_info,sizeof(frid_info))>0)
				{
						if(frid_info.id==id)
						{
								f_info.id = frid_info.id;
								f_info.age = frid_info.age;
								strcpy(f_info.virtual_name,frid_info.virtual_name);
								strcpy(f_info.real_name,frid_info.real_name);
								strcpy(f_info.telephone_num,frid_info.telephone_num);
								strcpy(f_info.birthday,frid_info.birthday);
								strcpy(f_info.gender,frid_info.gender);
								f_info.vip=frid_info.vip;
								break;
						}
				}
		}
		write(nowfd,&f_info,sizeof(f_info));
}


void delet_friend(int nowfd, int id)//删除好友
{
		printf("进入删除好友模块要删除的好友id为:%d\n",id);
		pchain del = find_addr(nowfd);
		int my_id = del->data->id;//我的id号 
		int i,k=0;
		for(i=0;i<PARTNER_SIZE;i++)
		{
				if(del->data->partner[i]==0)
				{
						k=1;
						break;
				}
				if(del->data->partner[i]==id)
				{
						printf("该好友已经删除置为-1\n");
						del->data->partner[i]=-1;
						k=1;
						break;
				}
		}
		if(k==0)
		{
				printf("未找到该好友\n");
				write(nowfd,RET_ERR,sizeof(RET_ERR));
		}
		else
		{
				printf("已删除该好友\n");
				addto_file(del);
				write(nowfd,RET_SUC,sizeof(RET_SUC));
		}
		pchain fri_del = find_now(id);
		k=0;
		if(NULL!=fri_del)
		{
				for(i=0;i<PARTNER_SIZE;i++)
				{
						if(fri_del->data->partner[i]==0)
						{
								k=1;
								break;
						}
						if(fri_del->data->partner[i]==my_id)
						{
								fri_del->data->partner[i]=-1;
								k=1;
								break;
						}
				}
				if(k==1)//开始删除
				{
						addto_file(fri_del);
				}
		}
		else//NULL
		{
				k=0;
				int fd = open("qqdata",O_RDWR);
				creat_data fri_data;
				int n;
				while(read(fd,&fri_data,sizeof(fri_data))>0)
				{	
						if(fri_data.id==id)
								break;
				}
				pchain fri_null_del;
				init_chain(&fri_null_del);
				bzero(fri_null_del,sizeof(*fri_null_del));
				fri_null_del->data = &fri_data;
				for(i=0;i<PARTNER_SIZE;i++)
				{
						if(fri_null_del->data->partner[i]==0)
						{
								k=1;
								break;
						}
						if(fri_null_del->data->partner[i]==my_id);
						{
								fri_null_del->data->partner[i]=-1;
								k=1;
								break;
						}
				}
				if(k==1)
				{
						addto_file(fri_null_del);
				}
		}
}





void send_file_on(int nowfd,int id)
{
		printf("进入文件传输模块!\n");
		pchain file_p = find_now(id);
		if(file_p==NULL)return ;
		struct sockaddr_in sd_udp;
		int sd_fd = socket(AF_INET,SOCK_DGRAM,0);
		sd_udp.sin_family = AF_INET;
		sd_udp.sin_port = htons(PORT);

		sd_udp.sin_addr.s_addr = htonl(INADDR_ANY);
		bind(sd_fd,(struct sockaddr*)&sd_udp,sizeof(sd_udp));

		sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(file_p->conaddr.sin_addr));
		struct to_udp file_sd;
		char y_n[2]={0};

		pchain from_p = find_addr(nowfd);

		file_sd.flag = RFILE;
		file_sd.id = from_p->data->id;
		strcpy(file_sd.virtual_name,from_p->data->virtual_name);

		sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
		printf("等待好友接收!\n");
		recvfrom(sd_fd,y_n,2,0,NULL,NULL);
		sd_udp.sin_family = AF_INET;
		sd_udp.sin_port = htons(PORT);
		sd_udp.sin_addr.s_addr = from_p->conaddr.sin_addr.s_addr;
		printf("收到命令:%s\n",y_n);
		if(strcmp(y_n,"1")==0)
		{
				puts("对方同意接收文件");
				file_sd.flag = YFILE;
				file_sd.id = id;
				strcpy(file_sd.virtual_name,file_p->data->virtual_name);
				file_sd.conaddr.sin_addr.s_addr=file_p->conaddr.sin_addr.s_addr;
				file_sd.conaddr.sin_port=htons(PORT);
				file_sd.conaddr.sin_family=AF_INET;
				sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
				printf("发送方:%s\n",inet_ntoa(sd_udp.sin_addr));
		}
		else
		{
				puts("对方不同意接收文件");
				file_sd.flag = NFILE;
				sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
		}
		close(sd_fd);
}

void send_file_off(int nowfd,int id)
{
				printf("进入离线传文件模块\n");

				pchain off_fl = find_addr(nowfd);

				char file_cont[1024]={0};
				int fd,fp;
				struct sockaddr_in sd_udp;
				int sd_fd = socket(AF_INET,SOCK_DGRAM,0);
				sd_udp.sin_family = AF_INET;
				sd_udp.sin_port = htons(8888);
				struct to_udp file_sd;
				sd_udp.sin_addr.s_addr = htonl(INADDR_ANY);
				bind(sd_fd,(struct sockaddr*)&sd_udp,sizeof(sd_udp));
				sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(off_fl->conaddr.sin_addr));
				file_sd.flag = SCFILE;
				sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
				
				bzero(file_sd.file_name,sizeof(file_sd.file_name));
				recvfrom(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,&len);

				struct off_send off_info;
				off_info.flag = 1;
				off_info.id = off_fl->data->id;
				off_info.to_id = id;
				strcpy(off_info.file_name,file_sd.file_name);

				set_err(fp=open("offsend",O_RDWR|O_CREAT,0666),"open");
				 off_t offset=0;
				 offset=lseek(fp,0,SEEK_END);
				 printf("offset:%d\n",offset);
				 if(offset!=0)
				 {
					 ftruncate(fp,offset);//这个如果没有的话，修改文件中结构体会出问题（后面数据清零）
					 struct off_send *p=NULL;
					 p=(struct off_send *)mmap(0,offset,PROT_READ|PROT_WRITE,MAP_SHARED,fp,0);
					 int i=0;
					while(1)
					{
						if(p[i].flag==0)
						{
							write(fp,&off_info,sizeof(off_info));
							break;
						}
						if(p[i].flag==-1)
						{
							printf("发现-1\n");
							printf("给之前的离线文件赋值\n");
							p[i]=off_info;
							munmap(p,offset);
							break;

						}
						i++;
					}
				 }
				 else
				 {
						write(fp,&off_info,sizeof(off_info));
				 }
					close(fp);


				umask(0);
				char save_name[NAME_SIZE]={0};
				sprintf(save_name,"%d",id);

				mkdir(save_name,0666);
				chdir(save_name);
				printf("file_name:%s\n",file_sd.file_name);
				set_err(fd=open(file_sd.file_name,O_RDWR|O_CREAT,0666),"open");
				bzero(file_cont,sizeof(file_cont));
				usleep(5000);
				while(recvfrom(sd_fd,file_cont,sizeof(file_cont),MSG_DONTWAIT,NULL,NULL)>0)
				{
						write(fd,file_cont,strlen(file_cont));
				}
				close(sd_fd);
				close(fd);
				chdir("..");

}


void send_message_off(int nowfd,int id)
{
				printf("进入离线传传信息模块\n");

				pchain off_fl = find_addr(nowfd);

				char file_cont[256]={0};
				int fp;
				struct sockaddr_in sd_udp;
				int sd_fd = socket(AF_INET,SOCK_DGRAM,0);
				sd_udp.sin_family = AF_INET;
				sd_udp.sin_port = htons(8888);
				struct to_udp file_sd;
				sd_udp.sin_addr.s_addr = htonl(INADDR_ANY);
				bind(sd_fd,(struct sockaddr*)&sd_udp,sizeof(sd_udp));
				sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(off_fl->conaddr.sin_addr));
				file_sd.flag = SCTALK;
				sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
				
				recvfrom(sd_fd,file_cont,sizeof(file_cont),0,(struct sockaddr*)&sd_udp,&len);

				struct off_send off_info;
				bzero(&off_info,sizeof(off_info));
				off_info.flag = 2;//离线信息的flag
				off_info.id = off_fl->data->id;
				off_info.to_id = id;
				strcpy(off_info.message,file_cont);

				set_err(fp=open("offsend",O_RDWR|O_CREAT,0666),"open");
				 off_t offset=0;
				 offset=lseek(fp,0,SEEK_END);
				 printf("offset:%d\n",offset);
				 if(offset!=0)
				{
					 ftruncate(fp,offset);//这个如果没有的话，修改文件中结构体会出问题（后面数据清零）
					 struct off_send *p=NULL;
					 p=(struct off_send *)mmap(0,offset,PROT_READ|PROT_WRITE,MAP_SHARED,fp,0);
					 int i=0;
					while(1)
					{
						if(p[i].flag==0)
						{
							write(fp,&off_info,sizeof(off_info));
							printf("flag:%d id:%d toid:%d message:%s\n",off_info.flag,off_info.id,off_info.to_id,off_info.message);
							printf("离线信息发送成功\n");
							break;
						}
						if(p[i].flag==-1)
						{
							printf("发现-1\n");
							printf("给之前的离线文件赋值\n");
							p[i]=off_info;
							printf("flag:%d id:%d toid:%d message:%s\n",p[i].flag,p[i].id,p[i].to_id,p[i].message);
							munmap(p,offset);
							break;
	
						}
						i++;
					}
				}
				else
				{
					write(fp,&off_info,sizeof(off_info));
							printf("flag:%d id:%d toid:%d message:%s\n",off_info.flag,off_info.id,off_info.to_id,off_info.message);
					printf("离线信息发送成功\n");
				}
					close(fp);


				close(sd_fd);

}
void login_send_message(int nowfd,int id,char *message)
{
		printf("进入离线传信息模块\n");
		printf("id:%d message:%s\n",id,message);
		struct to_udp file_sd;
		pchain ptmp=NULL;
		int fa;
		int sd_fd = socket(AF_INET,SOCK_DGRAM,0);
		file_sd.flag=XZTALK;
		printf("XZTALK:%d\n",XZTALK);
		file_sd.id=id;
		ptmp=find_addr(nowfd);
		pchain file_p = find_now(id);
		if(file_p==NULL)
		{
				creat_data *madan=NULL;
				madan = (creat_data*)malloc(sizeof(creat_data));
				init_chain(&file_p);
				printf("该用户不在线\n");
				fa = open("qqdata",O_RDONLY);
				while(read(fa,madan,sizeof(*madan))>0)
				{
						printf("%d\n",madan->id);
						if(id==madan->id)
						{
								printf("找到该离线文件的发送者\n");
								file_p->data=madan;
								close(fa);
								break;
						}
				}
		}
		strcpy(file_sd.virtual_name,file_p->data->virtual_name);
		ptmp->conaddr.sin_family=AF_INET;
		ptmp->conaddr.sin_port=htons(PORT);
		sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&(ptmp->conaddr),len);
		usleep(5000);
		printf("离线信息发送成功flag=%d\n",file_sd.flag);
		printf("内容:%s\n",message);
		sendto(sd_fd,message,strlen(message)+1,0,(struct sockaddr*)&(ptmp->conaddr),len);

}

void login_send(int nowfd,int id,char *file_name)//16id
{
		printf("进入login_send\n");
		printf("id:%d file_name:%s\n",id,file_name);
		char file_cont[1024];
		int fd,fp,fa;
		struct sockaddr_in sd_udp;

		struct to_udp file_sd;
		int sd_fd = socket(AF_INET,SOCK_DGRAM,0);
		sd_udp.sin_family = AF_INET;
		sd_udp.sin_port = htons(8888);
		sd_udp.sin_addr.s_addr = htonl(INADDR_ANY);
		bind(sd_fd,(struct sockaddr*)&sd_udp,sizeof(sd_udp));

		pchain file_p = find_now(id);
		if(file_p==NULL)
		{
				creat_data *madan=NULL;
				madan = (creat_data*)malloc(sizeof(creat_data));
				init_chain(&file_p);
				printf("该用户不在线\n");
				fa = open("qqdata",O_RDONLY);
				while(read(fa,madan,sizeof(*madan))>0)
				{
						printf("%d\n",madan->id);
						if(id==madan->id)
						{
								printf("找到该离线文件的发送者\n");
								file_p->data=madan;
								close(fa);
								break;
						}
				}
		}

		pchain from_p = find_addr(nowfd);

		sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(from_p->conaddr.sin_addr));
		

		file_sd.flag = RFILE;
		file_sd.id = file_p->data->id;
		strcpy(file_sd.virtual_name,file_p->data->virtual_name);
		strcpy(file_sd.file_name,file_name);
		sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
		char y_n[2];
		char save_name[NAME_SIZE]={0};
		sprintf(save_name,"%d",from_p->data->id);
		read(sd_fd,y_n,2);
		printf("得到回复:%s\n",y_n);
		if(strcmp(y_n,"1")==0)
		{
				if(0==fork())
				{
						file_sd.flag = XZFILE;
						sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);

						chdir(save_name);
						printf("save_name:%s\n",save_name);
						printf("file_name:%s\n",file_name);
						fd = open(file_name,O_RDONLY);
						if(fd<0)
						{
								show_err("open");
						}
						int n;
						file_sd.flag = 100;
						bzero(file_cont,sizeof(file_cont));
						while(read(fd,file_cont,sizeof(file_cont))!=0)
						{
								sendto(sd_fd,file_cont,strlen(file_cont),0,(struct sockaddr*)&sd_udp,len);
								bzero(file_cont,sizeof(file_cont));
						}
						close(fd);

						sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(from_p->conaddr.sin_addr));// 回复发送端 对方已经接受文件
						unlink(file_sd.file_name);//删除文件
						exit(0);
				}
				else
				{
					sleep(2);//让子进程先运行
					rmdir(save_name);
				}
		}
		else
		{
			sd_udp.sin_addr.s_addr = inet_addr(inet_ntoa(from_p->conaddr.sin_addr));// 回复发送端 对方拒绝经接受文件
			file_sd.flag = NFILE;
			file_sd.id = id;
			strcpy(file_sd.virtual_name,file_p->data->virtual_name);
			sendto(sd_fd,&file_sd,sizeof(file_sd),0,(struct sockaddr*)&sd_udp,len);
			if(0==fork())
			{
				chdir(save_name);
				unlink(file_sd.file_name);
				exit(0);
			}
				rmdir(save_name);
		}
		close(sd_fd);
}








