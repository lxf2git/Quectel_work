#include"apue.h"
#include"struct.h"


        
void forget_passwd()
{
REPWD:
        bzero(&message,sizeof(message));
        bzero(puf,sizeof(puf));
        message.flag=FDPWD;
        printf("通过输入个人信息找回密码：\n");
        printf("请输入您的编号：\n");
        scanf("%d",&message.found_info.id);
        printf("请输入真实姓名：\n");
        scanf("%s",message.found_info.real_name);
        printf("请输入您的电话:\n");
        scanf("%s",message.found_info.telephone);
        printf("您的密保口令：\n");
        scanf("%d",&message.found_info.for_passwd);
        
        write(sockfd,&message,sizeof(message));
        usleep(500);
        read(sockfd,puf,sizeof(puf));
                if(puf[0]=='1')
                {
                        read(sockfd,&message,sizeof(message));
                        printf("确认成功，您的编号密码为：\n%d\n %s\n",message.login_info.id,message.login_info.passwd);
                        printf("请牢记!\n");
                        longjmp(FLAG,0);
                }       
                else    
                {
                        printf("输入错误！");
                          bzero(puf,sizeof(puf));
                        printf("#1# 重新输入\n#2# 退出\n");
                        scanf("%s",puf);
                        if(puf[0]=='1')
                                {goto REPWD;}
                        if(puf[0]=='2')
                                {longjmp(FLAG,0);}
                }               
}               


 void login()
{
        while(1)
        {
        bzero(puf,sizeof(puf));
        bzero(&message,sizeof(message));
        message.flag=LOGIN;
        printf("天使编号：\n");//输入登录信息
        scanf("%d",&message.login_info.id);
        printf("密码：\n");
        scanf("%s",message.login_info.passwd);
        getchar();
        write(sockfd,&message,sizeof(message));//传送编号密码
        bzero(&message,sizeof(message));
        sleep(1);
        read(sockfd,puf,sizeof(puf));//接受服务器验证的返回值
                
                if(puf[0]=='1')
                {       
                        break;
                }
                if(puf[0]=='2')
                {       
                        printf("编号或密码错误请重新输入！\n共三次机会\n");
                        i++;
                }       
                        if(i==3)
                        {       
                                printf("是否找回密码?\n#1# 是\n#2# 否\n");
                                scanf("%d",&m);
                                switch(m)
                                {       
                                        case 1: 
                                                forget_passwd();
							break;
                                        case 2:
                                                longjmp(FLAG,0);
							break;
                                }
                        }
        }
	bzero(&myinfo,sizeof(myinfo));
	usleep(5000);
	read(sockfd,&myinfo,sizeof(myinfo));
        printf(" 欢迎%s回到神域！\n\n ",myinfo. virtual_name);
}



