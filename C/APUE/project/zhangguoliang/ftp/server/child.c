#include"apue.h"
#include"ftp.h"
void child( struct recv_to_deal child)
{
		printf("child_deal:%d\n",child.to_ser.cmd);
		printf("%s\n",child.to_ser.ftp_ls_path);
	switch(child.to_ser.cmd)
	{
		case LS:
			my_ls(child);
			break;

		case PUT:
			my_put(child);
			break;

		case GET:
			my_get(child);
			break;
	
		case CD:
			my_cd(child);
			break;
	
		case PWD:
			my_pwd(child);
			break;
	
		case MKDIR:
			my_mkdir(child);
			break;
	
		case QUIT:
			my_quit();
			break;
	
		default :
			err();
			break;
	}
}
