#include"apue.h" 

int main()
{
	key_t key= ftok("/root",'a');
	int id = msgget(key,IPC_CREAT|IPC_EXCL|0600);
	if(id<0)
	{
		myperror("msgget");
	}
	return 0;
}
