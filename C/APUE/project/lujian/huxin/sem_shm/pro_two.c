#include"../../apue.h"

int main()
{
	int num,i;
	int shmid = shmget(0x8888,100,0);
	if(shmid < 0)
	{
		myperror("shmget");
	}
	char *p = (char *)shmat(shmid,NULL,0);
	if(p == (char *)-1)
	{
		myperror("shmat");
	}
	num = strlen(p);
	for(i = 0;i<num;i++)
	{
		if(p[i]>='a'&&p[i]<='z')
		{
			p[i]-=32;
		}
	}
	int semid = semget((key_t)123456,1,O_RDWR);
	if(semid < 0)
	{
		myperror("semget");
	}
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = +1;
	buf.sem_flg = 0;
	semop(semid,&buf,1);
	return 0;
}

