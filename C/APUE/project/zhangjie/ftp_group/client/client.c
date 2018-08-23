#include"../main.h"

int connect_fun(char *p);
int choose();
int udp_fun();
void ls_fun(int confd, int judge);
int put_fun(int sockfd, int confd, int judge,  char *file);
void get_fun(int confd, int judge, char *file);
void judge_fun(int confd, int judge);
void pwd_fun(int confd, int judge);

int main(int argc, char **argv)
{
	if(2 != argc)
	{
		printf("%s ip\n", argv[0]);
		return -1;
	}
	int judge;
	int fun;
	char file[100];          
	sCts usr_order;
	usr_order.type = LOGIN;
	printf("please input usrname:");
	scanf("%s", usr_order.uFg.ftp_cli_login.ftp_usrname);
	char *p = getpass("please input passwd:");
	strcpy(usr_order.uFg.ftp_cli_login.ftp_passwd,p);

	int sockfd = connect_fun(argv[1]);
	write(sockfd, &usr_order, sizeof(usr_order));
	int confd = udp_fun();
	recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
	if(-1 == judge)
	{
		printf("login fail\n");
		exit(-1);
	}
	else
	{
		puts("success");
	}
	while(1)
	{
		fun = 0;
		bzero(&usr_order, sizeof(usr_order));
		bzero(file, sizeof(file));
		fun = choose();
		usr_order.type = fun;
		switch(fun)
		{
			case LS ://int char
				write(sockfd, &usr_order, sizeof(usr_order));
				ls_fun(confd, judge);
				break;
			case  PUT://int char
				scanf("%s", file);
				strcpy(usr_order.uFg.ftp_put_file, file);
				write(sockfd, &usr_order, sizeof(usr_order));
				put_fun(sockfd, confd, judge, file);
				break;
			case GET ://int char
				scanf("%s", file);
				strcpy(usr_order.uFg.ftp_get_file, file);
				write(sockfd, &usr_order, sizeof(usr_order));
				get_fun(confd, judge, file);
				break;
			case CD ://int
				scanf("%s", file);
				strcpy(usr_order.uFg.ftp_cd_path, file);
				write(sockfd, &usr_order, sizeof(usr_order));
				judge_fun(confd, judge);
				break;
			case PWD ://int char
				write(sockfd, &usr_order, sizeof(usr_order));
				pwd_fun(confd, judge);
				break;
			case MKDIR ://int
				scanf("%s", file);
				puts(file);
				strcpy(usr_order.uFg.ftp_mkdir_path, file);
				write(sockfd, &usr_order, sizeof(usr_order));
				judge_fun(confd, judge);
				break;
			case QUIT ://int
				write(sockfd, &usr_order, sizeof(usr_order));
				recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
				if(judge == 0)
				{
					exit (0);
				}
				break;
			deault:
				printf("no order\n");
				break;
		}
	}
	return 0;
}

int connect_fun(char *p)
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("sockfd");
		return -1;
	}
	struct sockaddr_in conaddr;
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5556);
	conaddr.sin_addr.s_addr = inet_addr(p);
	int ret = connect(sockfd, (struct sockaddr*)&conaddr, sizeof(conaddr));
	if(ret < 0)
	{
		close(sockfd);
		perror("connect");
		exit(-1);
	}
	return sockfd;
}
int udp_fun()
{
	int confd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in seladdr;
	seladdr.sin_family = AF_INET;
	seladdr.sin_port = htons(8888);
	seladdr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(confd, (struct sockaddr *)&seladdr, sizeof(seladdr));
	return confd;
}
int choose()
{
	char order[10];
	bzero(order, sizeof(order));
	printf("ftp > ");
	scanf("%s", order);
	char order_gather[7][10] = {"ls", "put", "get", "cd", 
			"pwd", "mkdir", "quit"};
	int i;
	for(i = 0; i < 7; i++)
	{
		if(strcmp(order_gather[i], order) == 0)
		{
			return i+1;
		}
	}
}

void ls_fun(int confd, int judge)
{
	char buf_ret[1024] = {"\0"};
	recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
	if(judge == FAILURE)
	{
		printf("fail");
	}
	else if(judge == 0)
	{
		while(1)
		{
			recvfrom(confd, buf_ret, sizeof(buf_ret), 0, NULL, NULL);
			if(strcmp(buf_ret, "null") == 0)
			{
				bzero(buf_ret, sizeof(buf_ret));
				break;
			}
			printf("%s",buf_ret);
			fflush(stdout);
			bzero(buf_ret, sizeof(buf_ret));
		}
	}
}

int put_fun(int sockfd, int confd, int judge, char *file)
{
	struct sockaddr_in conaddr;
	bzero(&conaddr, sizeof(conaddr));
	socklen_t len = sizeof(conaddr);
	recvfrom(confd, &judge, sizeof(int), 0, (struct sockaddr*)&conaddr, &len);
	if(judge == -1)
	{
		puts("fail");
		return -1;
	}
	else
	{
		puts("sucess");
		char buf_ret[1024] = {"\0"};
		int fd = open(file, O_RDONLY);
		while(1)
		{
			bzero(buf_ret, sizeof(buf_ret));
			int ret = read(fd, buf_ret, sizeof(buf_ret));	
			if(ret <= 0)
			{
				sendto(confd, "null", 5, 0,  (struct sockaddr*)&conaddr, len);
				break;
			}
			sendto(confd, buf_ret, sizeof(buf_ret), 0,  (struct sockaddr*)&conaddr, len);
		}
	}
	return 0;	
}

void get_fun(int confd, int judge, char *file)
{
	char buf_ret[1024] = {"\0"};
	recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
	if(judge == -1)
	{
		puts("fail");
	}
	else
	{
		puts("sucess");
		int fd = open(file, O_CREAT|O_EXCL|O_RDWR, 0777);
		while(1)
		{
			recvfrom(confd, buf_ret, sizeof(buf_ret), 0, NULL, NULL);
			if(strcmp(buf_ret, "null") == 0)
			{
				bzero(buf_ret, sizeof(buf_ret));
				break;
			}
			write(fd, buf_ret, sizeof(buf_ret));
			bzero(buf_ret, sizeof(buf_ret));
		}
		close(fd);
	}
}

void judge_fun(int confd, int judge)
{
	recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
	if(judge == -1)
	{
		puts("fail");
	}
	else
	{
		puts("success");
	}	
}

void pwd_fun(int confd, int judge)
{
	char buf_ret[1024] = {"\0"};
	recvfrom(confd, &judge, sizeof(int), 0, NULL, NULL);
	if(judge == -1)
	{
		puts("fail");
	}
	else
	{
		while(1)
		{
			recvfrom(confd, buf_ret, sizeof(buf_ret), 0, NULL, NULL);
			if(strcmp(buf_ret, "null") == 0)
			{
				bzero(buf_ret, sizeof(buf_ret));
				break;
			}
			if(buf_ret[0] != '\0')
			{
				printf("%s\n",buf_ret);
			}
			bzero(buf_ret, sizeof(buf_ret));
		}
	}
}
