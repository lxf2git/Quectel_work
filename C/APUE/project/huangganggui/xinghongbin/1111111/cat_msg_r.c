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
int main()
{

		sMsg m;
		key_t key;
		key = ftok("/root",2);
		int id = msgget(key,0);
		while(1)
		{
				msgrcv(id,&m,sizeof(m)-sizeof(long),0,0);
				printf("%d\n",m.length);
				if(m.length == 1024)
				{
						printf("%s",m.mtext);
						memset(m.mtext,0,sizeof(m.mtext));
						fflush(NULL);
				}
				else
				{
						printf("%s",m.mtext);
						fflush(NULL);
						msgctl(id,IPC_RMID,NULL);
						exit(0);
				}
		}
}
