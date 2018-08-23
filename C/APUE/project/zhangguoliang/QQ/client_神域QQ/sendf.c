#include"apue.h"
#include"struct.h"

void sendf()
{
	printf("您的好友列表：\n");
	printf("******************************\n");
	bzero(&message,sizeof(message));
	message.flag=SHOWF;
	write(sockfd,&message,sizeof(message));//传送要显示好友列表的命令
	usleep(5000);
	while(1)
	{
	        read(sockfd,&lsfd,sizeof(lsfd));
	        if(lsfd.is_on=='\0')
	                break;
	        printf("%d  %s        ",lsfd.id,lsfd.virtual_name);
	        if(lsfd.is_on=='1')
	                {printf("on\n");}
	        if(lsfd.is_on=='0')
	                {printf("off\n");}
	}
	        printf("\n");
	printf("******************************\n");
	printf("请输入对方编号：");
	scanf("%d",&message.login_info.id);
	printf("好友在线传输请按#1#，离线功能传输请#2#\n");
	scanf("%s",puf);
	if(puf[0]=='1')
	{	
	message.flag=SENDFILE;
	write(sockfd,&message,sizeof(message));
	printf("等待对方确定接受........\n");
	}
	else if(puf[0]=='2')
	{
	message.flag=LXSENDF;
	write(sockfd,&message,sizeof(message));
	printf("等待服务器接受......\n");
	}
	else
	{printf("输入错误\n");}
}


