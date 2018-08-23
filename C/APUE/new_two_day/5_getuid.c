#include"../apue.h"

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		return -1;
	}	
	struct stat s;
	lstat(argv[1],&s);
	printf("%s\n",(getpwuid(s.st_uid))->pw_name);	
	return 0;

}
