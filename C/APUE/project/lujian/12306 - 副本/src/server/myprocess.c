#include"P12306.h"
void *myprocess(void *arg)
{
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	switch(argv->recv_pakg.cmd)
	{
		case REGISTER:
				my_register(argv);
				break;
		case LOGIN:
				my_login(argv);
				break;
		case QUE_TKT:
				my_que_tkt(argv);
				break;
		case QUE_ORDER:
				my_que_order(argv);
				break;
		case ORD_TKT:
				my_ord_tkt(argv);
				break;
		case BACK_TKT:
				my_back_tkt(argv);
				break;
	}
}
void my_register(void *arg)//注册
{
	printf("********1**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	struct ser_cli_pakg ser_cli_info;
	bzero(&ser_cli_info,sizeof(ser_cli_info));
	int judgeret;
	judgeret = db_add_user(argv->recv_pakg.user.username,argv->recv_pakg.user.userpasswd);
	printf("%d \n",judgeret);
	if(judgeret == FALSE)
	{
		ser_cli_info.cmd= REG_ERR;
		sprintf(ser_cli_info.ret.reg_buf,"%s","The username exist.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));
	}
	else
	{
		ser_cli_info.cmd= REGISTER;
		sprintf(ser_cli_info.ret.reg_buf,"%s","The user add success.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
	}
	free(argv);
}
void my_login(void *arg)//登录
{
	printf("********2**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	char passwdbuf[20];
	bzero(&passwdbuf,sizeof(passwdbuf));
	struct ser_cli_pakg ser_cli_info;
	bzero(&ser_cli_info,sizeof(ser_cli_info));
	int judgeret;	
	judgeret = db_user_passwd(argv->recv_pakg.user.username,passwdbuf);
	if(judgeret == FALSE)
	{
		ser_cli_info.cmd= LOG_ERR;
		sprintf(ser_cli_info.ret.reg_buf,"%s","The username not exist.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));
	}
	else
	{

		if((strcmp(passwdbuf,argv->recv_pakg.user.userpasswd)) != TRUE)
		{	
		  	ser_cli_info.cmd = LOG_ERR;	
			sprintf(ser_cli_info.ret.reg_buf,"%s","The user passwd is error.");
			sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
		}
		else 
		{
			ser_cli_info.cmd = LOGIN;
			ser_cli_info.flag = LOG_SUC;
			sprintf(ser_cli_info.ret.reg_buf,"%s","The user login success.");
			sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));			
		}
	}
	free(argv);
}
void my_que_tkt(void *arg) //查询票
{
	printf("********3**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	char databuf[1024];
	bzero(databuf,sizeof(databuf));
	struct ser_cli_pakg ser_cli_info;
	bzero(&ser_cli_info,sizeof(ser_cli_info));
	int judgeret;	
	judgeret = db_train_info(argv->recv_pakg.req.que_buf,databuf);
	if(judgeret == FALSE)
	{
		ser_cli_info.cmd= QUE_ERR;
   		sprintf(ser_cli_info.ret.que_buf,"%s","The train number temporary create.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));
	}
	else
	{
		ser_cli_info.cmd= QUE_TKT;
		sprintf(ser_cli_info.ret.que_buf,"%s",databuf);
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
	}
	free(argv);
}
void my_ord_tkt(void *arg)//订票
{
	printf("********4**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	struct ser_cli_pakg ser_cli_info;
	bzero(&ser_cli_info,sizeof(ser_cli_info));
	int judgeret;	
	if(argv->recv_pakg.flag == LOG_UNSUC)
	{
		ser_cli_info.cmd= ORD_ERR;
		sprintf(ser_cli_info.ret.ord_buf,"%s","Please earlier LOGIN.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
		free(argv);
		return ;
	}
	if(argv->recv_pakg.flag == LOG_SUC)
	{
			judgeret = db_ticket_num(argv->recv_pakg.req.ord_num);
			if(judgeret == 0)
			{
					ser_cli_info.cmd= ORD_ERR;
					sprintf(ser_cli_info.ret.ord_buf,"%s","The ticket already sell out.");
					sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
					return ;
			}	
			else
			{
					printf("[ %s =  %d]\n", __FUNCTION__, __LINE__); 
					db_add_ticket(argv->recv_pakg.user.username,argv->recv_pakg.req.ord_num);
					ser_cli_info.cmd = ORD_TKT;
					sprintf(ser_cli_info.ret.ord_buf,"%s","Book the ticket success,please as soon as possible to TEAM4 get.");
					sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
					db_change_train(argv->recv_pakg.req.ord_num,'-');
			}	
	}
	free(argv);
}
void my_que_order(void *arg)//查询订票
{
	printf("********5**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	struct ser_cli_pakg ser_cli_info;
	if(argv->recv_pakg.flag == LOG_UNSUC)
	{
		bzero(&ser_cli_info,sizeof(ser_cli_info));
		ser_cli_info.cmd= QUE_ERR;
		sprintf(ser_cli_info.ret.ord_buf,"%s","Please earlier LOGIN.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
		free(argv);
		return ;
	}
	char tickbuf[1024];
	bzero(tickbuf,sizeof(tickbuf));
	int judgeret;	
	judgeret = db_user_info(argv->recv_pakg.user.username,tickbuf);
	if(strlen(tickbuf) == 0)
	{
		ser_cli_info.cmd= QUE_ERR;
		sprintf(ser_cli_info.ret.ord_buf,"%s","The user not buy ticket.");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
		free(argv);
		return ;
	}
	char *p;
	char *q = tickbuf;
	char place[1024];
	while(1)
	{
			memset(place,0,sizeof(place));
			bzero(&ser_cli_info,sizeof(ser_cli_info));
			p = strrchr(q,':');
			if(NULL == p)
			{
					ser_cli_info.cmd= QUE_OVER;
					sprintf(ser_cli_info.ret.ord_buf,"%s","Query finish");
					sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
					free(argv);
					return ;
			}
			db_ticket_place(p+1,place);
			ser_cli_info.cmd= QUE_ORDER;
			sprintf(ser_cli_info.ret.ord_buf,"%s:%s:%s",argv->recv_pakg.user.username,p+1,place);
			sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
			*p = '\0';
	}
}
void my_back_tkt(void *arg)//退票
{
	printf("********6**********\n");
	struct ser_deal_pakg *argv = (struct ser_deal_pakg*)arg;
	struct ser_cli_pakg ser_cli_info;
	bzero(&ser_cli_info,sizeof(ser_cli_info));
	if(argv->recv_pakg.flag == LOG_UNSUC)
	{
		ser_cli_info.cmd= BACK_ERR;
		sprintf(ser_cli_info.ret.ord_buf,"%s","Please earlier LOGIN");
		sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));	
		free(argv);
		return ;
	}
	int judgeret;	
	judgeret = db_del_ticket(argv->recv_pakg.user.username,argv->recv_pakg.req.ord_num);
	if(judgeret < 0)
	{
					ser_cli_info.cmd = BACK_ERR;
					sprintf(ser_cli_info.ret.ord_buf,"%s","You not buy the ticket");
					sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));
					return ;	
	}
	ser_cli_info.cmd = BACK_TKT;
	sprintf(ser_cli_info.ret.ord_buf,"%s","Back ticket success");
	sendto(argv->sockfd,&ser_cli_info,sizeof(ser_cli_info),0,(struct sockaddr* )&argv->cli_ip,sizeof(argv->cli_ip));
	db_change_train(argv->recv_pakg.req.ord_num,'+');
	free(argv);
}
