#include"../apue.h"
int main()
{
	int n;	
	char *p = NULL;
	int fd = open("mmap",O_RDWR);	
	if(fd<0)
	{
		show_err("open");
	}

	 p = (char *)mmap(0,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//建立文件和内存的映射
	if(p==MAP_FAILED)
	{
		show_err("mmap");
	}

	int cnt=0;
	for(;;)
	{
		if(p[0]!='\0')
		{
			printf("data:%s\n",p);
			memset(p,0,strlen(p));
			cnt = 0;
		}
		else
		{
			if(++cnt==20)//10s 退出
			{
				break;
			}
		}
		usleep(500*1000);//0.5s
	}

	munmap(p,1024);//解除映射

	close(fd);



	return 0;

}
