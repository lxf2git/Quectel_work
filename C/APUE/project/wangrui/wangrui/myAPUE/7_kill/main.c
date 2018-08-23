#include"../apue.h"

int main(int argc,char **argv)
{
	int sig = 0,pid = 0;
	int i;
	if(argc < 2)
	{
		printf("few\n");
		exit(-1);
	}
	else
	{
		if(argv[1][0] == '-')
		{
			sig = atoi(argv[1]+1);
			if(argv[2] == NULL)
			{
				kill(0,sig);
			}
			else
			{
				for(i=2;argv[i]!=NULL;i++)
				{
					pid = atoi(argv[i]);
					kill(pid,sig);
				}
			}
		}
		else
		{
			for(i=1;argv[i]!=NULL;i++)
			{
				pid = atoi(argv[i]);
				kill(pid,0);
			}
		}
	}
	return 0;
}
