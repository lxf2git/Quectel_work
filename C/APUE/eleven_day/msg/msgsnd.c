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
	key_t key = ftok("/root",'a');
	int id = msgget(key,O_WRONLY);
	printf("please input type,name,age,score\n");
	scanf("%ld%s%d%f",&m.type,m.name,&m.age,&m.score);
	msgsnd(id,&m,sizeof(m)-sizeof(m.type),0);
}
