#include"../apue.h"

int main()
{
	int j,i;
	long os;
	FILE *fp = NULL;
	char buf[256] = {};
	char buff[12] = "abc";
	int status;
	pid_t pid;
	fp = fopen("stop.c","r");
	os = 3 * sizeof(pid_t);
	fseek(fp,-os,SEEK_END);
	for(i=0;i<3;i++)
	{
		fread(&pid,sizeof(pid_t),1,fp);
		kill(pid,SIGKILL);
		waitpid(pid,&status,0);
	//	system();
	}
	fclose(fp);
	return 0;
}
//
