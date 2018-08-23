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
		int length;
		char mtext[1025];
}sMsg;
void sent_fileName(char *fileName);
void get_data();
int main(int argc,char **argv)
{

		
		sent_fileName(argv[1]);
		get_data();
}


void sent_fileName(char *fileName)
{
		sMsg m;
		m.mtype = 2;
		memset(m.mtext,0,sizeof(m.mtext));

		key_t key;
		key = ftok("/root",2);
		printf("key-send:%d\n",key);
		int id = msgget(key,IPC_CREAT|0666);
		printf("id:%d\n",id);
		strcpy(m.mtext,fileName);
		msgsnd(id,&m,sizeof(m)-sizeof(long),0);
}
void get_data()
{
		
		sMsg m;
		memset(m.mtext,0,sizeof(m.mtext));
		key_t key;
		key = ftok("/home",1);
		printf("key-rcv:%d\n",key);
		int id = msgget(key,0);
		printf("rec-id:%d\n",id);
		while(1)
		{
				ssize_t ret = msgrcv(id,&m,sizeof(m)-sizeof(long),3,0);
			printf("ret:%d\n",ret);
				if(m.length == 1024)
				{
						printf("%s\n",m.mtext);
						memset(m.mtext,0,sizeof(m.mtext));
				}
				else
				{
						printf("data:%s\n",m.mtext);
						fflush(NULL);
						printf("end\n");
						//msgctl(id,IPC_RMID,NULL);
						exit(0);
				}
		}
}
