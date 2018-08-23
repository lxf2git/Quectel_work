
#include"../apue.h"
#include <string.h>
#include <stdlib.h>
int show_window();
int cmd_deal();
		char buf_env[10];
int main()
{
		while(1)
		{
				show_window();
				cmd_deal();
		}
		return 0;

}


int show_window()
{
		char show_buf[1024];
		char dir_buf[1024];
		memset(show_buf,0,sizeof(show_buf));
		memset(dir_buf,0,sizeof(dir_buf));
		sprintf(show_buf,"[%s@good boy@%s]#",getenv("USER"),getcwd(dir_buf,sizeof(dir_buf)));
		printf("%s ",show_buf);
		fflush(NULL);

		return 0;
}


int cmd_deal()
{
		char *pEnv;

		char cmd[10];
		char buf_cmd[1024];
		char argument[1024];
		char buf[1024];
		int ret_access=0;
		int ch;
		memset(cmd,0,sizeof(cmd));
		memset(buf_cmd,0,sizeof(cmd));
		memset(argument,0,sizeof(cmd));
		memset(buf,0,sizeof(cmd));
		ch =getchar();
		if(ch == '\n')
				return 0;
		else
				ungetc(ch,stdin);
		scanf("%s",cmd);

		if( getchar() != '\n')
		{
				scanf("%[^\n]",argument);
				getchar();
		}

		if(!strcmp(cmd,"exit"))
		{
				exit (0);
		}
		else
				if((pEnv = strchr(cmd,'='))!=NULL)
				{
						int ret = 1;
						strcpy(buf_env,cmd);
						//		puts(buf_env);
						//		setenv(cmd,pEnv+1,0);
						ret = putenv(buf_env);
						if(ret != 0)
						{
								perror("purenv");
						}
						//	system("env");

						//	puts(cmd);
						//		*pEnv='\0';
						//		puts(cmd);
						//	printf("*%s",cmd);
						//			if(getenv(cmd+1) !=NULL)			
						//		printf("%p\n",getenv(cmd));


				}
				else

						if(!strncmp(cmd,"cd",2))
						{
								chdir(argument);
						}
						else
						{

								if(cmd[0] != '/')
										sprintf(buf_cmd,"/home/apue/shell/my%s",cmd);
								ret_access = access(buf_cmd,F_OK);
								if(ret_access == -1)
								{
										printf("%s dont find from /home/apue/shell\n",cmd);
										return -1;
								}
								sprintf(buf,"%s %s",buf_cmd,argument);

								printf("%s\n",buf);
								system(buf);
								char dir_buf[1024];
								//							printf("[%s]#\n",getcwd(dir_buf,sizeof(dir_buf)));					
						}
		return 0;		
}
