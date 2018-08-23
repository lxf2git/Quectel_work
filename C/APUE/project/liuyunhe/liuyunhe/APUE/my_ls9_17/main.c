#include "apue.h"
//ls -lix file/dir
//:表示选项后有参数 optarg:存放选项参数
void show_all_attr(char* file_flage,struct stat stat)
{
			if('l'==file_flage[0]||'l'==file_flage[1]||'l'==file_flage[2])
			{
				mode(stat);
				printf(" %3d ",stat.st_nlink);
				struct passwd *pPasswd=NULL;;
				pPasswd = getpwuid(stat.st_uid);
				printf(" %s ",pPasswd->pw_name);
				struct group *getgid = NULL;
				getgid = getgrgid(stat.st_gid);
				printf(" %s ",getgid->gr_name);
				printf(" %5d ",stat.st_size);
				struct tm *Tm;
					  Tm = localtime(&stat.st_ctime);
				printf("%2d %2d %2d:%2d ",Tm->tm_mon,Tm->tm_mday,Tm->tm_hour,Tm->tm_min);
			}
}
void show_inode(char* file_flage,struct stat stat)
{
			if('i'==file_flage[0]||'i'==file_flage[1]||'i'==file_flage[2])
			{
				printf("%6d ",stat.st_ino);
			}
}
int show_hide(char *file_flage,char name)
{
						if('a'!=file_flage[0]&&'a'!=file_flage[1]&&'a'!=file_flage[2])
						{
							if('.' == name)
							{
									return -1;
							}
						}
						return 0;
}
int main(int argc, char **argv)
{
	int ret=0;
	char file_flage[4];
	
	DIR *pdil =NULL;
	struct dirent *pdirent = NULL;
	struct stat stat;
	char mode;
	memset(file_flage, 0, sizeof(file_flage));

	while(1)
	{
		ret=getopt(argc, argv, "lai");
		if(ret==-1)
		{
			//	printf("nothing.\n");
			//	printf("arg=%s\n", argv[optind]);
				break;
		}
	//	printf("ret=%c\n", ret);
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
				//	printf("err.\n");
					break;
				}
				default:
				{
						printf("default.\n");
						break;
				}

		}
	}

		if(NULL==argv[optind])
		{
				pdil = opendir("./");
				if(NULL == pdil)
				{
						perror("opendir");
						return -1;
				}
				chdir("./");
				while(1)
				{
						pdirent = readdir(pdil);
						if(NULL == pdirent)
						{
							break;
						}
						ret = lstat(pdirent->d_name,&stat);
						if(-1 == ret)
						{
								perror(argv[optind]);
								goto ERR;
						}
						ret =0;
						ret = show_hide(file_flage,pdirent->d_name[0]);
						if(-1 == ret)
						{
								continue;
						}
						show_inode(file_flage,stat);
						show_all_attr(file_flage,stat);
						printf(" %s\n",pdirent->d_name);

				}
		}
		else
		{	
			pdil = opendir(argv[optind]);
			if(NULL==pdil)
			{
						ret = lstat(argv[optind],&stat);
						if(-1 == ret)
						{
								printf("sorry %s not\n",argv[optind]);
								exit(-1);
						}
						show_inode(file_flage,stat);
						show_all_attr(file_flage,stat);
						printf(" %s\n",argv[optind]);
			}
			else
			{
				chdir(argv[optind]);
				while(1)
				{
						pdirent = readdir(pdil);
						if(NULL == pdirent)
						{
							break;
						}
						ret = lstat(pdirent->d_name,&stat);
						if(-1 == ret)
						{
								perror(argv[optind]);
								goto ERR;
						}
						ret =0;
						ret = show_hide(file_flage,pdirent->d_name[0]);
						if(-1 == ret)
						{
								continue;
						}
						show_inode(file_flage,stat);
						show_all_attr(file_flage,stat);
						printf(" %s\n",pdirent->d_name);
				}
			}
		}
ERR:
		closedir(pdil);
		return 0;
	
}








