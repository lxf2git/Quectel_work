#include"apue.h"

int show_all(char *pathname);

int main(int argc, char **argv)
{
	if(2 != argc)
	{
		printf("%s path name\n",argv[0]);
		return -1;
	}
	show_all(argv[1]);
	return 0;
}


int show_all(char *pathname)
{
	DIR *pdir=NULL;
	struct dirent *pdirent=NULL;
	struct stat buf;
	char buf_path[100];
	int ret=0;
	pdir = opendir(pathname);
	if(NULL == pdir)
	{
		perror("pdir");
		goto ERR;
	}

	ret = chdir(pathname);
	if(ret < 0)
	{
		perror("chidr");
		goto ERR;
	}
	
	while(1)
	{

		pdirent = readdir(pdir);
		if(NULL == pdirent)
		{
			break;
		}

		ret = lstat(pdirent->d_name, &buf);
		if(ret == -1)
		{
			perror("lstat");
			goto ERR;
		}

		if(pdirent->d_name[0]=='.')
		{
			continue;
		}

		if(S_ISDIR(buf.st_mode))
		{
			show_all(pdirent->d_name);
			ret = chdir("../");
			if(ret < 0)
			{
				perror("chdir");
				goto ERR;
			}
		}
		else
		{
			memset(buf_path, 0, sizeof(buf_path));
			getcwd(buf_path,sizeof(buf_path));
			printf("%s/%s\n", buf_path,pdirent->d_name);
		}
	}
	printf("%s\n", buf_path);
	closedir(pdir);
	return 0;
ERR :
	closedir(pdir);
	return -1;
}
