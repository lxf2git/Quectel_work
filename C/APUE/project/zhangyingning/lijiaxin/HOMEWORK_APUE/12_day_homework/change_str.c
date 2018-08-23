#include"../apue.h"

int main()
{
		//创建一个信号量集对象,key可以自行定义，也可以用ftok获得
		//信号量：控制访问同一资源的进程的数量 控制多个进程同步
		// int semget(key_t key, int nsems, int semflg);
		// 创建或取得一个信号量集对象
		// nsems：信号量的个数 一般是1
		// semflg:IPC_CREAT创建,IPC_EXCL判断是否存在,其余同open();
		// 如：O_RDONLY O_WRONLY O_RDWR ...
		// 成功返回对象id  失败-1
		int semid = semget((key_t)12345,1,IPC_CREAT|0600);
		if(semid<0)
		{
				perror("semget");
		}
		//对新建的信号集设定初值,
		//
		//semid:信号集的id号(semget的返回值);
		//设置编号下标为0 的信号量为0(信号量不能为负,为负值则挂起(不能执行程序))；
		//semctl(semid,0,IPC_RMID,NULL);删除信号量集对象
		semctl(semid,0,SETVAL,0);
		char buf_str[1023];
		scanf("%s",buf_str);


		if(fork()==0)
		{

				printf("ssssss\n");
				int shmid = shmget(0x1234,0,0);
				if(shmid == -1)
				{
						perror("shmget");
						exit(-1);
				}
				char *buf = shmat(shmid,NULL,0);
				int i=0;
				while(buf[i]!='\0')
				{
						if(buf[i]>96)
						{
								buf[i]=buf[i]-32;
						}
						i++;
				}
				//int semop(int semid, struct sembuf *sops, unsigned nsops);
				//对信号量进行一些操作,通过对*sops进行赋值
				struct sembuf xx = {0,+1,0};
				//对xx 结构体赋值,0 是表示信号信号编号为0进行操作
				//+1，表示对编号为0的信号集进行+1处理，
				//当一个进程时,可默认为0；(格式:IPC_NOWAIT:不挂起等待; SEM_UNDO:返回上一次的状态 );

				semop(semid,&xx,1);	
		}
		else
		{
				int shmid = shmget(0x1234,1024,IPC_CREAT|0666);

				char *buf = shmat(shmid,NULL,0);
				memset(buf,0,1024);
				strcpy(buf,buf_str); 

				struct sembuf xx = {0,-1,0};
				semop(semid,&xx,1);	
				printf("%s\n",buf);

				shmdt(buf);
				shmctl(shmid,IPC_RMID,NULL);
		}
		return 0;


}
