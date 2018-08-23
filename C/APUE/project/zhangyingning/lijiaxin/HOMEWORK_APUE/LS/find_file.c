#include"apue.h"

int file_show(char *argv,int show_l,int show_a,int show_i)
{
		DIR *pdir=NULL;
		struct dirent *pdirent=NULL;
		struct stat stat;
		int ret;
		pdir=opendir(argv);
		if(pdir==NULL)
		{
				perror("poendir");
				return -1;
		}
		ret = chdir(argv);
		if(ret<0)
		{
				perror("chdir");
				return -1;
		}
		if(pdir==NULL)
		{
				perror("opendir");
				return -1;
		}
		while(1)
		{
				pdirent=readdir(pdir);
				if(pdirent==NULL)
				{
						break;
				}

				if('.'==pdirent->d_name[0]&&show_a==0)
				{
						continue;
				}
				
				show_inode(pdirent->d_name,show_i);
				show_all_attr(pdirent->d_name,show_l);
			
				printf("%s   ",pdirent->d_name);
				if(show_l==1)
				{
					printf("\n");
				}
		}
		closedir(pdir);
}
