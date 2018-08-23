#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int judge_dup(int argc,char **argv);

int main(int argc,char **argv)
{
		if(argc==1)
		{
				printf("echo:use-----error\n");
				return -1;
		}
		judge_dup(argc,argv);
		if (argv[1][0]== '$')
		{
			if(getenv(argv[1]+1) !=NULL)
					printf("%s\n",getenv(argv[1]+1));
			else
					printf("env no have\n");

		}
		else
				printf("%s\n",argv[1]);
		return 0;
}
