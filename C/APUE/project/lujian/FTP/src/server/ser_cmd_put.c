
#include "../include/ftp.h"
#include "server.h"

int ser_cmd_put(int confd, struct cli_ser_pakg lv_cli_ser_pakg, struct sockaddr_in conaddr)
{

		static int fd; 
		struct send_pakg snd_pakg;
		memset(&snd_pakg, 0 , sizeof(snd_pakg));

		if (lv_cli_ser_pakg.cmd == PUT)
		{	
				char *p;
				p = strrchr(lv_cli_ser_pakg.argv.file_put, '/');
				if (p !=NULL)
				{
						fd = creat(p+1, 0666);
						if (fd < 0)
						{
								printf("creat err\n");
						}
				}
				else
				{
						fd = creat(lv_cli_ser_pakg.argv.file_put, 0666);
						if (fd < 0)
						{
								printf("creat err\n");
						}

				}
				return TURE; 
		}

		else if (lv_cli_ser_pakg.cmd == PUT_CONT)
		{
				int n;

				n = write(fd, lv_cli_ser_pakg.argv.file_put, \
								strlen(lv_cli_ser_pakg.argv.file_put));
				if (n <= 0)
				{

						printf("write\n");
				}
				return TURE; 
		}

		else if (lv_cli_ser_pakg.cmd == PUT_OVER)
		{
				snd_pakg.pakg_type = PUT_OVER; 
				strcpy(snd_pakg.data_buf.file_buf, "Transfer complete");
				if (sendto(confd, &snd_pakg, sizeof(snd_pakg),
										0, (struct sockaddr*)&conaddr, sizeof(conaddr)) <0)
				{

						printf("sendto \n");
				}
				close(fd);
				return TURE; 
		}

}	

