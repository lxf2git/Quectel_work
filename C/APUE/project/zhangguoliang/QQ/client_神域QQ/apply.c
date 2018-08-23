#include"apue.h"
#include"struct.h"

void myapply()
{
REPLLY:
	bzero(&message,sizeof(message));
	message.flag=APPLY;
	printf("请输入以下注册信息\n");
	printf("您的真实姓名：");
	scanf("%s",message.apply_info.real_name);
	printf("您的天使昵称：");
	scanf("%s",message.apply_info.virtual_name);
	printf("您的电话号码：");
	scanf("%s",message.apply_info.telephone);
	printf("您的生日：");
	scanf("%s",message.apply_info.birthday);
	printf("您的年龄：");
	scanf("%d",&message.apply_info.age);
	printf("您的登录密码：");
	scanf("%s",message.apply_info.passwd);
	printf("您的密保数字口令用于找回密码：");
	scanf("%d",&message.apply_info.for_passwd);
	printf("您的性别：");
	scanf("%s",message.apply_info.gender);
	printf("输入完成，申请中.........\n");
	write(sockfd,&message,sizeof(message));
	sleep(1);
	bzero(&data,sizeof(data));
	read(sockfd,&data,sizeof(data));
	if(sizeof(data.id)==0)
		{
			printf("申请失败请重新输入\n");
			goto REPLLY;
		}
		else
			printf("注册成功！\n");
	printf("您的编号为：");
	printf("%d\n",data.id);
	printf("请牢记上帝分配给您的编号及密码！\n\n");
	printf("您已成功注册成为天使$ %s $",data.virtual_name);
	printf("欢迎来到神域^_^\n");
}
