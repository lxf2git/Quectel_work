#include"../apue.h"
void change(char *p)
{
	while(*p)
	{
		if((*p)>='a'&&(*p)<='z')
		{
			*p-=32;
		}
		p++;
	}
		
}

int main()
{
	char *p;	
	struct sembuf sem;
	int shmid = shmget((key_t)0x12345678,1024,O_RDWR);
	if(shmid<0)
	{
		myperror("shmget");
	}

	 p = shmat(shmid,NULL,0);

	int semid = semget((key_t)0x123,1,O_RDWR);
	if(semid<0)
	{
		myperror("semget");
	}

	 while(1)
	 {
		sem.sem_num=0;
   		sem.sem_op = -1;
		sem.sem_flg = 0;		
		semop(semid,&sem,1);	 
	 	change(p);
		sem.sem_num=0;
   		sem.sem_op = +1;
		sem.sem_flg = 0;		
		semop(semid,&sem,1);	 

	 }
}










