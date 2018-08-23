#include"main.h"
int main(int argc, char **argv)
{
		if(argv[2]=="<")
		{
				int fid=open(argv[3],O_RDWR);
				dup2(fid,0);
				printf("%s",argv[2]);
				exit(0);
		}
		if(argv[2]==">")
		{
				int fid=open(argv[3],O_RDWR);
				dup2(fid,1);
				printf("%s",argv[1]);
				exit(0);
		}
		if(argv[2]==">>")
		{
				int fid=open(argv[3],O_RDWR|O_APPEND);
				dup2(fid,1);
				printf("%s",argv[1]);
				exit(0);
		}
		printf("%s\n",argv[1]);
		return 0;
}

