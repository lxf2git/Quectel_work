#include"main.h"
void judge_output(int argc,char **argv,char *mode)
{
	int ret=0;
	char ls[4]="myls";
	if(argc>3||argc==0||strcmp(ls,argv[0])!=0)
	{
		printf("input wrong!\n");
		exit(-1);
	}
	while(1)
	{
		ret=getopt(argc,argv,"lai");
		if(ret==-1)
		{
			break;
		}
		switch(ret)
		{
			case 'l':
					mode[2]='l';
					break;
			case 'a':
					mode[1]='a';
					break;
			case 'i':
					mode[0]='i';
					break;
			case '?':
					printf("judge_error!\n");
					break;
			default:
					printf("judge_default!\n");
					break;
		}
	}
}
