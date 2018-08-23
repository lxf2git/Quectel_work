#include"../apue.h"

int main()
{
	char *p;
	struct sembuf sem;	
	int shmid = shmget((key_t)0x12345678,1024,IPC_CREAT|0666);
	if(shmid<0)
	{
		myperror("shmget");
	}
	p = shmat(shmid,NULL,0);

	int semid = semget((key_t)0x123,1,IPC_CREAT);
	if(semid<0)
	{
		myperror("semget");
	}
	semctl(semid,0,SETVAL,0);

	while(1)
	{
		printf("input:\n");
		gets(p);
		sem.sem_num = 0;
		sem.sem_op = +1;
		sem.sem_flg = 0;//为了让p2端执行change
		semop(semid,&sem,1);

		sem.sem_num = 0;
		sem.sem_op = -1;
		sem.sem_flg = 0;//为了让p2端执行change
		semop(semid,&sem,1);
		printf("%s",p);		
	}

}












