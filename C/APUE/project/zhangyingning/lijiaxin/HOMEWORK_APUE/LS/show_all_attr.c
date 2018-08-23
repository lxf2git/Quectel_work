#include "apue.h"

char *exch_month(int n);
int time_add_zero(int n);
int show_all_attr(char *argv,int l)
{
	if(l==0)
	{
			return 0;
	}
	struct stat stat;
	char mode[11];//0 1-9 10
	int ret;
	int i;
	int mode_num=0;
	//穷举法
	char mode_str[][4]={"---",
			            "--x",
						"-w-",
						"-wx",
						"r--",
						"r-x",
						"rw-",
						"rwx"};
	memset(mode, 0, sizeof(mode));
	lstat(argv, &stat);
	if(S_ISREG(stat.st_mode))
	{
		mode[0]='-';
	}
	else 
		if(S_ISDIR(stat.st_mode))
		{
			mode[0]='d';
		}
		else
			if(S_ISCHR(stat.st_mode))
			{
					mode[0]='c';
			}
			else
				if(S_ISBLK(stat.st_mode))
				{
						mode[0]='b';
				}
				else
					if(S_ISFIFO(stat.st_mode))
					{
							mode[0]='p';
					}
					else
						if(S_ISLNK(stat.st_mode))
						{
								mode[0]='l';
						}
						else
							if(S_ISSOCK(stat.st_mode))
							{
									mode[0]='s';
							}
	for(i=6; i>=0; i=i-3)
	{
		mode_num=(stat.st_mode>>i)&0x7;
		strcat(mode,mode_str[mode_num]);
	}
	
	printf("%s ", mode);
	printf("%3d ",stat.st_nlink);
	printf("%s ",(getpwuid(stat.st_uid))->pw_name);
	printf("%s",(getgrgid(stat.st_gid))->gr_name);
	printf("%5d ",stat.st_size);
	printf("%s ",exch_month((localtime(&stat.st_mtime))->tm_mon));
	printf("%d ",time_add_zero((localtime(&stat.st_mtime))->tm_mday));
	printf("%d:",time_add_zero((localtime(&stat.st_mtime))->tm_hour));
	printf("%d ",time_add_zero((localtime(&stat.st_mtime))->tm_min));

	return 0;
}

int time_add_zero(int n)
{
		if(n<10)
		{
				printf("0");
				return n;
		}
		return n;
}

char *exch_month(int n)
{
	char *str=NULL;
	switch(n)
	{
		case 0:str="Jan";break;
		case 1:str="Feb";break;
		case 2:str="Mar";break;
		case 3:str="Apr";break;
		case 4:str="May";break;
		case 5:str="Jun";break;
		case 6:str="Jul";break;
		case 7:str="Aug";break;
		case 8:str="Sep";break;
		case 9:str="Oct";break;
		case 10:str="Nov";break;
		case 11:str="Dec";break;
		default:perror("localtime");break;
	}
	return str;
}


















