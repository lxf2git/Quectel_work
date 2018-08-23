#include"apue.h"

int ord_tick(struct cli_pakg client,int say)
{
		struct ser_cli_pakg serTcli;
		if(say==ORD)
		{
				printf("%s请输入要订票的车次：\n%s",colo.blue,colo.end);
		}
		if(say==CHANGE)
		{
				printf("%s请输入要改签（买）票的车次\n%s",colo.gren,colo.end);
		}
		client.cliTser.cmd = ORD_TKT;
		bzero(client.cliTser.req.ord_num,sizeof(client.cliTser.req.ord_num));
		scanf("%s",client.cliTser.req.ord_num);
		char *p = strstr(tick,client.cliTser.req.ord_num);
		if(NULL ==p)
		  {
		    printf("input ticket number error\n");
		    return 0;
		  }
		if(sendto(client.fd,&client.cliTser,sizeof(client.cliTser),0,(struct sockaddr*)&client.seraddr,sizeof(struct sockaddr_in))<0)
		{
				show_err("sento_order");
		}
		bzero(&serTcli,sizeof(serTcli));
		if(recvfrom(client.fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
		{
				show_err("recv_order");
		}
		puts(serTcli.ret.ord_buf);
		if(serTcli.cmd==ORD_ERR)
		  {
		    return 0;
		  }
		return 1;
}

int ret_tick(struct cli_pakg client,int say)
{
		int flag = 0;
		char start_add[20];
		char end_add[20];
		struct ser_cli_pakg serTcli;
		if(say==RET)
		{
				printf("%s请输入要退票的车次：\n%s",colo.blue,colo.end);
		}
		if(say==CHANGE)
		{

				printf("%s请输入要改签（退）票的车次\n%s",colo.gren,colo.end);
		}



		client.cliTser.cmd = BACK_TKT;
		bzero(client.cliTser.req.ord_num,sizeof(client.cliTser.req.ord_num));
	 	scanf("%s",client.cliTser.req.ord_num);
		if(strstr(tick,client.cliTser.req.ord_num) ==NULL)
		  {
		    printf("input ticket number error\n");
		    return 0;
		  }	

		if(sendto(client.fd,&client.cliTser,sizeof(client.cliTser),0,(struct sockaddr*)&client.seraddr,sizeof(struct sockaddr_in))<0)
		{
				show_err("sendto_return");
		}
		bzero(&serTcli,sizeof(serTcli));
		if(recvfrom(client.fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
		{
				show_err("recv_return");
		}
		puts(serTcli.ret.ord_buf);
		if(serTcli.cmd == BACK_ERR)
		{
				return 0;
		}
		return 1;
}
