#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct msgbuf
{
		long mtype;
		char mtext[1024];
		int length;
}sMsg;
int main(int argc , char **argv)
{

		sMsg m;
		m.mtype = 1;
		memset(m.mtext,0,sizeof(m.mtext));
		key_t key;
		key = ftok("/root",2);
		char buf[1024];
		int id = msgget(key,IPC_CREAT);
		int fd = open(argv[1],O_RDONLY);
		if(fd == -1)
		{
				perror("open");
				exit(-1);
		}
		while( (m.length = read(fd,buf,sizeof(buf) ) ) > 0)
		{
				printf("%d   %d\n",m.length,sizeof(m));

				
				strcpy(m.mtext,buf);
				msgsnd(id,&m,sizeof(m)-sizeof(long),0);
				memset(buf,0,sizeof(buf));
				memset(m.mtext,0,sizeof(m.mtext));
		}
		close(fd);
}
