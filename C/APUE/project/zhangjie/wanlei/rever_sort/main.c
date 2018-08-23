#include"main.h"
#include"insert.h"
#include"read.h"

int main(int argc,char *argv[])
{
	sMod smod;
	init_mod(&smod);
	read_data(&smod,argv[1]);
	find(&smod);
	return 0;
}
