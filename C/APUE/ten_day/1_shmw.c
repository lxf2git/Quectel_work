#include"../apue.h"
int main()
{
	int shmid = shmget(0x8888,100,IPC_CREAT|0644);//存在 直接取得 不存在则创建

	printf("w:%d\n",shmid);

	 char *p = shmat(shmid,NULL,0);
	 if(p==(char *)-1)
	 {
	 	show_err("shmat");
	 }

	 strcpy(p,"Beijing welcome you!");
	 //shmdt(p);
	return 0;

}




