#include "/apue.h"
#include <assert.h>
void my_error(char *name)
{
		perror(name);
		exit(-1);
}
int main(int argc,char **argv)
{
		assert(argc == 2);

		int fd_name ;
		printf("%d\n",strlen(argv[1]));
	   	if( (fd_name = open("file_pipe",O_WRONLY) ) == -1  )
				my_error("c :open");
		

		int pid = getpid();
		
		char sent_buf[1024];
		sprintf(sent_buf,"%s$%d",argv[1],pid);
		printf("sent_buf:%s\n",sent_buf);
		write( fd_name,sent_buf, strlen(sent_buf) );

//		close(fd_name);


		usleep(1000*20);
		int fd;
		char buf_name[1024];
		memset(buf_name,0,sizeof(buf_name));
		sprintf(buf_name,"file_pipe%d",pid);
		printf("%s\n",buf_name);

		if( (fd = open(buf_name,O_RDONLY) ) == -1  )
				my_error("c :open_pipe_child");


		char buf[1024];
		int ret;
		memset(buf,0,sizeof(buf));
				printf("read...\n");
		while(  ( ret = read(fd,buf,sizeof(buf)-1) ) >0 )
		{
				if(strlen(buf)== 0)
						break;
				printf("%s",buf);
				memset(buf,0,sizeof(buf));
		}
		unlink(buf_name);
		if(ret == -1)
				my_error("c : readfile");
		fflush(NULL);
		close(fd);


}
