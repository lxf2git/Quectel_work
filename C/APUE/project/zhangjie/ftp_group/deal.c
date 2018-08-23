#include"main.h"
void show(pDtp phead);

int deal(int *pfd, int fd, pDtp phead, int msgid, sMsg msgbuf)
{
	pid_t pid;
	sRtd buf;
	int ret = read(pfd[0], &buf, sizeof(buf));
	if(ret < 0)
	{
		perror("read");
		return -1;
	}

	if(LOGIN == buf.usr_order_msg.type)
	{
		sMfile usr_msg;//用户信息
		usr_msg.type = 3;
		sprintf(usr_msg.msgbuf, "%s %s\n", 
				buf.usr_order_msg.uFg.ftp_cli_login.ftp_usrname,
				buf.usr_order_msg.uFg.ftp_cli_login.ftp_passwd);
		msgsnd(msgid, &usr_msg, sizeof(usr_msg)-sizeof(usr_msg.type), 0);
		pDtp pnew = NULL;
		init_node(&pnew);
		pnew->usr_log_msg = buf.usr_log_msg;
		pnew->pid_fun = fork();
		insert_(phead, pnew);
		if(pnew->pid_fun == 0)
		{
			ftp_fun(fd);
		}
	}
	pid = judge_pid(phead, &buf);
	msgbuf.type = (long)pid;
	msgbuf.msgbuf = buf;
	msgsnd(msgid, &msgbuf, sizeof(msgbuf)-sizeof(msgbuf.type), IPC_NOWAIT);
	return 0;
}

int insert_(pDtp phead, pDtp pnew)
{
	if(NULL == phead || NULL == pnew)
	{
		printf("insert error\n");
		return -1;
	}
	pnew->next = phead;
	pnew->prev = phead->prev;
	phead->prev->next = pnew;
	phead->prev = pnew;
}

int judge_pid(pDtp phead, pRtd data)
{
	pDtp p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(data->usr_log_msg.sin_addr.s_addr == 
			p->usr_log_msg.sin_addr.s_addr &&
			data->usr_log_msg.sin_port ==  p->usr_log_msg.sin_port)
		{
			return p->pid_fun;
		}
	}
	return 0;
}

void show(pDtp phead)
{
	puts("链表");
	pDtp p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		printf("%d ", p->pid_fun);
		fflush(stdout);
	}
}
