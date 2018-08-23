#include"../../apue.h"
int main()
{
	char puf[1024];
	int shmid = shmget(0x8888,100,IPC_CREAT|0644);
	if(shmid == -1)
	{
		myperror("shmget");
	}
	char * p = (char *)shmat(shmid,NULL,0);
	if(p == (char *)(-1))
	{
		myperror("shmat");
	}
	printf("please input char string \n");
	memset(puf,0,sizeof(puf));
	scanf("%s",puf);
	strcat(p,puf);
	int semid = semget((key_t)123456,1,IPC_CREAT);
	if(semid <0 )
	{
		myperror("semget");
	}
	semctl(semid,0,SETVAL,0);
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = 0;
	semop(semid,&buf,1);
	puts(p);
	shmdt(p);
	shmctl(shmid,IPC_RMID,NULL);
	semctl(semid,0,IPC_RMID);
	return 0;
}
