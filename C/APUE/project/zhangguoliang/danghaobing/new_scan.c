#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//显示路径的文件扫描其
void scan_start(char*);

int main(int argc,char **argv)
{
	if(argc!=2)
	{
			printf("%s file_name\n",argv[0]);
			return -1;
	}
	scan_start(argv[1]);
}

void scan_start(char *a)
{
		char dir[256];
		char tran[256];
		strcpy(dir,a);
		DIR *pdir = opendir(a);
		struct dirent *pdirent;
		struct stat Stat;
		if(pdir==NULL)
		{
			perror("opendir");
			return ;
		}
		int ret = strlen(dir);
		dir[ret-1]=='/'?:(dir[ret]='/',dir[ret+1]='\0');
		chdir(dir);
		while( ((pdirent=readdir(pdir))!=NULL) )
		{
				if(pdirent->d_name[0]!='.')
				{
					if(!lstat(pdirent->d_name,&Stat))
					{
						strcpy(tran,dir);
						strcat(tran,pdirent->d_name);
						printf("%s\n",tran);
						if(S_ISDIR(Stat.st_mode))
						{
								scan_start(tran);
								chdir(dir);
						}
					}
					else
					{
							perror("lstat");
							break;
					}
				}	
		}
		closedir(pdir);
}
