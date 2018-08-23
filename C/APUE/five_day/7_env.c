#include"../apue.h"
int main(int argc,char *argv[])
{
	int i=0;
	while(argv[i]!=NULL)
	{
		printf("i:%d argc:%d string:%s\n",i,argc,argv[i]);
		i++;
	}
}
