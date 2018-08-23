#include "../include/ftp.h"
#include "server.h"

int ser_cmd_pwd(int confd, struct sockaddr_in conaddr)
{
		struct send_pakg snd_pakg;
		memset(&snd_pakg, 0 , sizeof(snd_pakg));

		if (getcwd(snd_pakg.data_buf.cmd_buf, sizeof(snd_pakg.data_buf.cmd_buf)) < 0)
		
		{
			
			printf("getcwd\n");
			return FALSE;  
		}

		else
		{
		 	snd_pakg.pakg_type = PWD;
			puts(snd_pakg.data_buf.cmd_buf);
			if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, sizeof(conaddr)) < 0)
			{

				printf("sendto\n");
				return FALSE;  
			}

		}
		 	snd_pakg.pakg_type = OVER;
			if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, (struct sockaddr*)&conaddr, sizeof(conaddr)) < 0)
			{

				printf("sendto\n");
				return FALSE;  
			}


		return TURE; 

}	
