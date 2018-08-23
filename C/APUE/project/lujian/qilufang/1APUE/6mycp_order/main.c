#include"main.h"     
int main(int argc,char **argv)
{
	int flag=0;
	flag=judge_fileORdir(argc,argv);
	if(flag<0)
	{	
		file_cp(argv[1],argv[2]);
	}

	else
	{
		dir_cp(argv[1],argv[2]);
	}
	return 0;
}
