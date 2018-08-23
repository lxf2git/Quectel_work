#include"fork.h"

int main()
{
		int i;
		pid_t pid;
		char ch[]={'a','b','c'};
		int pid_arr[3];
		int fid=open("a.txt",O_CREAT|O_EXCL,0666);
		if(fid==-1)
		{
				perror("open");
				fid=open("a.txt",O_WRONLY);
				if(fid==-1)
				{
						perror("open append");
						exit(-1);
				}
		}
		for(i=0;i<3;i++)
		{
				pid=fork();
				if(0==pid)
				{
						pid_arr[i]=getpid();
						save(fid,pid_arr[i]);
						break;
				}
		}
		for(i=0;i<3;i++)
		{
				if(getpid()==pid_arr[i])
				{
						while(1)
						{
								sleep(1);
								printf("%c",'a'+i);
						}
				}
		}
		return 0;
}
void save(int fid,int pid)
{
		char pid_ch[10];
		sprintf(pid_ch,"%d",pid);
		write(fid,pid_ch,strlen(pid_ch));
		write(fid," ",1);
}
