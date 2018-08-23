#include"main.h"

int main()
{
	int sockfd = sock_fun();
	int pfd[2];
	int ret = pipe(pfd);//建立处理进程和接受进程之间的数据传输。
	if(fork() == 0)
	{
		while(1)
		{
			recive(sockfd, pfd);
		}
	}
	else
	{
		pDtp phead = NULL;
		init_node(&phead);
		int fd = open("record.txt", O_RDWR, 0666);
		if(fd < 0)
		{
			perror("open");
			return -1;
		}
		int msgid = creat_msg_que();
		sMsg msgbuf;
		close(pfd[1]);
		if(fork() == 0)
		{
			record(fd, msgid);
		}
		while(1)
		{
			deal(pfd, fd, phead, msgid, msgbuf);
		}
	}
	return 0;
}

void zomb_fun(int sig)
{
	wait(NULL);
}

int sock_fun()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5556);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
	if(ret < 0)
	{
		close(sockfd);
		perror("bind");
		return -1;
	}
	listen(sockfd, 10);
	return sockfd;
}

void creat_memory(void **p, int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		perror("malloc");
		exit(-1);
	}

}

int recive(int sockfd, int *pfd)
{
	struct sockaddr_in conaddr;
	bzero(&conaddr, sizeof(conaddr));
	socklen_t len = sizeof(conaddr);
	int confd = accept(sockfd, (struct sockaddr*)&conaddr, &len);
	if(confd < 0)
	{
		close(sockfd);
		perror("accept");
		return -1;
	}
	if(fork() == 0)
	{
		close(pfd[0]);
		while(1)
		{
			recive_msg(sockfd, confd, conaddr, pfd);
		}
	}
}

int recive_msg(int sockfd, int confd, struct sockaddr_in conaddr, int *pfd)
{
	sCts buf;
	sRtd send_buf;
	int ret = read(confd, &buf, sizeof(buf));
	if(ret <= 0)
	{
		return -1;
	}

	send_buf.usr_order_msg = buf;
	send_buf.confd = confd;
	send_buf.usr_log_msg = conaddr;

	write(pfd[1], &send_buf, sizeof(send_buf));
	if(QUIT == send_buf.usr_order_msg.type)
	{
		exit(0);
	}
	return 0;
}

void init_node(pDtp *p)
{
	creat_memory((void **)p, sizeof(sDtp));
	(*p)->usr_log_msg.sin_addr.s_addr = 0;
	(*p)->usr_log_msg.sin_port = 0;
	(*p)->pid_fun = 0;
	(*p)->prev = *p;
	(*p)->next = *p;
}

int creat_msg_que()
{
	key_t key = ftok("/root", 'x');
	if(key < 0)
	{
		perror("ftok");
		return -1;
	}
	int msgid = msgget(key, IPC_CREAT|O_RDWR|0600);
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	return msgid;
}

void record(int fd, int msgid)
{
	daemon(0, 0);
	sMfile buf;
	while(1)
	{
		msgrcv(msgid, &buf, sizeof(buf)-sizeof(buf.type), 3, 0);
		write(fd, buf.msgbuf, strlen(buf.msgbuf));
	}
}
