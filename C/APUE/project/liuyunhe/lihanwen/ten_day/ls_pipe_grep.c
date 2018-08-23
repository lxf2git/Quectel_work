#include"../apue.h"	

int main(int argc,char *argv[])	
{
	if(argc!=2)
	{
		printf("%s conditions\n",argv[0]);
		return -1;
	}
	int pipefd[2];
	pid_t pid;
	pipe(pipefd);

	pid = fork();
	if(pid<0)
	{
		show_err("fork");
		return -1;
	}
	if(pid==0)
	{
		sleep(1);
		close(pipefd[1]);
		char read_buf[1024];
		while(1)
		{
			read(pipefd[0],read_buf,sizeof(read_buf));
			if(read_buf==NULL)//停止标志是什么
			{
				printf("end\n");
				break;
			}
			if(strncmp(read_buf,argv[1],strlen(argv[1]))==0)
			{
				printf("%s\n",read_buf);
			}
			memset(read_buf,0,sizeof(read_buf));
		}



	}else
	{
		DIR *pdir = NULL;
		struct dirent *pdirent = NULL;
		struct stat stat;
		char mode;
		int ret;

		pdir=opendir("..");
		if(pdir==NULL)
		{
			show_err("opendir");
		}

		char buf[1024];
		char ch[2] = {'\n'};
		while(1)
		{
			close(pipefd[0]);
			pdirent=readdir(pdir);
			if(pdirent==NULL)
			{
				break;
			}
			strcpy(buf,pdirent->d_name);
			strcat(buf,ch);
			write(pipefd[1],buf,sizeof(buf));
			memset(buf,0,sizeof(buf));
		}
		wait(NULL);

	}
	


	return 0;	
}
