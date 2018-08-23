#include"../apue.h"
int main()
{
	 int shmid = shmget(0x8888,0,0);	
	 if(shmid==-1)
	 {
	 	show_err("shmget");
	 }
	printf("r:%d\n",shmid);
	 char *p = shmat(shmid,NULL,SHM_RDONLY);
	if(p==(char*)-1)
	{
		show_err("shmat");
	}

	puts(p);
//	shmdt(p);
//	shmctl(shmid,IPC_RMID,NULL);
	sleep(20);
	return 0;

}
