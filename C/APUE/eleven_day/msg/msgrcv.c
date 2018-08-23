#include"../../apue.h"

typedef struct msg
{
	long type;
	char name[20];
	int age;
	float score;
}Msg;

int main()
{
	Msg m;	
	long type;
	key_t key = ftok("/root",'a');
	int id = msgget(key,O_RDONLY);
	printf("请输入想接收的消息的类型：0表示任意\n");
	scanf("%d",&type);
	if(msgrcv(id,&m,sizeof(m)-sizeof(m.type),type,IPC_NOWAIT)==-1)
	{
		puts("没有这个类型的消息");
	}
	else
	{
		printf("type:%ld name:%s age:%d score:%f\n",
						m.type,m.name,m.age,m.score);
	}
	msgctl(id,IPC_RMID,NULL);
}
