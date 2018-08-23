#include"../apue.h"

void fun(DIR *p)
{
	char fil_name[50];
	struct dirent *read;
	struct stat stat;
	while(1)
	{
	read=readdir(p);	
	if(read==NULL)
		break;
		if(read->d_name[0]!='.')
		{
		printf("%s\n",read->d_name);
		lstat(read->d_name,&stat);
		if(S_ISDIR(stat.st_mode))
		{ 
			DIR *tdir=opendir(read->d_name);
			chdir(read->d_name);
			fun(tdir);
			chdir("../");
		}
		}
	}
	closedir(p);
}


int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("loose file name");
		return -1;
	}
	DIR *p=opendir(argv[1]);
		if(p==NULL)
		{
			perror("not dir");
			return -1;
		}
   		chdir(argv[1]);
		fun(p);

	return 0;
}
