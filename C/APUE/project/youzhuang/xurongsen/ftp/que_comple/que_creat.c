#include "que_resd.h"

int main()
{
	int id = msgget(0x6666,IPC_CREAT|0666);
	if(id<0)
	{
		show_err("msgget");
	}
	int id2 = msgget(0x6668,IPC_CREAT|0666);
	if(id2<0)
	{
		show_err("msgget2");
	}
}
