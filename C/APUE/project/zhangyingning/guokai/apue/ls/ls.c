#include "apue.h"
int show_file_no();
void mode_lai(struct stat *stat);
void show_i_no_file(char *file_flage);

int main(int argc, char **argv)
{
	int ret,i,n=0;
	char file_flage[4];

	memset(file_flage, 0, sizeof(file_flage));

	while(1)
	{
		ret=getopt(argc, argv, "lai");
		if(ret==-1)
		{
				if(n==0)
				{
					if(argv[1]!=NULL)
					show_file(&argv[optind]);	
					else
					show_file_no();
				}
				else
				break;
		}
		n++;
		switch(ret)
		{
				case 'l':
				{
						strcat(file_flage, "l");
						break;
				}
				case 'a':
				{
						strcat(file_flage, "a");
						break;
				}
				case 'i':
				{
						strcat(file_flage, "i");
						break;
				}
				case '?':
				{
						break;
				}
				default:
				{
						break;
				}

		}			
	}
		if(strlen(file_flage)!=0)
		{			
			if(argv[optind]!=NULL)	
			{
				show_i_file(&argv[optind],file_flage);
			}
			else
			{
				show_i_no_file(file_flage);
			}
				
		}	
}

void show_i_no_file(char *file_flage)
{
	int ret,i,j,k;
	DIR *pdir = NULL;
	struct stat stat;
	struct dirent *pdirent = NULL;
	pdir = opendir("./");
	while(1)
	{
		int m=0,n=0;	
		pdirent = readdir(pdir);
		if(pdirent==NULL)
		{
			break;
		}
		lstat(pdirent->d_name,&stat);
		if((strlen(file_flage))==1)
		{
			if(file_flage[0]=='a')	
			printf("%s\n",pdirent->d_name);
			if(file_flage[0]=='i')
			{
				if(pdirent->d_name[0]!='.')
				printf("%d %s\n",stat.st_ino,pdirent->d_name);			
			}
			if(file_flage[0]=='l')
			{
				if(pdirent->d_name[0]!='.')
				{	
					struct passwd *puid = NULL;
					struct passwd *pgid	= NULL;
					puid = getpwuid(stat.st_uid);
					pgid = getpwuid(stat.st_gid);	
					mode_lai(&stat);
					printf("%d  %s  %s  %d  %s	%s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,pdirent->d_name,ctime(&stat.st_atime));
				}
			}		
		}
		if((strlen(file_flage))==2)
		{			
			if((file_flage[0]=='a'&&file_flage[1]=='i')||file_flage[0]=='i'&&file_flage[1]=='a')	
			printf("%d %s\n",stat.st_ino,pdirent->d_name);
		}
		if((strlen(file_flage))==2)
		{
			if((file_flage[0]=='a'&&file_flage[1]=='l')||file_flage[0]=='l'&&file_flage[1]=='a')	
			{
				struct passwd *puid = NULL;
				struct passwd *pgid	= NULL;
				puid = getpwuid(stat.st_uid);
				pgid = getpwuid(stat.st_gid);	
				mode_lai(&stat);
				printf("%d  %s  %s  %d  %s	%s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,pdirent->d_name,ctime(&stat.st_atime));
			}
		}
		if((strlen(file_flage))==2)
		{
			if((file_flage[0]=='l'&&file_flage[1]=='i')||file_flage[0]=='i'&&file_flage[1]=='l')	
			{
				if(pdirent->d_name[0]!='.')
				{	
					struct passwd *puid = NULL;
					struct passwd *pgid	= NULL;
					puid = getpwuid(stat.st_uid);
					pgid = getpwuid(stat.st_gid);	
					printf("%d ",stat.st_ino);			
					mode_lai(&stat);
					printf("%d  %s  %s  %d  %s	%s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,pdirent->d_name,ctime(&stat.st_atime));
				}
			}
		}
		if((strlen(file_flage))==3)
		{
				struct passwd *puid = NULL;
				struct passwd *pgid	= NULL;
				puid = getpwuid(stat.st_uid);
				pgid = getpwuid(stat.st_gid);	
				printf("%d ",stat.st_ino);			
				mode_lai(&stat);
				printf("%d  %s  %s  %d  %s	%s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,pdirent->d_name,ctime(&stat.st_atime));			
		}
	}
}



int show_file(char **a[0])
{
	int ret;	
	DIR *pdir = NULL;	
	struct dirent *pdirent = NULL;
	ret = chdir((char *)a[0]);
	if(ret==0)
	{
		pdir = opendir("./");
		if(pdir == NULL)
		{
			perror("opendir");
			return -1;
		}
		while(1)
		{
			pdirent = readdir(pdir);
			if(pdirent==NULL)
			{
				break;
			}
			if((pdirent->d_name[0])!='.')
			printf("%s\n",pdirent->d_name);
		}
	}
	if(ret==-1)
	{ 
		printf("%s\n",a[0]);
	}
}


int show_file_no()
{
	DIR *pdir = NULL;
	struct dirent *pdirent = NULL;
	pdir = opendir("./");
	if(pdir == NULL)
	{
		perror("opendir");
		return -1;		
	}
	while(1)
	{
		pdirent = readdir(pdir);
		if(pdirent== NULL)
		{
			break;
		}
		if(pdirent->d_name[0]!='.')
		printf("%s\n",pdirent->d_name);		
	}
}

int show_i_file(char **a[],char *file_flage)
{	
	int ret,i,j,n=0;
	struct stat stat;
	ret = lstat((char*)a[0],&stat);
	for(i=0;i<4;i++)
	{		
		if(file_flage[i]=='i')
		{
			for(j=0;j<4;j++)
			{
				if(file_flage[j]=='l')
				{
					struct passwd *puid = NULL;
					struct passwd *pgid	= NULL;
				   	puid = getpwuid(stat.st_uid);
					pgid = getpwuid(stat.st_gid);	
					printf("%d  ",stat.st_ino);
					mode_lai(&stat);
					printf("%d  %s  %s  %d  %s	%s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,a[0],ctime(&stat.st_atime));
					n++;
					break;	
				}			
			}
			if(n!=0)
			{
				break;
			}
			else
			{					
				printf("%d %s",stat.st_ino,a[0]);
				break;	
			}

		}
	
		else if(file_flage[i]=='l')
		{
			for(j=0;j<4;j++)
			{	
				if(file_flage[j]=='i')	
				{						
					struct passwd *puid = NULL;
					struct passwd *pgid	= NULL;
				   	puid = getpwuid(stat.st_uid);
					pgid = getpwuid(stat.st_gid);	
					printf("%d ",stat.st_ino);
					mode_lai(&stat);
					printf("%d  %s  %s  %d  %s  %s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,a[0],ctime(&stat.st_atime)); 
					n++;
				}				
			}

			if(n!=0)
			{
				break;
			}
			else
			{
					struct passwd *puid = NULL;
					struct passwd *pgid	= NULL;
				   	puid = getpwuid(stat.st_uid);
					pgid = getpwuid(stat.st_gid);	
					mode_lai(&stat);	
					printf("%d  %s  %s  %d  %s  %s",stat.st_nlink,puid->pw_name,pgid->pw_name,stat.st_size,a[0],ctime(&stat.st_atime));
				   break;	
			}
			
		}
		
	}		
}

void func(int n,char *mode,int num)
{
	int i,m=n;
	if(n==4||n==5||n==6||n==7)
	{
		mode[num]='r';
	}
	else
	{
		mode[num]='-';
	}
	n=m;
	if(n==2||n==3||n==6||n==7)
	{
		mode[num+1]='w';
	}
	else
	{
		mode[num+1]='-';
	}
	n=m;
	if(n==1||n==3||n==5||n==7)
	{
		mode[num+2]='x';
	}
	else
	{
		mode[num+2]='-';
	}
}	

void mode_lai(struct stat *stat)
{
	char mode[11]={0};
	if(S_ISREG(stat->st_mode))
	{
		mode[0]='-';
	}
	else if(S_ISDIR(stat->st_mode))
	{
		mode[0]='d';
	}
	else if(S_ISCHR(stat->st_mode))
	{
		mode[0]='c';
	}
	else if(S_ISBLK(stat->st_mode))
	{
		mode[0]='b';
	}
	else if(S_ISFIFO(stat->st_mode))
	{
		mode[0]='p';
	}
	else if(S_ISLNK(stat->st_mode))
	{
		mode[0]='l';
	}
	else if(S_ISSOCK(stat->st_mode))
	{
		mode[0]='s';
	}
	int mode_num=0;
	mode_num=(stat->st_mode>>6)&0x7;
    func(mode_num,mode,1);
	mode_num=(stat->st_mode>>3)&0x7;
	func(mode_num,mode,4);
	mode_num=stat->st_mode&0x7;
	func(mode_num,mode,7);
	printf("%s ",mode);	
}

