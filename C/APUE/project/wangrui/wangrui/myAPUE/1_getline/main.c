#include"mygetline.h"

int main(int argc,char *argv[])
{
	char *pbuf = NULL;
	int len = 30,ret = 0;
	FILE *fp = fopen(argv[1],"r+");
	if(fp == NULL)
	{
		perror("open");
	}
	pbuf = (char *)malloc(100);
	while(1)
	{
		ret = getline(&pbuf,&len,fp);
		printf("ret:%d len:%d\n",ret,len);
		if(ret == -1)
		{
			break;
		}
		fwrite(pbuf,ret,1,stdout);
	}
	fclose(fp);
	return 0;
}
