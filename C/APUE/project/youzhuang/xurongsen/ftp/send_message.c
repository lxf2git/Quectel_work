#include"aa.h"

int send_information( void *pdata,int socked)
{
	int ret;//判断返回的结果
	int len;//判断pdata读取的结果
	len = strlen(pdata);
	ret = write(socked,pdata,len);
	if(ret<0)
	{
			return FAILED;
	}
	return SUC;
}

int receive_information( void *pdata,int socked)
{
	int ret;//判断返回的结果
	int len=1024;//判断pdata读取的结果
//	len = strlen(pdata);
	ret = read(socked,pdata,len);
//	printf("read-->pdata:%s\n",pdata);
	if(ret<0)
	{
			return FAILED;
	}
	return SUC;
}
