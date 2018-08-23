
/********************
 *
 * 作业：写个程序 开启3个子进程 每个子进程每秒打印一个字符 第一个进程打印a 第二个进程打印b
 *  第三个进程打印c 然后父进程结束  file
 *  再写个程序 终止上面的所有子进程  system(cmd);  cmd kill+id 
 *
 *
 * ********************/

#include"../../apue.h" 


void print(void);
int main() 
{
		int fd;
		int re;
		int sta;

		pid_t pid;

		atexit(print); //注册

		char cmd[256];

		bzero(cmd, sizeof(cmd));

		if ((fd =creat("file",0666)) < 0)
		{
				perror("creat");
				_exit(-1);
		}


		pid = fork();  

		if (pid == 0)
		{
				/*
				 *第一个进程
				 *
				 */

				pid =getpid();
				printf("chid->pid: %d\n", getpid());
				if (write(fd, &pid,sizeof(pid)) < 0)
				{
						perror("write");
						_exit(-1);
				}
				printf("%d:write OK\n", pid);
				close(fd);

				while(1)
				{
						puts("a");
						sleep(3);
				}
		}
		else
		{
				pid = fork();
				if (pid == 0)
				{
				
				/*
				 *第二个进程
				 *
				 *
				 */
						sleep(1); // 延时 防止竞争
						pid =getpid();
						printf("chid->pid: %d\n", getpid());
						if (write(fd, &pid,sizeof(pid)) < 0)
						{
								perror("write");
								_exit(-1);
						}

						printf("%d:write OK\n", pid);
						close(fd);

						while(1)
						{
								puts("b");
								sleep(3);
						}
				}
				else
				{
						pid = fork();
						if (pid == 0)
						{
								
						/*
						 *第三个进程
						 *
						 *
						 */
								sleep(2);
								pid =getpid();
								printf("chid->pid: %d\n", getpid());
								if (write(fd, &pid,sizeof(pid)) < 0)
								{
										perror("write");
										_exit(-1);
								}
								printf("%d:write OK\n", pid);
								close(fd);


								while(1)
								{

										puts("c");
										sleep(3);		
								}

						}
						else
						{
							exit(-1);
							
#if 0
							printf("pa->pid: %d\n", getpid());

							sleep(10);
							close(fd);

							if ((fd = open("file", O_RDWR)) < 0)
							{
								perror("open");
							}

							//lseek(fd,0, SEEK_SET);

						/*****读取子进程pid*****/

							while(1)
							{

								if ((re = read(fd, &pid, sizeof(pid))) < 0)
								{
									printf("re == %d\n", re) ;
									perror("read");
								}
								if (re == 0)
								{
									break;
								}
						/*****kill -9 pid****/

								printf("pid: %d\n", pid);
								sprintf(cmd,"kill -9"" " "%d",pid);
								puts(cmd);
								system(cmd);
								bzero(cmd, sizeof(cmd));
							}
						
						/*****父进程收尸****/
							while(1)
							{
								pid = wait(&sta);
								if (pid == -1)
								{
									break;
								}
								printf("child->pid:%d, status:%d %d %d %d \n",
								   	pid, WIFEXITED(sta),
								   	WEXITSTATUS(sta), WIFSIGNALED(sta),WTERMSIG(sta));
							}

							
#endif 	
						}
				}
		}


}

void print(void)
{
	printf("pa:%d end\n", getpid());
}



/*
WIFEXITED(status) 判断是否正常退出  真 正常退出
WEXITSTATUS(status) 取得进程结束时的返回值
WIFSIGNALED(status) 判断是否是被信号终止 信号终止返回真
WTERMSIG(status)  判断是被哪个信号终止的
*/















