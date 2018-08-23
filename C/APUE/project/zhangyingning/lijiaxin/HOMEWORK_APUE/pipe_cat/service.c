#include"../apue.h"

void func(int sig)
{
		wait(NULL);
}

int main()
{
		char buf[20];
		char buff[1024];
		pid_t ret;
		signal(SIGUSR1,func);
		while(1)
		{
				int fd = open("fifo123",O_RDONLY);
				if(fd<0)
				{
						perror("open_per");
				}
				bzero(buf,20);
				if(read(fd,&buf,sizeof(buf))>0)
				{
			//	printf("xxxxxxxxxxxx\n");
			//	
						printf("%s\n",buf);
						close(fd);
						ret = fork();
						if(ret==0)
						{
								usleep(10);
								int fdd = open(buf,O_RDONLY);
								if(fdd<0)
								{
										perror("open_cld");
								}
						//		read(fdd,buff,sizeof(buff));
						//		printf("%s\n",buff);


								bzero(buf,20);
								printf("输入管道名\n");
								scanf("%s",buf);
							//	mkfifo(buf,0644);
								printf("********\n");
								int fp = open(buf,O_WRONLY);
								if(fp<0)
								{
										perror("guandao");
								}
								printf("&&&&&&&&&\n");
								bzero(buf,20);
								sprintf(buf,"kill -SIGUSR1 %d",getppid());
								while(1)
								{
										if(read(fdd,buff,sizeof(buff))<=0)
						//		printf("%d\n",ret);
										{
												break;
										}
										write(fp,buff,sizeof(buff));
						//				printf("%s\n",buff);

								}
								close(fp);
								close(fdd);
								printf("%s\n",buf);
								system(buf);
							//	usleep(10);
							//	exit(0);

						}	

				}
		}
}
