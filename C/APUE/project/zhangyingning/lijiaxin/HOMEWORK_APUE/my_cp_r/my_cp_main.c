#include "apue.h"

int main(int argc,char **argv)
{
		int ret=0;
		if(3!=argc)
		{
				perror("no argument");
				return -1;
		}
		ret=find_data(argv[1],argv[2]);
		if(ret<0)
		{
				perror("find_data");
		}
		return 0;
}

int find_data(char *str1,char *str2)
{
		int ret=0;
		char buf[100]={'\0'};
		char buff[100]={'\0'};
		char dest_tmp[]="/";

		strcpy(buff,str2);

		DIR *pdir = opendir(str1);
		if(pdir==NULL)
		{
				perror("opendir");
				return -1;
		}

		struct stat st;
		struct dirent *pdirent=NULL;

		mkdir(str2,0777);
		
		ret = chdir(str1);
		if(ret<0)
		{
				perror("chdir");
		}

		while(1)
		{
				pdirent=readdir(pdir);
				if(pdirent==NULL)
				{
						break;
				}

				ret = stat(pdirent->d_name,&st);
				if(ret<0)
				{
						perror("stat");
						goto ERR;
				}
				if(pdirent->d_name[0]=='.')
				{
						continue;
				}

				if(S_ISDIR(st.st_mode))
				{
						strcpy(buf,buff);	
						strcat(buf,dest_tmp);
						strcat(buf,pdirent->d_name);

						if(ret<0)
						{
								if(errno==EEXIST);

								else
								{
									perror("mkdir");
									goto ERR;
								}
						}

						find_data(pdirent->d_name,buf);

				}
				else
				{
						my_cp(pdirent->d_name,buff);
						printf("buff:%s\n",buff);
				}
				
		}
		chdir("../");
		closedir(pdir);
		return 0;
ERR:
	closedir(pdir);
	return -1;
}
