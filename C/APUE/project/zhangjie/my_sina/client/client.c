#include"client.h"

int main()
{
	int sockfd = socket_fun();
	int suc = -1;
	sCts buf;
	sRed ser;
	while(1)
	{
		bzero(&buf, sizeof(buf));
		printf("请选择功能\n");
		printf("0:注册\n");
		printf("1:登录\n");
		scanf("%d", &buf.type);
		switch(buf.type)
		{
			case REGISTER:
				suc = reg_fun(sockfd, buf);
				if(0 == suc)
				{
					int yes;
					printf("注册成功\n");
					puts("按0键直接登录");
					scanf("%d", &yes);
					write(sockfd, &yes, sizeof(int));
					read(sockfd, &suc, sizeof(int));
					if(suc == 0)
					{
						goto load;
					}
				}
				break;
			case LOGIN:
				log_fun(sockfd, buf);
				read(sockfd, &suc, sizeof(int));
				if(suc == 0)
				{
					goto load;
				}
				printf("登录失败\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	}
load:
	bzero(&ser, sizeof(ser));
	read(sockfd, &ser, sizeof(ser));
	printf("用户名%s\n粉丝:%d 好友%d 微博%d\n",
		ser.usr_msg.usr_nam,ser.concern_num,ser.friend_num,ser.publish_num);
	menu_self(sockfd, ser);
	return 0;
}

int socket_fun()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in conaddr;
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(9999);
	conaddr.sin_addr.s_addr = inet_addr("192.168.1.25");
	connect(sockfd, (struct sockaddr*)&conaddr, sizeof(conaddr));
	return sockfd;
}

int reg_fun(int sockfd, sCts buf)
{
	int suc = -1;
	char *p1 = NULL;
	do
	{
		printf("请输入用户帐号\n");
		scanf("%s", buf.exe_fun.usr_self_info.usr_id);
		p1 = getpass("请输入密码");
		strcpy(buf.exe_fun.usr_self_info.usr_passwd, p1);
		p1 = getpass("请重复密码");
		if(strcmp(buf.exe_fun.usr_self_info.usr_passwd, p1) == 0)
		{
			break;
		}
		printf("两次密码输入不一致，注册失败\n");
	}while(1);
	strcpy(buf.exe_fun.usr_self_info.usr_passwd, p1);
	printf("请输入用户名, 输入后不可更改，请慎重考虑\n");
	scanf("%s",buf.exe_fun.usr_self_info.usr_nam);
	write(sockfd, &buf, sizeof(buf));
	read(sockfd, &suc, sizeof(int));
	printf("%d\n", suc);
	return suc;
}

int log_fun(int sockfd, sCts buf)
{
	printf("请输入帐号:");
	scanf("%s", buf.exe_fun.usr_self_info.usr_id);
	char *p = getpass("请输入密码:");
	strcpy(buf.exe_fun.usr_self_info.usr_passwd, p);
	write(sockfd, &buf, sizeof(buf));
	return 0;
}

int menu_self(int sockfd, sRed ser)
{
	sCts buf;
	sCts face;
	int ret;
	int line;
	int usr_face = -1;//当前界面-1为自己， 0为好友
	char usr_face_nam[30];//记录当前界面人的名字
	strcpy(usr_face_nam, ser.usr_msg.usr_nam);
	while(1)
	{
		bzero(&buf, sizeof(buf));
		strcpy(buf.usr_nam, ser.usr_msg.usr_nam);
		printf("请选择功能：\n");
		if(usr_face == -1)
		{
			printf("2:搜索用户\n");
			printf("3:关注好友\n");
			printf("4:取消关注\n");
			printf("5:发表微博\n");
		}
		printf("6:查看微博\n");
		printf("7:查看好友\n");
		printf("8:查看粉丝\n");
		if(usr_face == 0)
		{
			printf("15:返回主界面\n");
		}
		printf("16:退出程序\n");
		scanf("%d", &buf.type);
		switch(buf.type)
		{
			case SEARCH:
					if(usr_face == -1)
					{
						printf("请输入你要查找的用户名\n");
						scanf("%s", buf.exe_fun.search_usr_name);
						if(strcmp(buf.usr_nam, 
								buf.exe_fun.search_usr_name) ==0 )
						{
							goto see;
						}
						usr_face = search(sockfd, buf);
						if(usr_face == 0)
						{
							strcpy(usr_face_nam, 
							buf.exe_fun.search_usr_name);
						}
					}
					break;
			case CONCERN:
					if(usr_face == -1)
					{
						concern(sockfd, buf);
					}
					break;
			case NOT_CONCERN:
					if(usr_face == -1)
					{
						unconcern(sockfd, buf);
					}
					break;
			case PUBLISH:
					if(usr_face == -1)
					{
						pub_web(sockfd, buf);
					}
					break;
			case VIEW_BLOG:
					strcpy(buf.exe_fun.search_usr_name, usr_face_nam);
					view_web(sockfd, buf);
					break;
			case VIEW_FRI:
					strcpy(buf.exe_fun.search_usr_name, usr_face_nam);
					friend_list(sockfd, buf);
					break;
			case VIEW_FAN:
					strcpy(buf.exe_fun.search_usr_name, usr_face_nam);
					fans_list(sockfd, buf);
					break;
			case QUIT_V:
					if(usr_face == 0)
					{
						strcpy(buf.exe_fun.search_usr_name, usr_face_nam);
						ret = last(sockfd, buf);
						if(ret == 0)
						{
							usr_face = -1;
							bzero(usr_face_nam, sizeof(usr_face_nam));
							strcpy(usr_face_nam, ser.usr_msg.usr_nam);
						}
					}
					break;
			case QUIT_S:
					line = quit_s(sockfd, buf);
					if(line == 0)
					{
						return 0;
					}
					break;
			default:
				printf("操作错误\n");
					break;
		}
		if(buf.type != SEARCH && buf.type != QUIT_V)
		{
			see:
			face.type = SEARCH;
			strcpy(face.usr_nam, ser.usr_msg.usr_nam);
			strcpy(face.exe_fun.search_usr_name, usr_face_nam);
			search(sockfd, face);
		}
	}
}
