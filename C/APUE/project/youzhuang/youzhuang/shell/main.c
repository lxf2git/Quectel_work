#include"main.h"

int main()
{
		char *username,hostname[50],path[200],*ppath=NULL,sign,cmd[200];
		memset(hostname,0,sizeof(hostname));
		gethostname(hostname,sizeof(hostname));
		getcwd(path,sizeof(path));
		ppath=strrchr(path,'/');
		username=getenv("USER");
		if(strcmp(username,"root")==0)
		{
				sign='#';
		}
		else
		{
				sign='$';
		}
		while(1)
		{
				memset(cmd, 0, sizeof(cmd));;
				if(strcmp(ppath,"/root")==0)
				{
						strcpy(ppath,"/~");
				}
				if(strcmp(ppath,"/")==0)
				{
						strcpy(ppath,"//");
				}
				printf("[%s@%s %s]%c ", username, hostname, ppath+1, sign);
				scanf("%[^\n]", cmd);
				getchar();
				if(cmd=="\0")
				{
						continue;
				}
				if(strncmp(cmd, "cd ", 3)==0)
				{
						chdir(cmd+3);
						getcwd(path, sizeof(path));
						ppath=strrchr(path, '/');
				}
				else if(findch(cmd, '=')==0)
				{
						env(cmd);
				}
				else
				{
						system(cmd);
				}
		}
		return 0;
}

void env(char *cmd)
{
		char *value,name[10];
		int len;
		memset(name,0,sizeof(name));
		value=strrchr(cmd, '=');
		len=strlen(cmd)-strlen(value);
		strncat(name, cmd, len);
		printf("%s!!",name);
		printf("%s!!",value+1);
		setenv(name,value+1,1);
}

int findch(char *str,char ch)
{
		while(*str!='\0')
		{
				if(*str=='=')
				{
						return 0;
				}
				str++;
		}
		return -1;
}
