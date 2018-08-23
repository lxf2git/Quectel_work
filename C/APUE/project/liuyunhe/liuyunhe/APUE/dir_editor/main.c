#include"apue.h"
//**********目录扫描器********************

int main(int argc,char **argv)
{
		if(2 != argc)
		{
			perror(argv[0]);
			return -1;
		}
		char buf[256] = {'\0'};
		chdir(argv[1]);
		 memset(buf,0,sizeof(buf));
		 getcwd(buf,sizeof(buf));
		dir_guc(buf);
		return 0;
}
