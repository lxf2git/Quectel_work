#include"apue.h"

typedef struct file_da
{
	long type;
	char name[20];
	char buf[1024];
}File_da;
int main()
{	
	int ret;
	File_da file;
	key_t key = ftok("/root",'a');
	int id = msgget(key,O_RDWR);
	printf("please intput file_name\n");
	file.type = 1;
	scanf("%s",file.name);
	ret = msgsnd(id,&file,sizeof(file)-sizeof(file.type),0);
	if(ret < 0)
	{
			myperror("msgsnd");
	}
	while(1)
	{
			ret = msgrcv(id,&file,sizeof(file)-sizeof(file.type),2,0);
			if(ret < 0)
			{
					break;
			}
			else
			{
					printf("%s",file.buf);
			}
	}
}
