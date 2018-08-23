#include"apue.h"
int main()
{
		int fd[2];
		pid_t pid;
		pipe(fd);
		set_err(pid=fork(),"fork");
		if(pid==0)
		{
				sleep(1);
				close(fd[1]);
				char brr[100]={0};
				int i;
				read(fd[0],brr,sizeof(brr));
				
				for(i=0;brr[i]!=0;i++)
				if((brr[i]>='A')&&(brr[i]<='Z'))
				brr[i]=brr[i]+('a'-'A');
				
				puts(brr);
		}
		else
		{
				close(fd[0]);
				char arr[100]={0};
				scanf("%s",arr);
				write(fd[1],arr,strlen(arr));
				wait(NULL);
		}
		return 0;
}
