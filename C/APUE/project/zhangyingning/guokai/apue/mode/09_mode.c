#include "apue.h"

int main(int argc, char **argv)
{
	struct stat stat;
	char mode[11];

	if(argc!=2)
	{
			printf("%s name", argv[0]);
			return -1;
	}

	memset(mode, 0, sizeof(mode));
	lstat(argv[1], &stat);
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

	int mode_num=0;
	char buf[1];
	mode_num=(stat.st_mode>>6)&0x7;
//	printf("1:%d\n", mode_num);
	func(mode_num,mode,1);
	mode_num=(stat.st_mode>>3)&0x7;
//	printf("2:%d\n", mode_num);
	func(mode_num,mode,4);
	mode_num=stat.st_mode&0x7;
//	printf("3:%d\n", mode_num);
	func(mode_num,mode,7);
//	sprintf(buf,"%d",stat.st_nlink);	
//	mode[10]=buf[1];
	printf("mode=%s\n", mode);
	

	return 0;
}

void func (int n,char *mode,int num)
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
	n = m;
	if(n==2||n==3||n==6||n==7)
	{
		mode[num+1]='w';			
	}
	else
	{
		mode[num+1]='-';
	}
	n = m;
	if(n==1||n==3||n==5||n==7)
	{
		mode[num+2]='x';		
	}
	else
	{
		mode[num+2]='-';
	}
}
