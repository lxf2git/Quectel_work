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
		key_t key = ftok("/home",'b');
		int id = msgget(key,O_RDWR);
		printf("please enter type,name\n");
		scanf("%ld%s",&m.type,m.name);
		msgsnd(id,&m,sizeof(m)-sizeof(m.type),0);

		long type;
		printf("please enter type\n");
		scanf("%ld",&type);
		while(1)
		{
			usleep(100);
			memset(m.buf,0,sizeof(m.buf));
			if(msgrcv(id,&m,sizeof(m)-sizeof(m.type),type,IPC_NOWAIT)==-1)
			{
				//	puts("no type");
					break;
			}

			else
			{
					printf("%s",m.buf);
			}
		}
		msgctl(id,IPC_RMID,NULL);
		return 0;


}
