#include "../apue.h"

int main(int argc, char **argv)
{
		DIR *pdir=NULL;
		struct dirent *pdirent=NULL;
		struct stat stat;
		char mode;
		int ret;

		pdir=opendir("..");
		if(pdir==NULL)
		{
				perror("opendir");
				return -1;
		}

		while(1)
		{
			pdirent=readdir(pdir);
			if(pdirent==NULL)//目录中的内容遍历完毕
			{
					break;
			}
			//d_name只是某个目录下的名称
			
			//在工作目录下查找该文件 
			ret=lstat(pdirent->d_name, &stat);
			if(ret<0)
			{
					perror("lstat");
					goto ERR;
			}
			if(S_ISREG(stat.st_mode))
			{
					mode='-';
			}
			else 
					if(S_ISDIR(stat.st_mode))
					{
							mode='d';
					}
					else
							if(S_ISCHR(stat.st_mode))
							{
									mode='c';
							}
							else
									if(S_ISBLK(stat.st_mode))
									{
											mode='b';
									}
									else
											if(S_ISFIFO(stat.st_mode))
											{
													mode='p';
											}
											else
													if(S_ISLNK(stat.st_mode))
													{
															mode='l';
													}
													else
															if(S_ISSOCK(stat.st_mode))
															{
																	mode='s';
															}

		}
		printf("name=%s type=%c\n", pdirent->d_name, mode);
ERR:
		closedir(pdir);
		return 0;
}




