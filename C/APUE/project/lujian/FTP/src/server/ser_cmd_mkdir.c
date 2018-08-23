#include "../include/ftp.h"
#include "server.h"


int ser_cmd_mkdir(int confd,char* path_mkdir, struct sockaddr_in conaddr)
{

		struct send_pakg snd_pakg; 
		memset(&snd_pakg, 0, sizeof(snd_pakg));
		umask(0);
		if (mkdir(path_mkdir, 0755) == 0)
		{
				snd_pakg.pakg_type = MKDIR;
				sprintf(snd_pakg.data_buf.cmd_buf,"%s  created", path_mkdir);
				sendto(confd, &snd_pakg, sizeof(snd_pakg),0 , 
								(struct sockaddr*)&conaddr, sizeof(conaddr));
				if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0,
										(struct sockaddr*)&conaddr, sizeof(conaddr)) < 0)
				{

						printf("sendto\n"); 
				}
				snd_pakg.pakg_type = OVER;
				if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0,
										(struct sockaddr*)&conaddr, sizeof(conaddr)) < 0)
				{

						printf("sendto\n"); 
				}
				return TURE; 

		}
		else
		{
				snd_pakg.pakg_type = ERR;
				strcpy(snd_pakg.data_buf.cmd_buf, \
								"Create directory operation failed.");
				sendto(confd, &snd_pakg, sizeof(snd_pakg),  0, 
								(struct sockaddr*)&conaddr, sizeof(conaddr));
				return FALSE;  
		}

}

