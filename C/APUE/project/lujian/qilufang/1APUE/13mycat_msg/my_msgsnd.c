#include"apue.h"

typedef struct Data
{
	long type;
	char buf[200];
	char name[200];
}Data;
int main()
{
	Data info;
	info.type=2;
	key_t key = ftok("/root",'a');
	int id=msgget(key,O_WRONLY);
	printf("Input file name:\n");
	memset(info.name,0,sizeof(info.name));
	scanf("%s",info.name);
	msgsnd(id,&info,sizeof(info)-sizeof(info.type),0);
	while(1)
	{
		int ret=msgrcv(id,&info,sizeof(info)-sizeof(info.type),1,0);
		if(ret<0)
		{
			break;	
		}
		else
		{
			printf("%s",info.buf);
		}
		
	}

	return 0;

}
