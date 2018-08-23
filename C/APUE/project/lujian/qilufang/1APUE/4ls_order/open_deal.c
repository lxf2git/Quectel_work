#include"main.h"
int open_deal(struct stat *stat,char **file_name,DIR *pdir)
{
	int i=0;

	struct dirent * rent=NULL;
	while(1)
	{
		if(NULL==(rent=readdir(pdir)))
		{
			break;
		}
		file_name[i]=malloc(sizeof(char)*M);
		memset(file_name[i],0,sizeof(file_name[i]));
		strcpy(file_name[i],rent->d_name);	
		if((lstat(rent->d_name,&stat[i]))<0)
		{
			perror("lstat");
			return -1;
		}
		i++;
	}
	return i;
}
