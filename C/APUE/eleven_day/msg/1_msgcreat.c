#include"../../apue.h"
int main()
{
	 key_t key = ftok("/root",'a');
	int id =  msgget(key,IPC_CREAT|0600);
	if(id<0)
	{
		show_err("msgget");
	}
	
}

