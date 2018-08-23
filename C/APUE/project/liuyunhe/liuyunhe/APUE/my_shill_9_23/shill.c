#include"apue.h"

int shill_head()
{
		int i=0,j=0;
		char cmd[1024]={'\0'};
		char twd[100]={'\0'};
		char name[50]={'\0'};
		gethostname(name,50);
		getcwd(twd,100);
		printf("[%s@",getenv("USER"));
		for(i=0;name[i]!='\0';i++)
		{
				if('.'==name[i])
				{
						break;
				}
				printf("%c",name[i]);
		}
		printf(" ");
		i = strlen(twd);
		if(1 == i)
		{
				printf("/");
		}
		for(i=0;twd[i]!='\0';i++)
		{
				if('/' == twd[i])
				{
						j=i;
				}
		}
		for(j++;twd[j]!='\0';j++)
		{
				printf("%c",twd[j]);
		}
		if(0 == strcmp(getenv("USER"),"root"))
		{
				printf("]# ");
		}
		else
		{
				printf("]$ ");

		}
}

int shill_life()
{
		char cmd[256] = {'\0'};
		char *p;
		scanf("%[^\n]",cmd);
		getchar();
		if(0 == strcmp(cmd,"quit"))
		{
				return -1;
		}
		else if(0 == strncmp(cmd,"cd ",3))
		{
				chdir(cmd+3);
		}
		else if(NULL != (p = strchr(cmd,'=')))
		{		int i,j;
				char name[128]={'\0'};
				char value[128]={'\0'};
				for(i=0;cmd[i] != *p;i++)
				{
						name[i] = cmd[i];
				}
			//	printf("name:%s\n",name);
				for(j=(i+1);cmd[j]!= '\0';j++)
				{
						value[j-i-1] = cmd[j];
				}
			//	printf("value:%s\n",value);
				setenv(name,value,1);
				char *str = getenv(name);
				puts(str);
		}
		else
		{
				system(cmd);
		}
		return 0;
}
int main()
{
		int ret=0;
		puts("welcome to my shill");
		while(1)
		{
				shill_head();
				ret = shill_life();
				if(-1 == ret)
				{
						break;
				}
		}
		puts("byes my shill");
		return 0;
}
