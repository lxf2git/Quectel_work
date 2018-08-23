#include"id_passwd.h"
int generatorid()
{
	static long id=0;
	id++;
	return id;
}

int input_passwd(long id,int passwd)
{
	
	extern int a[100];
	a[id]=passwd;
}
