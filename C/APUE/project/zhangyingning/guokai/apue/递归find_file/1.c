#include"apue.h"

int main(int argc,char **argv)
{
	func(argv[1]);
}

int func(char *a)
{
	char buf[1024]={'\0'};	
	int ret;	
	DIR *pdir = NULL;
	struct dirent *pdirent = NULL;
	ret = chdir(a);
	getcwd(buf,sizeof(buf));
	printf("%s",buf);
	if(ret!=-1)
	{
		pdir = opendir("./");
		if(pdir==NULL)
		{
			perror("opendir");
			return -1;
		}
		while(1)
		{
			pdirent = readdir(pdir);
			if(pdirent==NULL)
			{
				chdir("..");	
				return 0;
			}
			if(pdirent->d_name[0]!='.')
			{	
				printf("  %s\n",pdirent->d_name);
			//	strcpy(buf,pdirent->d_name);	
				func(pdirent->d_name);			
			}
		}
	}
}
