#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <errno.h>
void char_mode(int mode_num,int num,char *mode);
int order_deal(int argc,char **argv);
int find_fileName(char *path,char *file_name,int order);
int information( char *file_name,int order,int length);
void ls_l(struct stat stat);
void show_file(char *path,char *file_name,int order);
void deal_path(char *path,char *file_name);
int main(int argc,char **argv)
{
		char file_name[256];
		int order=0;
		int i;
		order = order_deal(argc,argv);

		if((argc > 3)||(argc == 3&&argv[1][0]!='-'))
		{

			//	printf("user a.out path\n");
			//	return -1;
				if(argv[1][0]=='-')
						i=2;
				else
						i=1;
				for(;i<argc;i++)
				{
						printf("\n%s:\n",argv[i]);
						find_fileName(argv[i],file_name,order);
				}

		}
		if(argc == 1)
				find_fileName(".",file_name,8);
		if(argc == 2)
		{
				if(argv[1][0]=='-')
						find_fileName(".",file_name,order);
				else
						find_fileName(argv[1],file_name,8);
		}
		if(argc == 3)
		{
				find_fileName(argv[2],file_name,order);

		}
		printf("\n");
		return 0;



}
int order_deal(int argc,char **argv)
{
		int order = 0;
		int ret;
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
								{
									//显示所有属性
//										printf("all attri\n");
										order = (order|0x01);
//										order = 1;										
										break;
								}
						case 'a':
								{
										//显示隐藏文件
//										printf("show hide\n");
										order = (order|0x02);
										break;
								}
						case 'i':
								{
//										printf("show file inode.\n");
										order = (order|0x04);
										break;
								}
						case '?':
								{
										printf("err.\n");
										break;
								}
						default:
								{
										printf("default.\n");
										break;
								}

				}

		}
		printf("order:%d\n",order);
		return order;
}
int find_fileName(char *path,char *file_name,int order)
{
		int length;
		DIR * dir;
		struct dirent * pDirent;
		dir = opendir(path);
		if(NULL == dir)
		{
			  //printf("%d\n",errno);
				if(errno == 20)
				{
						deal_path(path,file_name);
//						printf("path:%s file:%s \n",path,file_name);

						show_file(path,file_name,order);
				}
				else
						perror("opendir");
				return -1;
		}
		while(1)
		{
				pDirent = readdir(dir);
				if(NULL == pDirent)
				{
//						perror("readdir");
						closedir(dir);
						return -1;
				}
				memset(file_name,0,sizeof(file_name));
				sprintf(file_name,"%s/%s",path,pDirent->d_name);
				length = strlen(path);
				information(file_name,order,length);
		}
		return 0;

}
void deal_path(char *path,char *file_name)
{
		int i;
		int flig = -1;
		for(i=0;i<strlen(path);i++)
		{
				if(path[i]=='/')
						flig = i;
		}
		if(flig == -1)
		{
				strcpy(file_name,path);
				strcpy(path,".");
					
		}
		else
		{
				path[flig] = '\0';
				strcpy(file_name,path+flig+1);
		}


}
void show_file(char *path,char *file_name,int order)
{
		int length;
		DIR * dir;
		struct dirent * pDirent;
		dir = opendir(path);
				if(NULL == dir)
				{
						perror("opendir");
						return ;
				}
		while(1)
		{
				pDirent = readdir(dir);
				if(NULL == pDirent)
				{
//						perror("readdir");
						closedir(dir);
						return ;
				}
				if(strcmp(pDirent->d_name,file_name)==0)
				{
						sprintf(file_name,"%s/%s",path,pDirent->d_name);
//						printf("%s\n",file_name);
						length = strlen(path);

						information(file_name,order,length);
				}
		}		
		return;
}


int information( char *file_name,int order,int length)
{
		struct stat stat;
		static int i=0;
		if( (order&0x02) || (file_name[length+1] != '.') )
		{
				lstat(file_name, &stat);
				if(order&0x04)
				{
						printf("%-7d",stat.st_ino);
				}

				if((order&0x01))
				{
						ls_l(stat);
				}
				if(order==0)
				{
						i++;
						if(i==5)
						{
								i=0;
								printf("\n");
						}
						printf("%-30s   ",file_name+length+1);
				}
				else
						printf(" %s\n",file_name+length+1);
		}
		
//	printf("%-7d %s %-3d %-3d %3d %9d %d %d %d",stat.st_ino ,mode ,stat.st_nlink ,stat.st_uid ,stat.st_gid ,stat.st_size ,stat.st_atime ,stat.st_mtime ,stat.st_ctime);
	

	return 0;
}
void ls_l(struct stat stat)
{
		char mode[11];
		memset(mode, 0, sizeof(mode));
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

		char_mode((stat.st_mode>>6)&0x7,1,mode);
		char_mode((stat.st_mode>>3)&0x7,4,mode);
		char_mode((stat.st_mode)&0x7,7,mode);
		printf("  %s %3d",mode,stat.st_nlink);
		struct passwd * pAss;
		pAss = getpwuid(stat.st_uid);
		printf(" %4s",pAss->pw_name);
		pAss = getpwuid(stat.st_gid);   //gid mei genggai
		printf(" %4s",pAss->pw_name);
		printf(" %9d",stat.st_size);
		char *time_file;
		time_file = ctime(&stat.st_ctime);
		time_file[strlen(time_file)-1]='\0';
		printf(" %s",time_file);

}
void char_mode(int mode_num,int num,char *mode)
{
		if(mode_num&0x4)
		mode[num]='r';
		else
				mode[num]='-';

		if(mode_num&0x2)
		mode[num+1]='w';
		else
				mode[num+1]='-';
		if(mode_num&0x1)
		mode[num+2]='x';
		else
				mode[num+2]='-';
}
