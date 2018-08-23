#include"apue.h"
#include"struct.h"

void personal()
{
	while(1)
	{
	printf("#1# 显示个人信息\n#2# 修改个人信息\n#3# 返回上一层\n");
	int d=0;
	scanf("%d",&d);
	switch(d)
		{
			case 1:
				printf("********************\n");
				printf("昵称:%s\n",myinfo.virtual_name);
				printf("姓名:%s\n",myinfo.real_name);
				printf("生日:%s\n",myinfo.birthday);
				printf("年龄:%d\n",myinfo.age);
				printf("性别:%s\n",myinfo.gender);
				printf("VIP %c 级\n",myinfo.vip);
				printf("电话：%s\n",myinfo.telephone_num);
				printf("********************\n");
				break;
			case 2:
				 bzero(&message,sizeof(message));
				 message.flag=CHINFO;
				 bzero(&apply,sizeof(apply));
				printf("请输入修改后的信息:\n");
				printf("昵称:");
				scanf("%s",message.apply_info.virtual_name);
				strcpy(myinfo.virtual_name,message.apply_info.virtual_name);
				printf("姓名:");
				scanf("%s",message.apply_info.real_name);
				strcpy(myinfo.birthday,message.apply_info.real_name);
				printf("生日:");
				scanf("%s",message.apply_info.birthday);
				strcpy(myinfo.birthday,message.apply_info.birthday);
				printf("性别：");
				scanf("%s",message.apply_info.gender);
				strcpy(myinfo.gender,message.apply_info.gender);
				printf("年龄:");
				scanf("%d",&message.apply_info.age);
				myinfo.age = message.apply_info.age;
				printf("密码:");
				scanf("%s",message.apply_info.passwd);
				printf("电话：");
				scanf("%s",message.apply_info.telephone);
				strcpy(myinfo.telephone_num,message.apply_info.telephone);
				write(sockfd,&message,sizeof(message));
				bzero(puf,sizeof(puf));
				read(sockfd,puf,sizeof(puf));
					if(puf[0]=='1')
					{printf("修改成功！\n");}
					else
					printf("修改失败！\n");
				break;
			case 3:
				break;
			default :
				printf("输入错误！\n");
				break;
		}
			if(d==3)
				break;
	}
	
}


void showfriends()
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
	
}
 

void talk_friend()
{
	bzero(&message,sizeof(message));
	message.flag=FTALK;
	printf("请输入对方的编号：");
	scanf("%d",&message.login_info);
	write(sockfd,&message,sizeof(message));
	
	printf("正在等待好友回复请求，按回车继续操作 ^_^\n");
	
	getchar();
	getchar();
}

void add_friend()
{
	bzero(&message,sizeof(message));
	message.flag=ADDFD;
	printf("请输入添加好友的编号：");
	scanf("%d",&message.login_info);
	write(sockfd,&message,sizeof(message));
	usleep(5000);
	//bzero(puf,sizeof(puf));
	//read(sockfd,puf,sizeof(puf));
	//if(puf[0]=='1')
	//	printf("添加好友成功！\n");
	//if(puf[0]=='2')
	//	printf("不存在此账户\n");
}


void delet_friend()
{
	bzero(&message,sizeof(message));
	message.flag=DELFD;
 	printf("请输入要删除好友的编号：");
 	scanf("%d",&message.login_info);
 	write(sockfd,&message,sizeof(message));
 	usleep(5000);
 	bzero(puf,sizeof(puf));
	read(sockfd,puf,sizeof(puf));
 	if(puf[0]=='1')
 	        printf("添加好友成功! *_*\n");
	 if(puf[0]=='2')
	         printf("不存在此账户! * = *\n");


}




