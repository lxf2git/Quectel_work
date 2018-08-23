
#include "../include/ftp.h"
#include "server.h"

int ser_cmd_cd(int confd, char* path, struct sockaddr_in conaddr);
int ser_cmd_quit(int confd, struct sockaddr_in conaddr);
int ser_cmd_pwd(int confd, struct sockaddr_in conaddr);
int ser_cmd_put(int confd, struct cli_ser_pakg lv_cli_ser_pakg, struct sockaddr_in conaddr);
int ser_cmd_mkdir(int confd, char* path_mkdir, struct sockaddr_in conaddr);
int ser_cmd_ls(int confd, char* file_name, struct sockaddr_in conaddr);
int ser_cmd_get(int confd, char* file_get, struct sockaddr_in conaddr);
int ser_cmd_cd(int confd, char* path, struct sockaddr_in conaddr);

int ser_deal_cmd(int confd, struct cli_ser_pakg lv_cli_ser_pakg, struct sockaddr_in conaddr)
{
		switch(lv_cli_ser_pakg.cmd)
		{
				case ERR:
						{

								printf("pakg is err\n");
								return FALSE;	
						}

				case 	LS:
						{
								ser_cmd_ls(confd, lv_cli_ser_pakg.argv.path_ls, conaddr);
										break;
						}

				case	PUT:
						{
								ser_cmd_put(confd, lv_cli_ser_pakg, conaddr);
								break;
						}
				case   PUT_CONT:
						{
								ser_cmd_put(confd, lv_cli_ser_pakg, conaddr);
								break;
						}
				case  PUT_OVER:
								{
										ser_cmd_put(confd, lv_cli_ser_pakg, conaddr);
										break;
								}

				case	GET:
						{
								ser_cmd_get(confd, lv_cli_ser_pakg.argv.file_get, conaddr);
								break;
						}

				case	CD:
						{
								ser_cmd_cd(confd, lv_cli_ser_pakg.argv.path_cd, conaddr);
								break;					
						}

				case	PWD:
						{
								ser_cmd_pwd(confd, conaddr);
								break;
						}
				case	MKDIR:
						{
								ser_cmd_mkdir(confd,lv_cli_ser_pakg.argv.path_mkdir, conaddr);
								break;
						}

				case	QUIT:
						{
								ser_cmd_quit(confd, conaddr);
								return QUIT; 
						}
				default:
						return FALSE;  
		}

		return TURE; 
}


