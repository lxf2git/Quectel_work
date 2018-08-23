#include"apue.h"
void reg_user(struct cli_pakg *client)
{
		struct ser_cli_pakg serTcli;
		while(1)
		{
				bzero(&(client->cliTser),sizeof(client->cliTser));
				client->cliTser.cmd = REGISTER;
				puts("input username(reg):");
				scanf("%s",client->cliTser.user.username);
				getchar();
				puts("input passwd(reg):");
				scanf("%s",client->cliTser.user.userpasswd);
				if(sendto(client->fd,&client->cliTser,sizeof(client->cliTser),0,(struct sockaddr*)&client->seraddr,sizeof(struct sockaddr_in))<0)
				{
						show_err("sendto_reg");
				}
				bzero(&serTcli,sizeof(serTcli));
				if(recvfrom(client->fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
				{
						show_err("recv_reg");
				}
				puts(serTcli.ret.reg_buf);
				if(serTcli.flag!=REG_ERR)
				{
						break;
				}
		}
}
void user_login(struct cli_pakg *client)
{
		struct ser_cli_pakg serTcli;
		bzero(&(client->cliTser),sizeof(client->cliTser));
		client->cliTser.cmd = LOGIN;
		puts("input username(log):");
		scanf("%s",client->cliTser.user.username);
		puts("input passwd(log):");
		scanf("%s",client->cliTser.user.userpasswd);
		if(sendto(client->fd,&client->cliTser,sizeof(client->cliTser),0,(struct sockaddr*)&client->seraddr,sizeof(struct sockaddr_in))<0)
		{
				show_err("sendto_log");
		}
		bzero(&serTcli,sizeof(serTcli));
		if(recvfrom(client->fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
		{
				show_err("recv_log");
		}
		puts(serTcli.ret.reg_buf);
		if(serTcli.flag==LOG_SUC)
		{
				client->cliTser.flag = LOG_SUC;
		}
		else
		{
				client->cliTser.flag = LOG_UNSUC;
		}

}
