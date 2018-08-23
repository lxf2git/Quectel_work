#include"../apue.h"
int main()
{
	int i;
	int semid = semget(0x8888,1,IPC_CREAT|0600);	
	if(semid<0)
	{
		show_err("semget");	
	}
	
	semctl(semid,0,SETVAL,5);
	for(i=0;i<10;i++)
	{
		if(fork()==0)
		{
			struct sembuf buf;
			buf.sem_num = 0;
			buf.sem_op = -1;
			buf.sem_flg = SEM_UNDO;	
			semop(semid,&buf,1);

			printf("%d进程start工作\n",getpid());
			sleep(3);
			printf("%d进程工作完毕\n",getpid());
		/*
			buf.sem_num = 0;
			buf.sem_op = +1;
			buf.sem_flg = 0;	
			semop(semid,&buf,1);
			*/
			exit(0);
		}
	}
	return 0;

}
