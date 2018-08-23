#include"../apue.h"
int main()
{
	key_t key = (key_t)123456;
	int semid =  semget(key,1,IPC_CREAT);
	if(semid<0)
	{
		show_err("semget");
	}

	semctl(semid,0,SETVAL,1);//IPC_RMID
	close(semid);
	return 0;

}
