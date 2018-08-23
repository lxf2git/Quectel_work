#include"apue.h"
int que_all(struct cli_pakg client,int say)
{
		bzero(&client.cliTser.req.que_buf,sizeof(client.cliTser.req.que_buf));
		char start_add[20];
		char end_add[20];
		client.cliTser.cmd = QUE_TKT;
		int flag = 0;
		int i=0;
		while(1)
		{
				if(i>0)
				{
						puts("0--》返回，其他--》重新输入！");
						scanf("%d",&flag);
						getchar();
						if(flag==0)
						{
								return 0;
						}
				}
				i++;
				bzero(end_add,sizeof(end_add));
				bzero(start_add,sizeof(start_add));
				if(say==QUE)
				{

						printf("%s输入查询火车票的起始地址： %s",colo.red,colo.end);
				}
				if(say==CHANGE)
				{
						printf("%s输入要改签火车票的起始地址（买）： %s",colo.yell,colo.end);
				}
				scanf("%s",start_add);
				getchar();
				flag = change(start_add);
				if(flag==0)
				{
						puts("input err!");
						continue;
				}
				if(say==QUE)
				{
						printf("%s输入查询火车票的终止地址： %s",colo.red,colo.end);
				}
				if(say==CHANGE)
				{
						printf("%s输入要改签火车票的终止地址（买）： %s",colo.yell,colo.end);
				}
				scanf("%s",end_add);
				flag = change(end_add);
				if(flag==0)
				{
						puts("input err!");
						continue;
				}
				break;
		}
		bzero(client.cliTser.req.que_buf,sizeof(client.cliTser.req.que_buf));
		sprintf(client.cliTser.req.que_buf,"%s-%s",start_add,end_add);
		if(sendto(client.fd,&client.cliTser,sizeof(client.cliTser),0,(struct sockaddr*)&client.seraddr,sizeof(struct sockaddr_in))<0)
		{
				show_err("sendto_que_all");
		}

		struct ser_cli_pakg serTcli;
		bzero(&serTcli,sizeof(serTcli));
		if(recvfrom(client.fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
		{
				show_err("recv_que_all");
		}
		if(serTcli.cmd==QUE_ERR)
		  {
		    printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);
		    return 0;
		  }
		if(serTcli.cmd!=QUE_ERR)
		{	    
				char *output = change_que(serTcli.ret.reg_buf,1);
				if(output!=NULL)
				{
						printf("%s%s\n%s",colo.violet,output,colo.end);
						return 1;
				}
				/*	else
				  	printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);*/
		}
		//printf("%s%s\n%s",colo.red,serTcli.ret.reg_buf,colo.end);
		return 0;
}
char * change_que(char *str,int flag)
{
  // printf("%s\n",str);
		static char output[1024];
		char *fir_flag = strchr(str,':');
		char *sec_flag = strchr(str,'-');
		char *thd_flag = strrchr(str,':');
		if(fir_flag==NULL||sec_flag==NULL)
		{
				return NULL;
		}
	if(flag==1)
	  {
		bzero(output,sizeof(output));
	       	strcpy(output,"车次>");
		strncat(output,str,strlen(str)-strlen(fir_flag)+1);
		strcat(output," 起始>");
		strncat(output,fir_flag+1,strlen(fir_flag+1)-strlen(sec_flag)+1);
		strcat(output," 终止>");
		strncat(output,sec_flag+1,strlen(sec_flag+1)-strlen(thd_flag));
				strcat(output,"  余票");
				strcat(output,thd_flag);
	  }
	if(flag==0)
	  {
		bzero(output,sizeof(output));
		strcpy(output,"Name>");
		strncat(output,str,strlen(str)-strlen(fir_flag)+1);//sec_flag
		strcat(output," 车次");
		strncat(output,fir_flag+1,strlen(fir_flag+1)-strlen(thd_flag)+1);//thd_flag
		strcat(output," 起始>");
		strncat(output,thd_flag,strlen(thd_flag)-strlen(sec_flag));
		strcat(output," 终止>");
		strcat(output,sec_flag+1);
	  }
		return (char *)output;
}
int que_ord(struct cli_pakg client)
{
		bzero(&client.cliTser.req.que_buf,sizeof(client.cliTser.req.que_buf));
		if(client.cliTser.flag==LOG_SUC)
		{
				puts("您定的车票有：");
		}
		client.cliTser.cmd = QUE_ORDER;
		if(sendto(client.fd,&client.cliTser,sizeof(client.cliTser),0,(struct sockaddr*)&client.seraddr,sizeof(struct sockaddr_in))<0)
		{
				show_err("sendto_que_all");
		}
		struct ser_cli_pakg serTcli;
		char *output;
		while(1)
		{
				bzero(&serTcli,sizeof(serTcli));
				if(recvfrom(client.fd,&serTcli,sizeof(serTcli),0,NULL,NULL)<0)
				{
						show_err("recv_que_all");
				}
				if(serTcli.cmd==QUE_ERR)
				  {


				     printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);
				    return 0;
				  }
				if(serTcli.cmd!=QUE_ERR)
				{	    
						output = change_que(serTcli.ret.reg_buf,0);
						if(output!=NULL)
						{
								printf("%s%s\n%s",colo.violet,output,colo.end);
						}
						//	else
						  // printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);
				}
				else
						printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);
				if(serTcli.cmd==QUE_OVER||serTcli.cmd==QUE_ERR)
				{
				  // printf("%s%s\n%s",colo.violet,serTcli.ret.reg_buf,colo.end);
						break;
				}
		}
		return 1;
}
int change(char *add)
{
		int i=0;
		while(add[i]!='\0')
		{
				if(add[i]<65||(add[i]<97&&add[i]>90)||add[i]>122)
				{
						return 0;
				}
				if(add[i]>65&&add[i]<97)
				{
						add[i]+=32;
				}
				i++;
		}
		return 1;
}
