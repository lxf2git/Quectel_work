#include"../apue.h"
int main(int argc,char **argv)
{
	struct stat s;
	lstat(argv[1],&s);
	printf("%s",ctime(&s.st_mtime));	
	return 0;

}
