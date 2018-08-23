#include"/home/C.语言笔记/class_exercise/APUE/apue.h" 

void sig_child(int signo);

typedef struct Client_info
{
		pid_t cl_pid;
		char filename[256];

}Sclt;

int main() 
{
		pid_t pid;
		umask(0);
		mkfifo("/all_know_pipe", 0644);
		int fd_all = open("/all_know_pipe", O_RDWR);
		Sclt sclt_buf;

		if (fd_all  < 0)
		{
				myperror("open");	
		}


		signal(SIGCHLD, sig_child);

		while(1)
		{
				printf("server is runging\n");
				read(fd_all, &sclt_buf,sizeof(Sclt));
				printf("get come from pid is (%d) request access %s \n",
								sclt_buf.cl_pid, sclt_buf.filename);

				if ((pid = fork()) < 0)
				{
						myperror("fork");
				}

				else if(pid == 0)
				{
						int fd_file;
						int n;
						int fd_clt;
						char fd_clt_buf[256];
						char data_buf[1024];

						memset(data_buf, 0, sizeof(data_buf));
						memset(fd_clt_buf, 0, sizeof(fd_clt_buf));
						sprintf(fd_clt_buf,"%d%s", sclt_buf.cl_pid,"_pipe");
						mkfifo(fd_clt_buf, 0644);

#if 1
						if ((fd_clt = open(fd_clt_buf, O_WRONLY)) < 0	)
						{
								myperror("open");
						}



#else
						if ((fd_clt = open(fd_clt_buf, O_RDWR)) < 0	)
						{
								myperror("open");
						}

						sleep(1);
#endif 
						
						if ((fd_file  = open(sclt_buf.filename, O_RDONLY))< 0)
						{
								myperror("open");
						}

						while(1)
						{
								if ((n=read(fd_file, data_buf, sizeof(data_buf)))  < 0)
								{
										myperror("read");
								}
								else if (0 == n)
								{
										close(fd_file);
										close(fd_all);
										unlink(fd_clt_buf);
								//		kill(sclt_buf.cl_pid,SIGKILL);
										break;
								}
								else 
								{
										if (write(fd_clt, data_buf, n) );
								}
						}

						_exit(0);
				}

	}


}

void sig_child(int signo)
{
	int  status;
	pid_t wait_pid;
	signal(SIGCHLD, sig_child);
	while((wait_pid = waitpid(-1, &status, WNOHANG)) > 0);
}

