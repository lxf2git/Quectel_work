#include"apue.h"
#include"microblog.h"
void register_data(SUer_basic_info *data)
{
	space();
	printf("昵称:");
	scanf("%s",data->s_nick_name);
	getchar();
	while(1)
	{
		space();
		printf("性别(男/女):");
		scanf("%s",data->s_sex);
		getchar();
		if(strcmp(data->s_sex,"男")==0 || strcmp(data->s_sex,"女")==0)
		{
			break;
		}
		space();
		printf("输入错误\n");
		bzero(data->s_sex,sizeof(data->s_sex));
	}
	while(1)
	{
		space();
		printf("年龄(1-99):");
		scanf("%d",&data->s_age);
		if(data->s_age>0&&data->s_age<100)
		{
			break;
		}
		space();
		printf("输入错误\n");
	}
}




/*void window()
{	
	int i;
	for(i=0; i<50; i++)
	{
		printf("                                           \n");
	}
	printf(" __________________________________________\n");
	printf("|_________________________________| _ 口 X |\n");
	printf("         欢迎使用史上最屌丝的微博          \n");
	printf("                                           \n");
	printf("                                           \n");
}*/

void login_window()
{
	clean_upground();
		space();
	printf(" ____________________________________     \n");
		space();
	printf("|                                    |    \n");
		space();
	printf("| ** 1 **                   用户登录 |    \n");
		space();
	printf("| ** 2 **                   用户注册 |    \n");
		space();
	printf("| ** 3 **                   退出微博 |    \n");
		space();
	printf("|____________________________________|    \n\n");
	clean_downground();
}



void input_user (PUser_basic_info data)
{	
	char *passwd = NULL;
	bzero(data, sizeof(*data));
	space();
	printf("用户名:");
	scanf("%s",data->s_user_name);
	getchar();
	passwd = getpass("                                     密码:");
	strcpy(data->s_passwd, passwd);
}


void register_user(PUser_basic_info data)
{
	bzero(data,sizeof( *data));
	char user_name[100];
	char *cre_passwd=NULL;
	int i;
create_user :
	while(1)
	{
		int num = 0;
		int ch_ = 0;
		int ch = 0;
		bzero(user_name,sizeof(user_name));
		space();
		printf("用户名\n");
		space();
		printf("(以字母,数字或下划线组成的6 — 12位用户名):\n");
		space();
		scanf("%s",user_name);
		getchar();
		if(strlen(user_name) > 5 && strlen(user_name) < 13)
		{
			for(i=0;i<strlen(user_name);i++)	
			{
				if( (user_name[i] != 95)
						&& !(user_name[i] > 96 && user_name[i] < 123) 
						&& !(user_name[i] > 64 && user_name[i] < 91) 
						&& !(user_name[i] > 47 && user_name[i] < 58) )			
				{
		space();
					printf("** 用户名创建失败,含有非法字符 **\n");
					goto create_user;
				}
				if( user_name[i] == 95)
				{
					ch_ = 1;
				}
				if( (user_name[i] >64 && user_name[i] < 91) || 
						(user_name[i] > 96 && user_name[i] < 123))	
				{
					ch = 1;
				}
				if( user_name[i] > 48 && user_name[i] < 58)
				{
					num = 1;
				}
			}
			if( (ch_ + ch + num) < 2)
			{
		space();
				printf("** 用户名创建失败,用户名由字母,数字或下划线组成 **\n");
				continue;
			}
			strcpy(data->s_user_name,user_name);
			break;
		}
		else
		space();
			printf("** 用户名创建失败,用户名长度不符 **\n");
	}
	while(1)
	{
		char *passwd=NULL;
		passwd = (char *)malloc(20*sizeof(char));
		bzero(passwd,20*sizeof(char));
		cre_passwd = getpass("                                     密码:");
		int i;
		for(i=0;i<strlen(cre_passwd);i++)
		{
			*(passwd+i) = *(cre_passwd+i);
		}
		cre_passwd = getpass("                                     确认密码:");
		if(strcmp(passwd,cre_passwd) == 0)
		{
			strcpy(data->s_passwd,passwd);
			break;
		}
		space();
		printf("** 密码输入不一致 **\n");
	}
	register_data(data);

}

int User_Login(PUser_basic_info data,int *ch)
{	
//	window();
	while(1)
	{
		login_window();
		space();
		scanf("%d",ch);
		getchar();
		switch(*ch)
		{
			case LOGIN:
				input_user(data);
				return LOGIN;
			case REGISTER:
				register_user(data);
				return REGISTER;
			case 3:
				exit(0);
			default:
		space();
				printf("** 输入错误,重新输入 **\n");
				break;
		}
	}
}
