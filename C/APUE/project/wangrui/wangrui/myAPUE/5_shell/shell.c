#include"../apue.h"

void print_title( void );
void get_dirname(char *crrDirName);

int main()
{
	char cmd[256];
	char tmp[256];
	int ret;

	puts("welcome to my shell");
	while(1)
	{
		//头
		print_title();
		bzero(cmd,256);
		scanf("%[^\n]",cmd);
		getchar();
		//eixt退出
		if(!strcmp(cmd,"exit"))
		{
			break;
		}
		//cd处理
		if(strncmp(cmd,"cd ",3) == 0)
		{	
			system(cmd);
			if(cmd[3] == '\0')
			{
				chdir("/root");
			}
			else
			{
				ret = chdir(cmd+3);
				if(ret<0)
				{
					perror("cd");
				}
			}
			continue;
		}
		//ls
		if(strncmp(cmd,"ls",2) == 0)
		{
			bzero(tmp,256);
			strcpy(tmp,cmd+3);
			bzero(cmd,256);
			strcpy(cmd,"ls --color ");
			strcat(cmd,tmp);
		}
		system(cmd);
	}

	puts("thank you for using my shell");
}
void print_title( void )
{
	char userSign;
	char crrDirName[256];
	bzero(crrDirName,256);
	if(strcmp(getenv("USER"),"root") == 0)
	{
		userSign = '#';
	}
	else
	{
		userSign = '$';
	}
	getcwd(crrDirName,256);
	get_dirname(crrDirName);
	printf("[%s@%s %s]%c ",getenv("USER"),getenv("HOSTNAME"),crrDirName,userSign);
}
void get_dirname(char *crrDirName)
{
	char tmp[256] = {};
	int i=0,j=0;
	getcwd(crrDirName,256);
	while((crrDirName)[i] != 0)
	{
		if(crrDirName[i] == '/')
		{
			bzero(tmp,256);
			j = 0;
			i++;
			continue;
		}
		tmp[j] = crrDirName[i];
		j++;
		i++;
	}
	if(strcmp(tmp,"root")==0)
	{
		strcpy(tmp,"~");
	}
	if(strcmp(tmp,"")==0)
	{
		strcpy(tmp,"/");
	}
	strcpy(crrDirName,tmp);
}
