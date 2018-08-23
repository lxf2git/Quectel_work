#include"main.h"

int main(int argc, char **argv)
{
		int ret;
		if(argc!=2)
		{
				printf("%s dirent name\n",argv[0]);
				return -1;
		}
		scna(argv[1]);
		return 0;
}

void scna(char *dir_name)
{
		char path[50];
		DIR *pdir=NULL;
		struct dirent *pdirent=NULL;
		pdir=opendir(dir_name);
		if(NULL==pdir)
		{
				return;
		}
		chdir(dir_name);
		while(1)
		{
				pdirent=readdir(pdir);
				if(NULL==pdirent)
				{
						break;
				}
				if(pdirent->d_name[0]!='.')
				{
						getcwd(path,sizeof(path));
						printf("%s/%s\n",path,pdirent->d_name);
						scna(pdirent->d_name);
				}
		}
		closedir(pdir);
		chdir("..");
}
