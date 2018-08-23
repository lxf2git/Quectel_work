#include"main.h"

int maxlen;

int main(int argc, char **argv)
{
		pFile phead=NULL;
		init_node(&phead);
		ls(argc, argv, phead);
		unload_link(&phead);
		return 0;
}

void ls(int argc,char **argv, pFile phead)
{
		int ret;
		char file_flage[4];
		memset(file_flage, 0, sizeof(file_flage));
		while(1)
		{
				ret=getopt(argc, argv, "lai");
				if(ret==-1)
				{
						break;
				}
				switch(ret)
				{
						case 'l':
								strcat(file_flage, "l");
								break;
						case 'a':
								strcat(file_flage, "a");
								break;
						case 'i':
								strcat(file_flage, "i");
								break;
						default:
								break;
				}
		}
		if(NULL==argv[optind])
		{
				save_struct(file_flage,"./", phead);
		}
		else
		{
				save_struct(file_flage,argv[optind], phead);
		}
}

void save_struct(char *file_flage,char *path, pFile phead)
{
		pFile pnew=NULL;
		int total=0;
		DIR *pdir=NULL;
		struct dirent *pdirent=NULL;
		pdir=opendir(path);
		if(NULL==pdir)
		{
				return;
		}
		while(1)
		{
				pdirent=readdir(pdir);
				if(NULL==pdirent)
				{
						break;
				}
				if(SUC==judge(file_flage, 'a'))
				{
						int size;
						int n=4096;
						int i=0;
						init_node(&pnew);
						size=mode(pdirent->d_name,pnew);
						while(1)
						{
								if(size>n-4096&&size<=n)
								{
										total+=n;
										break;
								}
								n+=4096;
						}
						strcpy(pnew->name,pdirent->d_name);
				}
				else
				{
						if(pdirent->d_name[0]!='.')
						{
								init_node(&pnew);
								total+=mode(pdirent->d_name,pnew);
								strcpy(pnew->name,pdirent->d_name);
						}
						else
						{
								continue;
						}
				}
				add_node(phead,pnew);
		}
		if(SUC==judge(file_flage, 'l'))
		{
				printf("total %d\n",total/1024);
		}
		show(file_flage, phead);
}

void show(char *file_flage, pFile phead)
{
						printf("%d\n",maxlen);
		int count=0;
		pFile p=phead->next;
		while(p!=phead)
		{
				count++;
				if(SUC==judge(file_flage, 'i'))
				{
						printf("%d ",p->ino);
				}
				if(SUC==judge(file_flage, 'l'))
				{
						printf("%s %d %-*s %-*s %5d %s %d %2d:%2d ",p->mode,p->link, maxlen,p->uname, maxlen,p->gname, p->size, p->mon, p->day, p->hour, p->min);
						printf("%s\n",p->name);
				}
				else
				{
						printf("%-10s ",p->name);
				}
				p=p->next;
		}
		if(FAIL==judge(file_flage, 'l'))
		{
				printf("\n");
		}
}

int judge(char *file_flage,char ch)
{
		int i=0;
		while(1)
		{
				if('\0'==file_flage[i])
				{
						break;
				}
				if(ch==file_flage[i])
				{
						return SUC;
				}
				i++;
		}
		return FAIL;
}

int mode(char *file_name, pFile pnew)
{
		struct passwd *passwd;
		struct group *group;
		struct stat stat;
		struct tm *time;
		char mode[11];
		char mode_str[][4]={"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
		char mon[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		int i;
		memset(mode, 0, sizeof(mode));
		lstat(file_name,&stat);
		if(S_ISREG(stat.st_mode))
		{
				mode[0]='-';
		}
		else
		{
				if(S_ISDIR(stat.st_mode))
				{
						mode[0]='d';
				}
				else
				{
						if(S_ISCHR(stat.st_mode))
						{
								mode[0]='c';
						}
						else
						{
								if(S_ISBLK(stat.st_mode))
								{
										mode[0]='b';
								}
								else
								{
										if(S_ISFIFO(stat.st_mode))
										{
												mode[0]='p';
										}
										else
										{
												if(S_ISLNK(stat.st_mode))
												{
														mode[0]='l';
												}
												else
												{
														if(S_ISSOCK(stat.st_mode))
														{
																mode[0]='s';
														}
												}
										}
								}
						}
				}
		}
		for(i=6;i>=0;i=i-3)
		{
				strcat(mode,mode_str[(stat.st_mode>>i)&7]);
		}
		passwd=getpwuid(stat.st_uid);
		group=getgrgid(stat.st_gid);
		time=localtime(&stat.st_ctime);
		pnew->ino=stat.st_ino;
		strcpy(pnew->mode,mode);
		pnew->link=stat.st_nlink;
		maxlen=strlen(passwd->pw_name);
	   	strcpy(pnew->uname,passwd->pw_name);
		strcpy(pnew->gname,group->gr_name);
		pnew->size=stat.st_size;
		strcpy(pnew->mon,mon[time->tm_mon]);
		pnew->day=time->tm_mday;
		pnew->hour=time->tm_hour;
		pnew->min=time->tm_min;
		return stat.st_size;
}
