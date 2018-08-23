#include<stdio.h>
#include<stdlib.h>
//命令行传参 
int main(int argc,char *argv[])//char **argv
{
	int i;
	if(argc==1)
	{
		printf("file_name argument\n");
		exit(-1);
	}
	for(i=0;i<argc;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}	
	return 0;

}
