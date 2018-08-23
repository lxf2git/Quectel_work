#include "../include/ftp.h"
#include  "server.h"


int ser_cmd_get(int confd,	char* file_get, struct sockaddr_in conaddr)
{
		struct send_pakg snd_pakg;
		memset(&snd_pakg, 0, sizeof(snd_pakg));

		int fd;
		if ((fd = open(file_get, O_RDONLY)) < 0)
		{
				snd_pakg.pakg_type =ERR;
				strcpy(snd_pakg.data_buf.file_buf, "No such file or director.");
				if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, \
										(struct sockaddr*)(&conaddr), sizeof(conaddr)))
				{

						printf("sendto err\n");

				}
				return FALSE;  
		}

		else
		{	
				int re;
				snd_pakg.pakg_type =GET;
				strcpy(snd_pakg.data_buf.file_buf, file_get);
				if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, 
										(struct sockaddr*)(&conaddr), sizeof(conaddr)) < 0)
				{

						printf("sendto err\n");
				}

				while(1)
				{
						re = read(fd, snd_pakg.data_buf.file_buf, 
										sizeof(snd_pakg.data_buf.file_buf) -3);
						if (re < 0)
						{

								printf("read err\n");
								break;
						}
						if (re == 0)
						{	
								snd_pakg.pakg_type =GET_OVER;
								strcpy(snd_pakg.data_buf.file_buf, "Tranlate complete");
								if (sendto(confd, &snd_pakg, sizeof(snd_pakg), 0, \
														(struct sockaddr*)(&conaddr), sizeof(conaddr)) < 0)
								{

										printf("sendto err\n");
								}
								break;
						}
						else
						{	
								snd_pakg.pakg_type = GET_CONT;
								if (sendto(confd, &snd_pakg,sizeof(snd_pakg), 0, \
														(struct sockaddr*)(&conaddr), sizeof(conaddr)) < 0)
								{

										printf("sendto err\n");
								}	   
						}
						bzero(snd_pakg.data_buf.file_buf, sizeof(snd_pakg.data_buf.file_buf));
				}
		}

		return TURE; 

}
