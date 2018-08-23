#include"../apue.h"
int main()
{
	char *p=NULL;
	char cmd[50] = {'\0'};
	scanf("%s",cmd);	
	p  = strchr(cmd,'=');
	printf("*p:%c",*p);
	return 0;

}
