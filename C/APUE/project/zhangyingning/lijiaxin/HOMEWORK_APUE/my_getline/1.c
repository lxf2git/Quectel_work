// #define _GNU_SOURCE
//#include<stdio.h>
//#include<string.h>
#include"getline.h"
int main(int argc,char **argv)//命令行传参数
{
	char *pbuf=NULL;
	int len  = 0,ret=0;	
	FILE *fp = fopen(argv[1],"r+");	//以追加的方式打开文件
	if(NULL==fp)
	{
	//	perror("sleep");//错误信息输出
		perror("fopen");//标准出错提示
	}

	while(1)
	{
		ret = my_getline(&pbuf,&len,fp);//mygetline...
		printf("len:%d\n",len);
		//len = 0;
		if(ret==-1)
		{
			break;
		}
		fwrite(pbuf,strlen(pbuf),1,stdout);//stdin 标准输入(要求键盘输入)stdout(标准输出按屏幕) stderr();
		//pbuf=NULL;
		printf("****************\n");
	}
	
	fclose(fp);//关闭文件
	return 0;

}
