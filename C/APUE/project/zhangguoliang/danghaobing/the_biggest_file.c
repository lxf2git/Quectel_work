#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int argc,char **argv)
{
	DIR *pdir = opendir(argv[1]);
	if(NULL==pdir)
	{
			perror("opendir");
			return 0;
	}
	chdir(argv[1]);
	int max=0;
	char mx_name[20];
	struct stat Stat;
	struct dirent *pdirent = NULL;
	while((pdirent = readdir(pdir))!=NULL)
	{
			lstat(pdirent->d_name,&Stat);
			if(Stat.st_size>max&&(pdirent->d_name[0]!='.')&&S_ISREG(Stat.st_mode))
			{
					max=Stat.st_size;
					strcpy(mx_name,pdirent->d_name);
			}
	}
	printf("The biggest file is %s \n",mx_name);
	closedir(pdir);
}
