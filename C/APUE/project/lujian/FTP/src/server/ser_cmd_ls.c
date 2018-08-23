
#include "../include/ftp.h"
#include "server.h"

static int ls_l(int confd, char* file_name, struct send_pakg snd_pakg, struct sockaddr_in conaddr);

int ser_cmd_ls(int confd, char* file_name, struct sockaddr_in conaddr)
{

		socklen_t  len = sizeof(conaddr);
		struct send_pakg snd_pakg;
		memset(&snd_pakg, 0, sizeof(snd_pakg));
		char mode[11];
		memset(mode, 0, sizeof(mode));
		char file_buf[1024];
		memset(file_buf, 0, sizeof(mode));
		getcwd(file_buf, 1024);

		   		 // ls file 
				if (strlen(file_name) == 0)
				{
						strcpy(file_name,"./");
				}	

				DIR* pdir = NULL;
				struct dirent * pdirent = NULL;
				pdir = opendir(file_name);
				if (pdir ==NULL)
				{
						if ((access(file_name, F_OK)) < 0)
						{

								snd_pakg.pakg_type = ERR;
								strcpy(snd_pakg.data_buf.cmd_buf,"file is not exit");
								if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
								{

										printf("sendto\n");
								}
								return FALSE;
						}
						else
						{
							ls_l(confd, file_name, snd_pakg, conaddr);
						}
				}
				else              // ls -l dir  
				{
						if (chdir(file_name) < 0)
						{

							printf("chdir\n");
						}

						while(1)
						{
								pdirent = readdir(pdir);
								if (pdirent == NULL)
								{
										break;
								}
								if (*(pdirent->d_name) == '.')
								{
									continue;
								}
								ls_l(confd, pdirent->d_name, snd_pakg, conaddr);
								memset(&snd_pakg, 0, sizeof(snd_pakg));
						}

						if (chdir(file_buf) < 0)
						{

							printf("chdir\n");
						}
						snd_pakg.pakg_type = OVER;
                   	   if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
						{

								printf("sendto\n");
								closedir(pdir);
								return FALSE;  
						}
				}

	

}
static int ls_l(int confd, char* file_name, struct send_pakg snd_pakg, struct sockaddr_in conaddr)
{

		socklen_t len = sizeof(conaddr);
		struct stat file;
		char mode[12];
		bzero(mode,sizeof(mode));
		memset(&file, 0 , sizeof(file));
		if (lstat(file_name, &file) < 0)
		{
			printf("lstat\n");
			return TURE; 
		}
		if(S_ISREG(file.st_mode))
		{
				mode[0]='-';
		}
		else if(S_ISDIR(file.st_mode))
		{
				mode[0]='d';
		}
		else if(S_ISCHR(file.st_mode))
		{
				mode[0]='c';
		}
		else if(S_ISBLK(file.st_mode))
		{
				mode[0]='b';
		}
		else if(S_ISFIFO(file.st_mode))
		{
				mode[0]='p';
		}
		else if(S_ISLNK(file.st_mode))
		{
				mode[0]='l';
		}
		else if(S_ISSOCK(file.st_mode))
		{
				mode[0]='s';
		}
/*****************************************/
		int mode_num = 00;
				int i=0, j=1;
		for (i=9; i>0; i--, j++)
		{
			mode_num = (file.st_mode &(01<<i-1)) >>(i-1);
			if (mode_num==1)
			{
				if (i%3==0)
				{
					mode[j]='r';
				}
				else if (i%3==2)
				{
					mode[j]='w';
				}
				else if (i%3==1)
				{
					mode[j]='x';
				}

			}
			else if (mode_num == 0)
			{
				mode[j]='-';
			}
	}	
		sprintf(snd_pakg.data_buf.cmd_buf, "%s %3u  %3u  %3u %8d  %s",
						mode, file.st_nlink, \
						file.st_uid,         \
						file.st_gid, 	 	 \
						file.st_size, 	     \
						ctime(&file.st_mtime) \
						);
		snd_pakg.data_buf.cmd_buf[strlen(snd_pakg.data_buf.cmd_buf)-1] = ' ';
		snd_pakg.data_buf.cmd_buf[strlen(snd_pakg.data_buf.cmd_buf)] = '\0';

		strcat(snd_pakg.data_buf.cmd_buf, file_name);
		puts(snd_pakg.data_buf.cmd_buf);
		snd_pakg.pakg_type = LS;
			if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
			{
			printf("sendto\n");
			return FALSE;  
		}

		return TURE; 
}






