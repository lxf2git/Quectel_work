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
	int fid;
	long type;
	File_da file;
	key_t key = ftok("/root",'a');
	int id = msgget(key,O_RDWR);
	if(-1 == msgrcv(id,&file,sizeof(file)-sizeof(file.type),0,0))
	{
		puts("not the type information\n");
	}
	else
	{
		fid = open(file.name,O_RDONLY);
		if(ret < 0)
		{
			myperror("open");
		}
		while(1)
		{
			memset(file.buf,0,sizeof(file.buf));
			ret = read(fid,file.buf,sizeof(file.buf));
			if(ret < 0 )
			{
				myperror("read");
			}
			if(ret == 0)
			{
				break;
			}
			file.type = 2;
			ret = msgsnd(id,&file,sizeof(file)-sizeof(file.type),0);
			if(ret < 0)
			{
				myperror("msgsnd");
			}
			usleep(1000);
		}
	}
	close(fid);
	msgctl(id,IPC_RMID,NULL);
}
