#include"main.h"

int main()
{
		int pid,i=0,j;
		printf("!\n");
				scanf("%d",&j);
		{
		pid=vfork();
		if(pid == 0)
		{
				printf("C pid:%d ppid:%d\n",getpid(),getppid());
				i++;
				printf("%d\n",i);
				scanf("%d",&j);
		}
		else
		{
				printf("P pid:%d ppid:%d\n",getpid(),getppid());
				i++;
				printf("%d\n",i);
		}
		}
		return 0;
}
