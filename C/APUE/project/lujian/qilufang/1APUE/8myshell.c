#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include<string.h>
void get_shellStr(char *str_shell);
char *get_dirNow(char *pwd_prev);
int func_setenv(char *arr)
{
	int ret=0;
	char name[40];
	memset(name,0,sizeof(name));
	char *value=(strchr(arr,'=')+1);
	strncpy(name,arr,strlen(arr)-strlen(value-1));
	ret=setenv(name,value,1);
	return ret;
}
int main()
{
	char cmd[1024];
	char str_shell[1024];
	puts("欢迎进入myshell！");
	while(1)
	{
		memset(str_shell,0,sizeof(str_shell));
		get_shellStr(str_shell);
		printf("%s",str_shell);

		memset(cmd,0,sizeof(cmd));
		scanf("%[^\n]",cmd);
		getchar();
		if(!strcmp(cmd,"shut"))
		{
			break;
		}
		if(!strncmp(cmd,"cd ",3))
		{
			if(!strcmp(cmd+3,".."))
			{
					chdir("..");
			}
			else
			chdir(cmd+3);
		}
		if(!strncmp(cmd,"USER=",4))
		{
			if(func_setenv(cmd))
			{
				perror("setenv");
			}
		}
		if(!strncmp(cmd,"HOSTNAME=",9))
		{
			if(func_setenv(cmd))
			{
				perror("setenv");
			}
		}
		else
		{
			system(cmd);
		}
	}
	puts("谢谢,欢迎下次使用！");
	return 0;
}
void get_shellStr(char *str_shell)
{
	int flag=0;
	char *pwd_now=NULL;
	char pwd_prev[1024];
	char *user_name=NULL;
	char *host_name=NULL;
	memset(pwd_prev,0,sizeof(pwd_prev));
	memset(str_shell,0,sizeof(str_shell));
	str_shell[0]='[';

	user_name=getenv("USER");
	strcat(str_shell,user_name);
	flag=strcmp(user_name,"root");

	str_shell[strlen(str_shell)]='@';

	host_name=getenv("HOSTNAME");
	strcat(str_shell,host_name);

	str_shell[strlen(str_shell)]=' ';
	getcwd(pwd_prev,sizeof(pwd_prev));
	pwd_now = get_dirNow(pwd_prev);
	strcat(str_shell,pwd_now);

	str_shell[strlen(str_shell)]=']';
	if(flag!=0)
	str_shell[strlen(str_shell)]='$';
	else
	str_shell[strlen(str_shell)]='#';
}
char *get_dirNow(char *pwd_prev)
{
	char *ptmp=pwd_prev;
	char *flag=NULL;
	while(*ptmp!='\0')
	{
		if(*ptmp=='/'&&*(ptmp+1)!='\0')
		{
			flag=ptmp;
		}
		ptmp++;
	}
	return flag+1;
}
