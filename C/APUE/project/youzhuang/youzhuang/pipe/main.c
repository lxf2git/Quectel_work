#include"main.h"

int judge(char *p1, char *p2)
{
		for(;*p1!=0;p1++)
		{
				if(strncmp(p1,p2,strlen(p2))==0)
				{
						return 0;
				}
		}
		return -1;
}

void grep(char *p1,char *p2)
{
		char ch[20];
		int i=0;
		while(*p1!=0)
		{
				ch[i]=*p1;
				i++;
				p1++;
				if(*p1==10)
				{
						ch[i]=0;
						if(judge(ch, p2)==0)
						{
								printf("%s\n",ch);
						}
						i=0;
						p1++;
				}
		}
}

int main( int argc, char **argv)
{
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		int fd[2];
		int pid;
		pipe( fd );

		pid = fork();
		if( pid == 0 )
		{
				close( fd[1] );
				read(fd[0],buf,sizeof(buf));
				grep(buf, argv[1]);
		}
		else
		{
				close( fd[0] );
				dup2(fd[1],1);
				system("ls");
				wait( NULL );
		}
}
