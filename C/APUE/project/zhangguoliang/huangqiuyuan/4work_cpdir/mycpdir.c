#include"../apue.h"

#include"cp.h"

void rd(DIR *dir_src,char *now)
{
	struct dirent *red;
	struct stat stat;
	char n[50],s[50];
	strcpy(n,now);
	while(1)
	{
		red=readdir(dir_src);
		//printf("%s \n",red->d_name);
		if(red==NULL)
			break;
			if(red->d_name[0]!='.')
			{
				strcpy(now,n);			
				lstat(red->d_name,&stat);
				strcat(now,"/");
				strcat(now,red->d_name);
				if(S_ISDIR(stat.st_mode))
				{
				mkdir(now,0777);				
				DIR *tdir=opendir(red->d_name);
				chdir(red->d_name);
				rd(tdir,now);			
				chdir("../");
				}
			else
				{
					cp(red->d_name,now);
					printf("%s copy sucess!\n",red->d_name);
				}
			}
	}
}


int main(int argc,char **argv)
{
	char now[256],src[250];
	if(argc!=3)
	{
		perror("loose dir name");
		return 0;
	}
	
	DIR *dir_src=opendir(argv[1]);
		if(dir_src==NULL)
		{
			perror("NO DIR_1");
			return -1;
		}
	strcpy(src,getcwd(src,sizeof(src)));
	strcat(src,"/");
	strcat(src,argv[1]);
	DIR *dir_des=opendir(argv[2]);
		if(dir_des==NULL)
		{
			mkdir(argv[2],0777);		
		}
	
	strcpy(now,getcwd(now,sizeof(now)));
	strcat(now,"/");
	strcat(now,argv[2]);
	
	chdir(argv[1]);
	rd(dir_src,now);
	
	return 0;
}
