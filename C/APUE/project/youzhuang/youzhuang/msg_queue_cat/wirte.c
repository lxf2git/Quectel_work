#include"main.h"
int main()
{
		Msg m;
		m.type=666;
		key_t key = ftok("/root",'a');
		int id = msgget( key, O_RDWR|IPC_CREAT|0600);
		scanf("%s", m.msg);
		msgsnd(id,&m,sizeof(m)-sizeof(m.type),0);
		msgrcv(id, &m, sizeof(m)-sizeof(m.type), 777, 0);
		printf("%s",m.msg);
		while(m.msg[0]!=0)
		{
				msgrcv(id, &m, sizeof(m)-sizeof(m.type), 777, 0);
				printf("%s",m.msg);
		}
		msgctl(id,0,NULL);
		return 0;
}
