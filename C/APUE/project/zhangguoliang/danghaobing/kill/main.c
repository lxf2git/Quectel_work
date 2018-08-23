#include "../apue.h"

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
		int i,ret;
		char arr[50];
		char brr[4]="abc";
		int fd = open("record.txt",O_RDWR|O_TRUNC);
		for(i=0;i<3;i++)
		{
				if((ret=fork())==0)
				{
								while_fork(brr[i]);
				}
				sprintf(arr,"%d ",ret);
				write(fd,arr,strlen(arr));//如何把数字存入
				sleep(1);
		}
		close(fd);
		system("gcc kill.c");
		return 0;
}
