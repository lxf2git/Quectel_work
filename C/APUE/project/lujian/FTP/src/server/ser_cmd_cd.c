

#include "../include/ftp.h"
#include "server.h"

int ser_cmd_cd(int confd, char* path, struct sockaddr_in conaddr)
{	
	struct send_pakg snd_pakg;
	memset(&snd_pakg, 0, sizeof(snd_pakg));
	socklen_t len = sizeof(conaddr);

	if (strcmp(path,"/root") == 0)
	{	
		snd_pakg.pakg_type = ERR;
		strcpy(snd_pakg.data_buf.cmd_buf, "Failed to change directory.");
		if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
		{
			printf("sendto\n");
			return FALSE;  
		}	

			return FALSE;  
	}
	else if (strlen(path) == 0)
	{
	
		snd_pakg.pakg_type = ERR;
		strcpy(snd_pakg.data_buf.cmd_buf, "(remote-directory)");
		if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
		{
			printf("sendto\n");
			return FALSE;  
		}	
	}
	else
	{	
			if (chdir(path) < 0)
			{	
					snd_pakg.pakg_type = ERR;
					strcpy(snd_pakg.data_buf.cmd_buf,  "Failed to change directory.");
					 if ((sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0))
					{
							printf("sendto\n");
							return FALSE;  
					}	
			}
			else
			{
					snd_pakg.pakg_type = CD;
					strcpy(snd_pakg.data_buf.cmd_buf,  "Directory successfully changed.");
					if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
					{

							printf("sendto\n");
							return TURE;   
					}	
					snd_pakg.pakg_type = OVER;
					if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, len) < 0)
					{
							printf("sendto\n");
							return TURE;   
					}	
			}

	
	}
	return TURE; 
}
