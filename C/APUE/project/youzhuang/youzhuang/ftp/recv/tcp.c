#include"ftp.h"

int send_information(void *buf,int socked)
{
	int ret;//判断返回的结果
	ret = write(socked,buf,sizeof(struct cli_to_ser));
	if(ret<0)
	{
			return FAIL;
	}
	return SUC;
}

int receive_information( void *buf,int socked)
{
	int ret;//判断返回的结果
	ret = read(socked,buf,sizeof(struct cli_to_ser));
	if(ret<0)
	{
			return FAIL;
	}
	return SUC;
}
