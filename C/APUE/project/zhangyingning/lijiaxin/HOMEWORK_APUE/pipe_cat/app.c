#include"../apue.h"

int main()
{
		char buf[20];
		char buff[1024];
		bzero(buff,0);
		int i;
		mkfifo("fifo123",0644);
		for(i=0;i<3;i++)
		{
				printf("请输入需要打开的文件\n");
		
				scanf("%s",buf);
				int fd = open("fifo123",O_WRONLY);
				write(fd,buf,sizeof(buf));
				bzero(buf,20);
				close(fd);
		}
//		nulink("fifo123");

		while(i--)
		{
				printf("需要打开管道\n");
				scanf("%s",buf);
				mkfifo(buf,0644);
				int fdd = open(buf,O_RDONLY);
				while(1)
				{
						if(read(fdd,buff,sizeof(buff))<=0)
						{
							break;
						}
						printf("%s",buff);
				}
				close(fdd);
		}
		return 0;

}
