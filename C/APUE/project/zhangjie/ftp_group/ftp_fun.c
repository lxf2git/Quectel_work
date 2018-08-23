#include"main.h"

void daemon_data_del(sRtd buf, int fd, char *p)//delete the information of daemon
{
	char usr_info[1024] = {"\0"};
	if(p[0] == '\0')
	{
		strcpy(usr_info, buf.usr_order_msg.uFg.ftp_cli_login.ftp_usrname);
		strcat(usr_info, " ");
		strcat(usr_info, buf.usr_order_msg.uFg.ftp_cli_login.ftp_passwd);
		strcat(usr_info, "\n");
	}
	else
	{
		strcpy(usr_info, p);
	}
	int l = strlen(usr_info);
	lseek(fd, SEEK_SET, 0);
	char record[1024] = {"\0"};
	char usr_info_red[1024] = {"\0"};
	read(fd, record, sizeof(record));
	int i,j=0,z;
	for(i=0;;i++)
	{
		usr_info_red[j] = record[i];
		j++;
		if(record[i] == '\n')
		{
			if(strcmp(usr_info_red, usr_info) == 0)
			{
				for(z=i+1-l; ; z++)
				{
					if(record[z] == '\n')
					{
						record[z] = record[z+l];
						break;
					}
					record[z] = record[z+l];
				}		
			}
			else
			{
				bzero(usr_info_red, sizeof(usr_info_red));
				j = 0;
				continue;
			}
		}
		if(record[i] == '\0')
		{
			break;
		}
	}
	lseek(fd, SEEK_SET, 0);
	write(fd, record, sizeof(record));
}

int suj_log_in(sRtd buf, int fd, char *p)//login
{
	char *pwd_cry_ret = NULL;
	struct spwd *pspwd = NULL;
	char user_name[50] = {"\0"};
	char user_passwd[50] = {"\0"};
	strcpy(user_name, buf.usr_order_msg.uFg.ftp_cli_login.ftp_usrname);
	strcpy(user_passwd, buf.usr_order_msg.uFg.ftp_cli_login.ftp_passwd);
	pspwd = getspnam(user_name);
	if(pspwd == NULL)
	{
		perror("getspnam");
		daemon_data_del(buf, fd, p);
		return FAILURE;
	}
	pwd_cry_ret = crypt(user_passwd, pspwd->sp_pwdp);
	if(strcmp(pwd_cry_ret, pspwd->sp_pwdp) == 0)
	{
		chdir("/home");
		chdir(user_name);
		strcpy(p, user_name);
		strcat(p, " ");
		strcat(p, user_passwd);
		strcat(p, "\n");
		return SUCCESS;
	}
	else
	{
		daemon_data_del(buf, fd, p);
		return FAILURE;
	}
}

struct sockaddr_in  pre_sed_del(sRtd buf)
{
	int confd = buf.confd;
	struct sockaddr_in conaddr;
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(8888);
	conaddr.sin_addr.s_addr = buf.usr_log_msg.sin_addr.s_addr;
	return conaddr;
}
	
void ret_to_cli(sRtd buf, int ret)
{
	int confd = buf.confd;	
	struct sockaddr_in conaddr = pre_sed_del(buf);
	socklen_t len = sizeof(conaddr);
	sendto(confd, &ret, sizeof(int), 0, (struct sockaddr *)&conaddr, len);
}

void rets_to_cli(sRtd buf, char *p)
{
	int confd = buf.confd;
	struct sockaddr_in conaddr = pre_sed_del(buf);
	socklen_t len = sizeof(conaddr);
	sendto(confd, p, strlen(p), 0, (struct sockaddr *)&conaddr, len);
}

int exce_ls_fun(sRtd buf)//ls
{
	char record[1024] = {"\0"};
	int fd_re = open("ls.txt", O_CREAT|O_EXCL|O_RDWR, 0777);
	if(fd_re < 0)
	{
		return FAILURE;
	}
	int ret;
	ret = SUCCESS;
	ret_to_cli(buf, ret);
	system("ls -l > ls.txt");
		while(1)
		{
			ret = read(fd_re, record, sizeof(record));
			if(ret <= 0)
			{
				strcpy(record, "null");
				rets_to_cli(buf, record);
				close(fd_re);
				system("rm -rf ls.txt");
				break;
			}
			rets_to_cli(buf, record);
			bzero(record, sizeof(record));
		}
		return EXE_SUC;
}

void get_cur_dir(sRtd buf)//pwd
{
	char path[1024] = {"\0"};
	getcwd(path, sizeof(buf));
	int ret = SUCCESS;
	ret_to_cli(buf, ret);
	rets_to_cli(buf, path);
	rets_to_cli(buf, "null");
}

int cd_poi_path(sRtd buf)//cd
{

	char path[100] = {"\0"};
	strcpy(path, buf.usr_order_msg.uFg.ftp_cd_path);
	int ret = chdir(path);
	if(ret < 0)
	{
		return FAILURE;
	}
	return SUCCESS;
}

int mkd_poi_dir(sRtd buf)//mkidr
{
	char dir_name[100] = {"\0"};
	strcpy(dir_name, buf.usr_order_msg.uFg.ftp_mkdir_path);
	int ret = mkdir(dir_name, 0644);
	if(ret < 0)
	{
		return FAILURE;
	}
	return SUCCESS;
}

void mk_quit_poc(sRtd buf, int fd, char *p)//quit
{
	daemon_data_del(buf, fd, p);
	bzero(p, sizeof(p));
	exit(0);
}

int put_new_file(sRtd buf, int id)//put
{
	int confd = buf.confd;
	char file_name[100] = {"\0"};
	strcpy(file_name, buf.usr_order_msg.uFg.ftp_put_file);
	int fd = open(file_name, O_CREAT|O_EXCL|O_RDWR, 0777);
	if(fd < 0)
	{
		return FAILURE;
	}
	int ret = SUCCESS;
	ret_to_cli(buf, ret);
	char record[1024] = {"\0"};
	while(1)
	{
		bzero(record, sizeof(record));
		recvfrom(confd, record, sizeof(record), 0, NULL, NULL);
		if(strcmp(record, "null") == 0)
		{
			break;
		}
		write(fd, record, strlen(record));		
	}
	return EXE_SUC;
}

int get_new_file(sRtd buf)//get
{
	char filename[100] = {"\0"};
	strcpy(filename, buf.usr_order_msg.uFg.ftp_get_file);
	int fd = open(filename, O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return FAILURE;	
	}
	int ret = SUCCESS;
	ret_to_cli(buf, ret);
	char file_ret[1024] = {"\0"};
	while(1)
	{
		ret = read(fd, file_ret, sizeof(file_ret));
		if(ret <= 0)
		{
			strcpy(file_ret, "null");
			rets_to_cli(buf, file_ret);
			break;
		}
		rets_to_cli(buf, file_ret);
		bzero(file_ret, sizeof(file_ret));
	}
	return EXE_SUC;
}

void ftp_fun(int fd)
{
	sMsg buf;
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	char usr_info[100] = {"\0"};
	while(1)
	{
		int ret,ch;
		bzero(&buf, sizeof(buf));
		key_t key = ftok("/root", 'x');
		int id = msgget(key,O_RDONLY);
		ssize_t ret_rec = msgrcv(id, &buf, sizeof(buf)-sizeof(buf.type), 
					getpid(), 0);
		if(ret_rec == -1)
		{
			perror("msgrcv");
			ret = FAILURE;
			ret_to_cli(buf.msgbuf, ret);
		}
		else
		{
			buf.msgbuf.confd = sockfd;
			ch = buf.msgbuf.usr_order_msg.type;
		}
		switch(ch)
		{
			case LOGIN:
				ret = suj_log_in(buf.msgbuf, fd, usr_info);
				ret_to_cli(buf.msgbuf, ret);
				break;
			case LS:
				ret = exce_ls_fun(buf.msgbuf);
				if(ret != EXE_SUC)
				{
					ret_to_cli(buf.msgbuf, ret);
				}
				break;
			case PUT:
				ret = put_new_file(buf.msgbuf, id);
				if(ret != EXE_SUC)
				{
					ret_to_cli(buf.msgbuf, ret);
				}
				break;
			case GET:
				ret = get_new_file(buf.msgbuf);
				if(ret != EXE_SUC)
				{
					ret_to_cli(buf.msgbuf, ret);
				}
				break;
			case CD:
				ret = cd_poi_path(buf.msgbuf);	
				ret_to_cli(buf.msgbuf, ret);
				break;
			case PWD:
				get_cur_dir(buf.msgbuf);
				break;
			case MKDIR:
				ret = mkd_poi_dir(buf.msgbuf);
				ret_to_cli(buf.msgbuf, ret);
				break;
			case QUIT:
				ret = SUCCESS;
				ret_to_cli(buf.msgbuf, ret);
				mk_quit_poc(buf.msgbuf, fd, usr_info);
				break;
			default :
				puts("input error");
				break;
		}
	}
}

