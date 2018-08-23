#include"apue.h"

void get_mode(int mode_num,char *p);
int main(int argc, char **argv)
{
		struct stat stat;
		time_t t;
		struct tm * tm;
		char mode[11];
		char *tim;


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
		printf("mode=%s\n", mode);

		int mode_num=0;
		mode_num=(stat.st_mode>>6)&0x7;
		get_mode(mode_num,&mode[1]);

		mode_num=(stat.st_mode>>3)&0x7;
		get_mode(mode_num,&mode[4]);
//		printf("2:%d\n", mode_num);

		mode_num=stat.st_mode&0x7;
		get_mode(mode_num,&mode[7]);
//		printf("3:%d\n", mode_num);
		t = stat.st_mtime;
		tim = ctime(&t);
		printf("%s %s\n", mode,tim);
		return 0;
}

void get_mode(int mode,char *p)
{
	if(mode >= 4 )
	{
		p[0] = 'r';
	}
	else
	{
		p[0] = '-';
	}
	if(mode == 2||mode == 3||mode == 6||mode == 7)
	{
		p[1] = 'w';
	}
	else
	{
		p[1] = '-';
	}
	if(mode == 1||mode == 3||mode == 5||mode == 7)
	{
		p[2] = 'x';
	}
	else
	{
		p[2] = '-';
	}
}
