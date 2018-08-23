#include"../apue.h"

int main(int argc,char **argv)
{
	DIR *pdir=opendir(argv[1]);
	if(pdir==NULL)
	{
		perror("opendir");
		return 0;
	}
		return 0;
}
