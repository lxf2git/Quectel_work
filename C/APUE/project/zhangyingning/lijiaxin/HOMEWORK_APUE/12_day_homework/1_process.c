#include"../apue.h"
void PV(int semid,int index,int op)
{
		struct sembuf buf = {index,op,IPC_NOWAIT};
		semop(semid,&buf,1);
}

int main()
{
		int semid = semget((key_t)123456,1,O_RDWR);
		pid_t pid = fork();
		if(pid==0)
		{
				sleep(1);
				puts("IIIIIIIIIIIIII");
				sleep(3);
				printf("WWWWWWWWWWWWW\n");
				PV(semid,0,+1);
		}
		else
		{
				PV(semid,0,-1);
				puts("fffffffffff");
				printf("dddddddddddd\n");
		}
}
