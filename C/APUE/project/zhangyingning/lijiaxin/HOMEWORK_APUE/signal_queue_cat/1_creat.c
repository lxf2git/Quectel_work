#include"../apue.h"

int main()
{
		key_t key = ftok("/home",'b');
		int id = msgget(key,IPC_CREAT|0666);
		if(id<0)
		{
				perror("msgget");
		}
		return 0;
}
