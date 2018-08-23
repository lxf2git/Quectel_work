#include"../apue.h"
extern char **environ;//char **argv
int main()
{
	int i;	
	for(i=0;environ[i]!=NULL;i++)
	{
		printf("%s\n",environ[i]);
	}	
	return 0;

}
