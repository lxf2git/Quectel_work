#include"apue.h"

int main(int argc,char **argv)
{
	DIR * dir;
	struct dirent * dirent;
	struct stat stat;
	off_t size = 0;
	char name[256] = {};

	
	if(argc != 2)
	{
		printf("%s directory\n",argv[1]);
		return -1;
	}

	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		dirent = readdir(dir);
		if(dirent == NULL)
		{
			break;
		}
		if((dirent->d_name)[0] == '.')
		{
			continue;
		}
		lstat(dirent->d_name,&stat);
		if(stat.st_size > size)
		{
			bzero(name,sizeof(name));
			strcpy(name,dirent->d_name);
			size = stat.st_size;
		}
	}
	printf("%s\n",name);

	closedir(dir);
	return 0;

}
