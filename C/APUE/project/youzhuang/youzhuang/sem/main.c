#include"main.h"

void swap(char *str)
{
		while(*str!=0)
		{
				if(*str>='a'&&*str<='z')
				{
						*str-=32;
				}
				str++;
		}
}

int main()
{
		char str[256];
		int shmid = shmget(0x7777,sizeof(256),IPC_CREAT);
		char *p = (char *)shmat(shmid, NULL, 0);
		int semid = semget(0x9999, 1, IPC_CREAT);
		if(semid < 0)
		{
				perror("semget");
				exit(-1);
		}
		semctl(semid, 0, SETVAL, 0);
		struct sembuf sem;
		sem.sem_num = 0;
		sem.sem_op = -1;
		sem.sem_flg = 0;
		int pid = fork();
		if( pid == 0 )
		{
				sem.sem_flg = SEM_UNDO;
				semop(semid, &sem, 1);
				strcpy(str, p);
				swap(str);
				strcpy(p, str);
				exit(0);
		}
		else
		{
				printf("please input string:\n");
				scanf("%s", str);
				strcpy(p, str);
				sem.sem_op = +1;
				semop(semid, &sem, 1);
				sem.sem_op = -1;
				semop(semid, &sem, 1);
				printf("%s\n",p);
				wait(NULL);
				shmdt(p);
				shmctl(shmid,IPC_RMID,NULL);
				semctl(semid,0,IPC_RMID,NULL);
		}
		return 0;
}
