#include "/apue.h"
void my_error(char *name);
void my_wait(int sig);
void my_exit(int sig);
void Sexit(int sig);

int main()
{
		signal(SIGCHLD,my_wait);
		signal(SIGINT,my_exit);
		signal(SIGTSTP,my_exit);
		if(mkfifo("file_pipe",0777) == -1)
				my_error("mkfifo");

		int fd ,pid=0;
	   	if( (fd = open("file_pipe",O_RDWR) ) == -1  )
				my_error("open");
		while(1)
		{
				int ret;
				char get_buf[1024];
				memset(get_buf,0,sizeof(get_buf));
				printf("等待客户\n");
#if 1			
				if( (pid = fork() )==0)
				{
						sleep(2);
				//		printf("getpid:%d\n",getpid());
						
						while(1)
						{
								usleep(1000*500);
								printf(".");
								fflush(NULL);
						}
				}
#endif
				if( ( ret = read(fd,get_buf,sizeof(get_buf) )) ==-1 )
						my_error("read name");
//				printf("%d  %s\n",ret,get_buf);
				if(pid > 0)
				{
//						printf("pid:%d\n",pid);
						if( kill(pid,SIGKILL) == -1)
								my_error("kill");
						pid = 0;

				}				

				if(fork() == 0)
				{
						signal(SIGPIPE,Sexit);
						char *pData;
						char buf_name[1024];
						if(( pData = strchr(get_buf,'$') ) == NULL)
						{
								printf("data error\n");
								exit(-1);
						}
						else
						{
								*pData = '\0';
//								printf("%s  %s  \n",get_buf,pData+1);
						}
						memset(buf_name,0,sizeof(buf_name));
						sprintf(buf_name,"file_pipe%s",pData+1);
						if(mkfifo(buf_name,0777) == -1)
								my_error(buf_name);

						int fd_child ;
						if( (fd_child = open(buf_name,O_WRONLY) ) == -1  )
								my_error("open_child");

						int fd_file;
//						printf("file: %s\n",get_buf);
						if( (fd_file = open(get_buf,O_RDONLY) ) == -1  )
								my_error("openi file");
						char buf_file[1024];
						memset(buf_file,0,sizeof(buf_file));
						while(  ( ret = read(fd_file,buf_file,sizeof(buf_file)) ) >0 )
						{
								sleep(1);
								write(fd_child,buf_file,sizeof(buf_file));
								memset(buf_file,0,sizeof(buf_file));
						}
						write(fd_child,buf_file,sizeof(buf_file)-1);
						printf("write over\n");
						close(fd);
						exit(0);


				}
//				sleep(1);
				memset(get_buf,0,sizeof(get_buf));
		}


}
void my_error(char *name)
{
		perror(name);
		exit(-1);
}

void my_wait(int sig)
{
		while(waitpid(-1,NULL,WNOHANG) > 0)
				printf("wait------------>\n");
		
}
void my_exit(int sig)
{
		printf("\ngood day bye bye ^_^\n");
		
		unlink("file_pipe");
	   exit(0);	

}

void Sexit(int sig)
{
		printf("客户错误 read端关闭\n");
		exit(-1);
}
