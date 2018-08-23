#include "ftp.h"

int other_command_client(char *command,int sockfd)
{
		if(strncmp(command,"cd",2)==0)
		{
				char fileaddr[100];
				struct cli_to_ser data;
				data.cmd = CD;
				strcpy(fileaddr,command+3);
				strcpy(data.farg.ftp_cd_path,fileaddr);

				send_information(&data,sockfd);
		}
		if(strncmp(command,"mkdir",5)==0)
		{
				char filename[100];
				struct cli_to_ser data;
				data.cmd = MKDIR;
				strcpy(filename,command+6);
				strcpy(data.farg.ftp_mkdir_path,filename);

				send_information(&data,sockfd);
		}
		if(strncmp(command,"ls",2)==0)
		{
				char fileaddr[100];
				struct cli_to_ser data;
				data.cmd = LS;
				strcpy(fileaddr,command+3);
				strcpy(data.farg.ftp_ls_path,fileaddr);
				
				send_information(&data,sockfd);
				//jieshou
		}    
		if(strncmp(command,"pwd",3)==0)
		{
				char fileaddr[100];
				struct cli_to_ser data;
				data.cmd = PWD;
				strcpy(fileaddr,command+4);
				strcpy(data.farg.ftp_cmd_path,fileaddr);

				send_information(&data,sockfd);

				//jieshou
		}
		if(strncmp(command,"quit",4)==0)
		{
				struct cli_to_ser data;
				data.cmd = QUIT;
				strcpy(data.farg.ftp_ls_path,command);

				send_information(&data,sockfd);
				return FAIL;
		}	
		bzero(command,sizeof(command));

}
