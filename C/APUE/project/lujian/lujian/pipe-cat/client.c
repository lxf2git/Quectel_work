
#include"/home/C.语言笔记/class_exercise/APUE/apue.h" 

void sig_child(int signo);

typedef struct Client_info
{
		pid_t cl_pid;
		char filename[256];

}Sclt;

int main() 
{
		int fd_all = open("/all_know_pipe", O_RDWR);
		if (fd_all < 0)
		{
				myperror("open");
		}

		Sclt sclt_buf;
		sclt_buf.cl_pid = getpid();
		printf("please input you want access file\n"); 
		scanf("%s",sclt_buf.filename); 

		if (access(sclt_buf.filename, F_OK) < 0)
		{
				myperror("access");
		}
		write(fd_all, &sclt_buf, sizeof(sclt_buf));

		sleep(1);

		char fd_prt_buf[256];
		char data_buf[1024];
		memset(data_buf, 0, sizeof(data_buf));
		memset(fd_prt_buf, 0, sizeof(fd_prt_buf));
		sprintf(fd_prt_buf, "%d%s", getpid(), "_pipe");

		int fd_prt = open(fd_prt_buf, O_RDONLY);

		if (fd_prt < 0)
		{
				myperror("open");
		}
		int n;
		while(1)
		{
				n = read(fd_prt, data_buf, sizeof(data_buf));
				if (0 == n)
				{
						break;
				}
				else
				{
						write(1, data_buf, n);
						memset(data_buf, 0, sizeof(data_buf));
				}
		}

		close(fd_all);
		close(fd_prt);
		unlink(fd_prt_buf);
		return TURE; 
}














