#define _FILE_OFFSET_BITS 64
#include"show.h"
struct stat Stat;

void show_file_l_ex(struct stat Stat)
{
	get_mode(Stat);
	printf("%d ",Stat.st_nlink);
	printf("%s ",getpwuid(Stat.st_uid)->pw_name);
	printf("%s ",getgrgid(Stat.st_gid)->gr_name);
	printf("%4d ",Stat.st_size);
	char *p;
    	p = asctime(localtime(&Stat.st_mtime));
	strcpy(p,p+4);
	int ret = strlen(p);
	p[ret-9]='\0';
	printf("%s ",p);
}

void no_dir(int l_ex,int a_ex,int i_ex,char *p)
{
	if(lstat(p,&Stat)<0)
			perror("lstat");
	if(i_ex)
	 		printf("%d ",Stat.st_ino);
	if(l_ex)
			show_file_l_ex(Stat);
	printf("%s  ",p);
}

void is_dir(int l_ex,int a_ex,int i_ex,DIR *pdir)
{
	struct dirent *pdirent = NULL;
	while((pdirent=readdir(pdir))!=NULL)
	{
			if(a_ex)
			{
				no_dir(l_ex,a_ex,i_ex,pdirent->d_name);
				if(l_ex||i_ex)
				printf("\n");
			}
			else
			{
				if( pdirent->d_name[0]!='.' )
				{
					no_dir(l_ex,a_ex,i_ex,pdirent->d_name);
					if(l_ex)
					printf("\n");
				}
			}
			
	}
}

void dir_file(int l_ex,int a_ex,int i_ex,char *p)
{
	DIR *pdir = opendir(p);
	if(NULL==pdir)
	{
			no_dir(l_ex,a_ex,i_ex,p);
			printf("\n");
	}
	else
	{		chdir(p);
			if(l_ex)
			{
				lstat(p,&Stat);
				printf("total %d\n",Stat.st_size/100);
			}
			is_dir(l_ex,a_ex,i_ex,pdir);
			if(!l_ex)	
			printf("\n");
	}
}
