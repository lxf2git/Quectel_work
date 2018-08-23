#include"apue.h"
#define SIZE 100
int main()
{
        //创建共享内存
	key_t key_shm = ftok("/root",'a');
	int shmit = shmget(key_shm,1024,IPC_CREAT|0666);
	char *p = shmat(shmit,NULL,0);
	//创建信号量集
	key_t key_sem = ftok("/root",'b');
	int semid = semget(key_sem,1,IPC_CREAT|0666);
	semctl(semid,0,SETVAL,0);
	//向共享内存中写入数据
	printf("Input a str:\n");
	if(read(0,p,SIZE)<0)
	{
		show_err("input_err!");
	}
	//对信号量进行处理
	struct sembuf buf;
	buf.sem_num=0;
	buf.sem_op=-1;
	buf.sem_flg=0;
	semop(semid,&buf,1);
	//将共享内存中的内容读出
	if(write(1,p,SIZE)<0)
	{
		show_err("output_err!");
	}
	//删除共享内存对象
	shmdt(p);
	shmctl(shmit,IPC_RMID,NULL);
	//删除信号量集对象
	semctl(semid,0,IPC_RMID,NULL);
	return 0;	
}
