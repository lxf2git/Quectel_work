#include "apue.h"

int main(int argc,char **argv)
{
		int ret=0;
		if(2!=argc)
		{
				perror("no argument");
				return -1;
		}
		ret=find_cata(argv[1]);
		if(ret<0)
		{
				perror("find_cata");
		}
		return 0;

}
int find_cata(char *argv)
{
	int ret=0;
	char buf[100]={'\0'};
	DIR *pdir = opendir(argv);
	if(pdir==NULL)
	{
			perror("opendir");
			return -1;
	}
	struct stat st;
	struct dirent *pdirent=NULL;
	ret = chdir(argv);
	getcwd(buf,sizeof(buf));
	if(ret<0)
	{
			perror("chdir");
	}
	while(1)
	{
			
			pdirent=readdir(pdir);
			
			if(pdirent==NULL)
			{
					break;
			}
			if(pdirent->d_name[0]=='.')
			{
					continue;
			}
			ret = stat(pdirent->d_name,&st);
			if(ret<0)
			{
					perror("stat");
					goto ERR;
			}
			if(S_ISDIR(st.st_mode))
			{
					find_cata(pdirent->d_name);
			}
			printf("%s/%s \n",buf,pdirent->d_name);
	}
	chdir("../");
	closedir(pdir);
	return 0;
ERR:
	closedir(pdir);
	return -1;
}
