#include"../apue.h"
typedef struct
{
		long type;
		char name[20];
		char buf[1024];
}Msg;
int main()
{
		Msg m;
		long int type;
		key_t key = ftok("/home",'b');
		int id = msgget(key,O_RDWR);
		printf("please enter type");
		scanf("%ld",&type);
		if(msgrcv(id,&m,sizeof(m)-sizeof(m.type),type,IPC_NOWAIT)==-1)
		{
				puts("no type");
		}
		else
		{
				int ret;
				printf("type:%ld name:%s\n",m.type,m.name);
				int fd = open(m.name,O_RDONLY);

				if(fd<0)
				{
						perror("open");
				}
				m.type = 1;
				while(1)
				{
						ret = read(fd,m.buf,sizeof(m.buf));
					//	printf("%s\n",m.buf);
						if(ret<=0)
						{
								break;
						}
						msgsnd(id,&m,sizeof(m)-sizeof(m.type),0);
				}
		}
	//	msgctl(id,IPC_RMID,NULL);
		return 0;

}
