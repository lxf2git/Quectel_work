#include"../apue.h"
int main()
{
	int fd[2];	
	pid_t pid;
	pipe(fd);
	
	pid = fork();
	if(pid<0)
	{
		show_err("fork");
	}	
	if(pid==0)//读 关闭写端
	{
		sleep(1);	
		close(fd[1]);
		int n;
		int ret = read(fd[0],&n,4);
		if(ret<=0)
		{
			show_err("read");
		}
		printf("read:%d\n",n);

			
	}
	else//par
	{
		close(fd[0]);//写 关闭读端
		int num;
		scanf("%d",&num);
		write(fd[1],&num,sizeof(num));	
		wait(NULL);
	
	}
	return 0;

}
