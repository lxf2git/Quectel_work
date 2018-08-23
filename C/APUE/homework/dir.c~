#include"../apue.h"


void printdir(char *dir)
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	struct stat statbuf;
	int ret;
	dp = opendir(dir);
	chdir(dir);

	while((entry=readdir(dp))!=NULL)
	{       
		printf("  ");
		ret = lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			
			if(entry->d_name[0]=='.')
			{
				continue;
			}
			
			printf("%s",entry->d_name);
			printdir(entry->d_name);
		}

		else
		{	
			printf("%s",entry->d_name);
		}
	}


	chdir("..");
	closedir(dp);

}
int main(int argc,char **argv)
{
	char *topdir = ".";	
	if(argc==2)
	{
		topdir = argv[1];	
	}	

	printdir(topdir);
	return 0;

}
