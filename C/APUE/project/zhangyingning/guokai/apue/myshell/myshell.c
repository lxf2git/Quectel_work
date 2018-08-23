#include"apue.h"

int main() 
{
	puts("my shell");
	char cmd[256];
	char cmd1[256];

	char buf1[1024];
	char buf2[1024];
	char buf3[1024];
	char buf4[1024];
	while(1)
	{
		int i=0;
		char *path_last;
		char *str_user = NULL;
		char *str_host = NULL;
		memset(cmd,0,sizeof(cmd));
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));
		memset(buf3,0,sizeof(buf3));
		memset(buf4,0,sizeof(buf4));
		getcwd(buf1,sizeof(buf1));
		path_last = strrchr(buf1,'/');
		str_host = getenv("HOSTNAME");
		str_user = getenv("USER");
		if(strcmp(str_user,"root")==0)
		{
			buf2[0]='#';
		}
		else
		{
			buf2[0]='$';
		}
		sprintf(buf4,"[%s@%s %s]%s",str_user,str_host,path_last+1,buf2);
		printf("%s",buf4);
		while((cmd[i]=getchar())!='\n')
		{
			i++;
		}
		while(cmd[0]==0)
		{
			memset(cmd1,0,sizeof(cmd1));
			for(i=0;i<255;i++)
			{
				cmd1[i]=cmd[i+1];
			}
			memset(cmd,0,sizeof(cmd));
			for(i=0;i<255;i++)
			{
				cmd[i]=cmd1[i];
			}
		}
		if(strcmp(cmd,"go\n")==0)
		{
			break;
		}
		if(cmd[0]=='c'&&cmd[1]=='d')
		{
			cmd[strlen(cmd)-1]='\0';
			chdir(cmd+3);
		}
		else
		{	
			system(cmd);
		}
	}	
	return 0; 
}
