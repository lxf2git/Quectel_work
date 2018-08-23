/****************
 *复制目录
 *
 *使用说明： 可以使用相对路经或者绝对路径
 *
 *
 *
 * **************/

#include"../apue.h"

#define  LEN      (1024)

static int len;

int scan_file(char *sour_path, char* dest_path,struct stat* psta, DIR* pd, 
				struct dirent* pdir,char* judge_path);

int mycp(int fds, int fdd);

int main(int argc, char** argv)
{
		if (argc != 3)
		{
				fprintf(stdout, "usage...\n");
				return FALSE;  
		}

		struct stat sta;
		struct stat* pstat = &sta;
		DIR* pd = NULL;
		struct dirent* pdir = NULL;
		char sour_path[LEN];
		char dest_path[LEN];
		char judge_path[LEN];

		bzero(sour_path, LEN);
		bzero(dest_path, LEN);
		bzero(judge_path, LEN);

		if (*argv[1] !='/')
		{
				getcwd(sour_path, LEN);
				sprintf(sour_path, "%s/%s", sour_path, argv[1]);
		}
		else
		{
				sprintf(sour_path, "%s", argv[1]);
		}

		if ((chdir(argv[2])) < 0)
		{
				mkdir(argv[2], 0777);
				chdir(argv[2]);
		}
		getcwd(dest_path, LEN);
		strcpy(judge_path, dest_path);

		len = strlen(sour_path);
		printf("len = %d\n", len);

		puts(sour_path);
		puts(dest_path);
		puts(judge_path);

		scan_file(sour_path, dest_path , pstat,  pd, pdir, judge_path);

		return TURE; 
}	

#if 1
int scan_file(char *sour_path, char* dest_path, struct stat* pstat, DIR* pd, 
				struct dirent* pdir,
				char* judge_path)
{
		static int fds;
		static int fdd;

		if ((pd =opendir(sour_path)) == NULL)
		{
				perror("opendir");
				exit(-1);
		}

		if ((chdir(sour_path)) <0 )
		{
				perror("chdir");
				exit(-1);
		}

		while(1)
		{
				pdir = readdir(pd);

				if(pdir == NULL)
				{
						break;
				}

				if (*pdir->d_name == '.')
				{
						continue;	
				}

				if ((lstat(pdir->d_name, pstat)) < 0)
				{	

						perror("lstat");
						exit(-1);
				}

				bzero(sour_path, LEN);
				bzero(dest_path, LEN);

				getcwd(sour_path, LEN);

				sprintf(sour_path,"%s/%s", sour_path, pdir->d_name);
				sprintf(dest_path,"%s/%s",judge_path,sour_path+len);

				if (S_ISDIR(pstat->st_mode))
				{						

						if((strcmp(sour_path, judge_path)) == 0)  //不复制目录本身
						{
								continue;
						}


					//	printf("[%s = %d line] sour_path->dir:%s\n", __FUNCTION__, __LINE__ , sour_path);
					//	printf("[%s = %d line] dest_path->dir:%s\n", __FUNCTION__, __LINE__ ,dest_path); 

						if ((mkdir(dest_path, 0777)) < 0)
						{
								perror("mkdir");
								exit(-1);
						}

						scan_file(sour_path, dest_path,pstat, pd, pdir, judge_path);
				}

				else
				{

					//printf("[%s = %d line] sour_path->file:%s\n", __FUNCTION__, __LINE__ , sour_path);
					//printf("[%s = %d line] dest_path->file:%s\n", __FUNCTION__, __LINE__ ,dest_path); 

						if (S_ISLNK(pstat->st_mode)) //链接文件
						{
							link(sour_path, dest_path);

							continue;
						}

						if ((fds = open(sour_path, O_RDONLY)) < 0)
						{
								perror("open");
								exit(-1);
						}

						if ((fdd = creat(dest_path, 0666)) < 0)
						{

					//	printf("[%s = %d line] dest_path->file:%s\n", __FUNCTION__, __LINE__ ,dest_path); 
								perror("creat");
								goto ERR;
						}

						if ((mycp(fds, fdd)) < 0)
						{
								printf("mycp failed");
								goto ERR;
						}

				}
		}

		if (chdir("../") <0)
		{
				perror("chdir");
				exit(-1);
		}

		return TURE; 
ERR:
		close(fds);
ERR1:
		close(fdd);
		return FALSE;  

}
#endif 


int mycp(int fds, int fdd)
{
		int re = 0;
		char buf[LEN];
		bzero(buf, LEN);

		while(1)
		{
				if ((re = read(fds, buf, LEN)) < 0)
				{
						perror("read");
						goto ERR;
				}

				if (re == 0)
				{
						break;
				}

				if ((write(fdd, buf, re)) < 0)
				{
						perror("write");
						goto ERR;
				}

				bzero(buf, LEN);
		}

		close(fds);
		close(fdd);
		return TURE; 

ERR:
		close(fds);
		close(fdd);
		return FALSE;  

}
