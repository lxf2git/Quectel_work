#include "../include/ftp.h"
#include "server.h"

int ser_cmd_quit(int confd, struct sockaddr_in conaddr)
{
	
	struct send_pakg snd_pakg;
	memset(&snd_pakg, 0, sizeof(snd_pakg));

	snd_pakg.pakg_type = QUIT;
	strcpy(snd_pakg.data_buf.cmd_buf, "Goodbye.");

	if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, \
						   	(struct sockaddr*)&conaddr, sizeof(conaddr)) <0)
	{
		printf("sendto fail\n");
	}

		return TURE; 
}
