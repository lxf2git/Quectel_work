#include "../include/ftp.h"
#include "../include/list.h"

#define _XOPEN_SOURCE
#include <shadow.h>
#include <crypt.h>
#include <unistd.h>

//struct list user_list_head;
//static int logfd;

char user_login(struct user_msg);
void write_log(struct list_info);

int deal_process(int sockfd, struct cli_ser_pakg recv_info, struct sockaddr_in cli_ip)
{
	char data_buf[1024];
	int fifofd, ret;


	struct send_pakg login_msg;
	struct list *list_tmp;
	memset(&login_msg, 0, sizeof(login_msg));

	if (recv_info.cmd == LOGIN){
		if ((ret = user_login(recv_info.cli_info)) < 0){
			login_msg.pakg_type = ERR;
			if (ret == -2){
				strcat(login_msg.data_buf.cmd_buf, "root login faild.");
			}
			else{
				strcat(login_msg.data_buf.cmd_buf, "login faild.");
			}
			sendto(sockfd, &login_msg, sizeof(login_msg), 0, 
					(struct sockaddr*)&cli_ip, sizeof(cli_ip));
			
			return -1;	
		}

		login_msg.pakg_type = LOGIN;
		strcat(login_msg.data_buf.cmd_buf, "login successs.");
		sendto(sockfd, &login_msg, sizeof(login_msg), 0, 
				(struct sockaddr*)&cli_ip, sizeof(cli_ip));
	
		memset(data_buf, 0, sizeof(data_buf));

		
		sprintf(data_buf, "/tmp/ftp/%s-%d", 
				inet_ntoa(cli_ip.sin_addr), ntohs(cli_ip.sin_port));
		
		if (mkfifo(data_buf, 0600) < 0){
			perror("server create fifo error");
			return -1;
		}
	
		if ((fifofd = open(data_buf, O_RDWR)) < 0){
			perror("server open fifo error");
			return -1;
		}

		struct user_list_num *new_user = calloc(1, sizeof(struct user_list_num));
		new_user->user.user_info = recv_info.cli_info;
		new_user->user.cli_ip = cli_ip;
		new_user->user.fifo_fd = fifofd;
		new_user->user.time = time(NULL);
		list_add_tail(&user_list_head, &(new_user->_list));
		return 0;
	}
	else{
		list_each(list_tmp, (&user_list_head)){
			if (list_entry(list_tmp, struct user_list_num, _list)->
					user.cli_ip.sin_addr.s_addr == cli_ip.sin_addr.s_addr){
				if (list_entry(list_tmp, struct user_list_num, _list)->
						user.cli_ip.sin_port == cli_ip.sin_port){
					fifofd = list_entry(list_tmp, struct user_list_num, _list)->
								user.fifo_fd;
					write(fifofd, &recv_info, sizeof(recv_info));

					if (recv_info.cmd == QUIT){
						close(fifofd);
						write_log(list_entry(list_tmp, struct user_list_num, _list)->user);
						list_remove(list_tmp);
						free(list_entry(list_tmp, struct user_list_num, _list));
					}

					break;
				}
			}
		}
			
		
		return 1;
	}
}


char user_login(struct user_msg user)
{
	struct spwd *sys_user;
	char *crypt_user_passwd;

	if (!strcmp(user.username, "root")){
		return -2;
	}

	sys_user = getspnam(user.username);
	if (NULL == sys_user){
		return -1;
	}

	setspent();
	crypt_user_passwd = crypt(user.passwd, sys_user->sp_pwdp);
	if (!strcmp(crypt_user_passwd, sys_user->sp_pwdp)){
		return 0;
	}
	else{
		return -1;
	}
	endspent();
}


void write_log(struct list_info list_num)
{
	char log_buf[1024];
	time_t now_time = time(NULL);
	printf("%lu %lu\n", list_num.time, now_time);
	printf("%s\n", ctime(&list_num.time));
	printf("%s\n", ctime(&now_time));
	memset(log_buf, 0, sizeof(log_buf));
	sprintf(log_buf, "%s  %d  %s", inet_ntoa(list_num.cli_ip.sin_addr),
			ntohs(list_num.cli_ip.sin_port), list_num.user_info.username);
	strcat(log_buf, ctime(&list_num.time));
	strcat(log_buf, ctime(&now_time));
	*strchr(log_buf, '\n') = ' ';
	write(logfd, log_buf, sizeof(log_buf));
}
