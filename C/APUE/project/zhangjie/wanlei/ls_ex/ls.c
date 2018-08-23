#include"../apue.h"
#include<time.h>
#include <grp.h>
#include<pwd.h>

void change_mode(char *pmode, struct stat stat);
int  show_file_name(char *pathname,int mode, int all, int ig);
void show_file(char *file_flag,char *pathname);

int main(int argc,char **argv)
{
	int ret,i=0;
	char file_flag[5];
	memset(file_flag, 0, sizeof(file_flag));
	while(1)
	{
		ret=getopt(argc,argv,"lai");
		if(ret==-1)
		{
			strcat(file_flag, " ");	
			break;
		}
		switch(ret)
		{
			case 'l':
				strcat(file_flag, "l");	
				break;	
			case 'a':
				strcat(file_flag, "a");	
				break;		
			case 'i':
				strcat(file_flag, "i");	
				break;		
			case '?':
				printf("err\n");
				break;
			dafault:
				break;
		}
	}
//	printf("%s\n",argv[optind]);
	if(NULL == argv[optind])
	{
		show_file("./",file_flag);
	}
	else
	{
		show_file(argv[optind],file_flag);
	}
	return 0;
}

void show_file(char *pathname,char *file_flag)
{
	int all=0,ig=0,mode=0;
	int i;
	for(i=0;i<4;i++)
	{
		if(file_flag[i]=='a')
		{
			all=1;
		}
		if(file_flag[i]=='l')
		{
			mode=1;
		}
		if(file_flag[i]=='i')
		{
			ig=1;
		}
		if(file_flag[0]==' ')
		{
			break;
		}
	}
//	printf("%s\n",pathname);
	show_file_name(pathname,mode,all,ig);
}

int show_file_name(char *pathname,int mode_, int all, int ig)
{
	DIR *pdir=NULL;
	struct dirent *pdirent=NULL;
	struct stat buf;
	struct group *pg=NULL;
	struct passwd *passwd=NULL;
	struct tm *ptm=NULL;
	long total=0;
	char mode[11];
	char month[][4]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", 
			"Aug", "Sep", "Oct", "Nov", "Dec"};
	memset(mode, 0, sizeof(mode));
	pdir=opendir(pathname);
	if(NULL==pdir)
	{
		int ret = lstat(pathname, &buf);
		if(ret==-1)
		{
			perror("ls");
			return 0;
		}
		if(0==all&&'.' == pathname[0])
		{
			return 0;
		}
		if(1==ig)
		{
			printf("%7d ",buf.st_ino);
		}
		if(1==mode_)
		{	
			memset(mode, 0, sizeof(mode));
			change_mode(mode, buf);
			printf("%s %2d ", mode, buf.st_nlink);
			pg = getgrgid(buf.st_gid);
			printf("%-5s ", pg->gr_name);
			passwd = getpwuid(buf.st_uid);
			printf("%-5s %5d ", passwd->pw_name, buf.st_size);
			ptm = gmtime(&buf.st_atime);
			printf("%s %2d %2d:%2d ",month[ptm->tm_mon], ptm->tm_mday,
								ptm->tm_hour, ptm->tm_min);
			total+=buf.st_size;
		}
		printf("%s  ",pathname);
		putchar('\n');
		return 0;
	}
	int ret=chdir(pathname);
	if(ret<0)
	{
		perror("chdir");
		goto ERR;
	}
	while(1)
	{
		pdirent = readdir(pdir);
		if(NULL == pdirent)
		{
			break;
		}
		lstat(pdirent->d_name, &buf);
		if(0==all&&'.' == pdirent->d_name[0])
		{
			continue;
		}
		if(1==ig)
		{
			printf("%7d ",buf.st_ino);
		}
		if(1==mode_)
		{	
			memset(mode, 0, sizeof(mode));
			change_mode(mode, buf);
			printf("%s %2d ", mode, buf.st_nlink);
			pg = getgrgid(buf.st_gid);
			printf("%-5s ", pg->gr_name);
			passwd = getpwuid(buf.st_uid);
			printf("%-5s %5d ", passwd->pw_name, buf.st_size);
			ptm = gmtime(&buf.st_atime);
			printf("%s %2d %2d:%2d ",month[ptm->tm_mon], ptm->tm_mday,
								ptm->tm_hour, ptm->tm_min);
			total+=buf.st_size;
		}
		printf("%s  ",pdirent->d_name);
		if(1==mode_)
		{
			putchar('\n');
		}
	}
	if(1 != mode_)
	{
		putchar('\n');
	}
	else
	{
		printf("total %ld\n",total/1024);
	}
ERR :
	closedir(pdir);
	return 0;
}

void change_mode(char *pmode, struct stat stat)
{
	char table[][4] = {"---", "--x", "-w-", "-wx", "r--",
		   				"r-x", "rw-", "rwx"};
	if(S_ISREG(stat.st_mode))
	{   
			pmode[0]='-';
	}   
	else if(S_ISDIR(stat.st_mode))
	{   
			pmode[0]='d';
	}   
	else if(S_ISCHR(stat.st_mode))
	{   
			pmode[0]='c';
	}   
	else if(S_ISBLK(stat.st_mode))
	{   
			pmode[0]='b';
	}   
	else if(S_ISFIFO(stat.st_mode))
	{   
			pmode[0]='p';
	}
	else if(S_ISLNK(stat.st_mode))
	{
			pmode[0]='l';
	}
	else if(S_ISSOCK(stat.st_mode))
	{
			pmode[0]='s';
	}
	int i,mode_num=0;
	for(i=6;i>=0;i=i-3)
	{
		mode_num=stat.st_mode>>i&0x07;
		strcat(pmode,table[mode_num]);
	}
}
