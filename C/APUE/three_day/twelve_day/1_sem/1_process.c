
#include"../apue.h"

void PV(int semid,int index,int op)
{
	struct sembuf buf = {index,op,0};
	semop(semid,&buf,1);
}

int main()
{
	int semid = semget((key_t)123456,1,O_RDWR);
	pid_t pid = fork();
	if(pid==0)
	{
		sleep(1);	
		puts("i am child proc!");
		sleep(3);
		printf("chidl_pid:%d\n",getpid());
		PV(semid,0,+1);
	}
	else
	{
		PV(semid,0,-1);
		puts("i am par proc!");
		printf("par_pid:%d\n",getpid());
	}
}
