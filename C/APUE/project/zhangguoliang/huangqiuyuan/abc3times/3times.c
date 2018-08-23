/******************************************************************
首先编译 3times.c   a b c 开始循环输出，直接在命令行输入 a.out 结束循环输出
*******************************************************************/



#include"../apue.h"
void while_fork(char p)
{
	while(1)
	{
		printf("%c\n",p);
		sleep(3);
	}
}

int main()
{
	int i;
	pid_t ret;
	char arr[50];
	int fd=open("record.txt",O_RDWR|O_TRUNC|O_CREAT);
	for(i=0;i<3;i++)
	{
		if((ret=fork())==0)
		{
			if(i==0)
				while_fork('a');
			if(i==1)
			{
				sleep(1);
				while_fork('b');
			}
			if(i==2)
			{
				sleep(2);
				while_fork('c');
			}
		}
		sprintf(arr,"%d ",ret);
		write(fd,arr,strlen(arr));
	}
	close(fd);
	system("gcc kill.c");
	return 0;
}

